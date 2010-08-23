/**
* Copyright (c) 2007-2009 Nokia Corporation and/or its subsidiary(-ies).
* All rights reserved.
* This component and the accompanying materials are made available
* under the terms of "Eclipse Public License v1.0"
* which accompanies this distribution, and is available
* at the URL "http://www.eclipse.org/legal/epl-v10.html".
*
* Initial Contributors:
* Nokia Corporation - initial contribution.
*
* Contributors:
*
* Description:
* Trace API
*
*/



/**
 @file
 @publishedPartner
 @prototype
*/


#ifndef OPENSYSTEMTRACE_TYPES_H
#define OPENSYSTEMTRACE_TYPES_H

#ifdef __KERNEL_MODE__
#include <kernel.h>
#else //__KERNEL_MODE__
#include <e32std.h>
#endif //__KERNEL_MODE__


/**
@file
@publishedPartner
@prototype
*/


/**
 * Every trace point must be statically assigned a group ID. This is
 * essentially a �label� that allows identification of the intended use of
 * the trace packets generated by the trace point. The Group ID will either 
 * reflect a system wide Tracing use cases, such as identifying why a panic 
 * occurred, or is assigned a meaning specific to a component, such as the 
 * heap trace output from the kernel. In essence the Group ID is a way of 
 * indicating that trace points / packets are related in some way. 
 * @see TGroupIdRange for more information.
 */
typedef TUint8  TGroupId;

/**
 * The maximum possible value for TGroupId
 */
const static TGroupId KMaxGroupId = 255; // 2^8 - 1

/**
 * @deprecated Use TGroupId instead
 * @see TGroupId
 */
typedef TUint8  TClassification;

/**
 * @deprecated Use KMaxGroupId instead
 * @see KMaxGroupId
 */
const static TClassification KMaxClassification = KMaxGroupId;

/**
 * Each trace point must be statically assigned a ComponentId to indicate the
 * module in which the trace point is defined. It should always be the UID3
 * of the binary containing the trace point associated with the component ID. 

 * The ComponentId and Group ID attributes of a trace point are independent.
 */
typedef TUint32 TComponentId;

/**
 * The maximum possible value for TComponentId
 */
const static TComponentId KMaxComponentId = 0xFFFFFFFF; // 2^32 - 1, or 4294967295 - 1

/**
 * The EXECUTABLE_DEFAULT_COMPONENTID can be used to define your own default
 * specific ComponentId. This is done by defining the macro to be your new
 * default value.
 */
#ifdef EXECUTABLE_DEFAULT_COMPONENTID
#define FW_DEFAULT_COMPONENTID EXECUTABLE_DEFAULT_COMPONENTID
#else
#define FW_DEFAULT_COMPONENTID TTraceContext::DefaultComponentId()
#endif

/**
 * Trace IDs have two functions in a trace packet:
 * 
 * 1. They identify the individual trace point that created the trace packet.
 * 2. They specify the format of the trace packet payload. 
 * 
 * This only works if the Trace ID value is unique for a given Group ID and 
 * Component ID, if present, and should be statically assigned during development 
 * when a trace point is created.  
 * 
 * The meaning of a TraceId is specific to the ComponentId and Group ID of the
 * associated trace point.
 */
typedef TUint16 TTraceId;

/**
 * The maximum possible value for TTraceId
 */
const static TTraceId KMaxTraceId = 65535; // 2^16 - 1

/**
 * Used in packets produced by the Print and Printf functions.
 *
 * Note that this format should not be used on the
 * device by clients of OST. This symbol is only marked
 * as published to partners to give host side tools access to
 * it.
 *
 * @deprecated No replacement is provided as this symbol is no 
 * longer needed as a result of the alignment of trace attributes 
 * in OSTv2.
 * @see TTraceId
 */
const static TTraceId KFormatPrintf = 0;

/**
 * Used in packets produced by the Print and Printf functions 
 * for unicode descriptors.
 *
 * Note that this format should not be used on the
 * device by clients of OST. This symbol is only marked
 * as published to partners to give host side tools access to
 * it.
 * 
 * @deprecated No replacement is provided as this symbol is no 
 * longer needed as a result of the alignment of trace attributes 
 * in OSTv2.
 * @see TTraceId
 */
const static TTraceId KFormatPrintfUnicode = 1;

/**
 * This value was used by UTFv2 clients to specify the start of 
 * the range of enums used to define their format ids. This is 
 * no longer necessary as in OSTv2 clients are allowed to use the
 * whole range without exception. 
 *
 * @deprecated No replacement is provided as this symbol is no 
 * longer needed as a result of the alignment of trace attributes 
 * in OSTv2.
 * @see TTraceId
 */
const static TTraceId KInitialClientFormat = 512;

/**
 * Include the thread identification into the trace packet at run-time.
 * The thread identification is used as an identifier to resolve
 * thread and process names in conjunction with
 * Group ID EThreadIdentification = 3.
 */
enum THasThreadIdentification
    {
    /** Do add the thread identification to the trace packet */
    EAddThreadIdentification = ETrue,
    /** Don't add the thread identification */
    ENoThreadIdentification = EFalse
    };


/**
 * The EXECUTABLE_DEFAULT_HAS_THREAD_IDENTIFICATION can be used to
 * define the default setting for adding or not adding the thread
 * identification in a trace packet. This is done by defining
 * the macro to be your new default value.
 */
#ifdef EXECUTABLE_DEFAULT_HAS_THREAD_IDENTIFICATION
#define FW_DEFAULT_HAS_THREAD_IDENTIFICATION EXECUTABLE_DEFAULT_HAS_THREAD_IDENTIFICATION
#else
#define FW_DEFAULT_HAS_THREAD_IDENTIFICATION EAddThreadIdentification
#endif


/**
 * Add the program counter into the trace packet at run-time.
 * The program counter is used to indicate where the CPU is in the
 * instruction sequence. This can be used to locate the line of code
 * or routine the trace was sent from.
 */
enum THasProgramCounter
    {
    /** Do add the program counter to the trace packet. */
    EAddProgramCounter = ETrue,
    /** Don't add the program counter */
    ENoProgramCounter = EFalse
    };


/**
 * The EXECUTABLE_DEFAULT_HAS_PC can be used to
 * define the default setting for adding or not adding the
 * program counter in a trace packet. This is done by defining
 * the macro to be your new default value.
 */
#ifdef EXECUTABLE_DEFAULT_HAS_PC
#define FW_DEFAULT_HAS_PC EXECUTABLE_DEFAULT_HAS_PC
#else
#define FW_DEFAULT_HAS_PC ENoProgramCounter
#endif

/**
 * The division of the Group IDs into different ranges aims to manage the
 * contention for the namespace.
 *
 * It is recommended that all developers use the Reserved range as far as possible.
 *
 * @see TGroupId
 */
enum TGroupIdRange
    {
    /**
     * The Group IDs in the Reserved range should be used by the majority of trace
     * points. This range of Group IDs are intended to identify which of the
     * most common trace use-cases a trace point is contributing to. They are unique
     * across the system.
     *
     * The Group IDs in this series are defined solely by the Symbian Foundation but are
     * intended for use by any software on a device.
     *
     * These Group IDs should only be enabled at run-time if the filtering on
     * ComponentIds functionality is also enabled. This is to avoid accidentally causing
     * trace live-locks from occurring when just the Group IDs is enabled. This could
     * happen because trace points in components involved in the current trace output
     * path might also be assigned these Group IDs. Filtering on ComponentIds means
     * that those trace points can be activated only when it�s known to be safe to do
     * so and not accidentally enabled with a Group IDs.
     *
     * @see TGroupIdReserved
     */
    EOstReservedRangeFirst = 0,

    /**
     * @see EOstReservedRangeFirst
     */
    EOstReservedRangeLast = 221,

    /**
     * The meaning of Group IDs in this range are defined on a per-component basis.
     * They are to be unique within a component.
     */
    EUserDefinedRangeFirst = 222,

    /**
     * @see EUserDefinedRangeFirst
     */
    EUserDefinedRangeLast = 253,
    
    /**
     * Only for use on the device by test code.
     *
     * Trace points with these Group IDs should not be released as part of a
     * production device.
     */
    ETestingRangeFirst = 154,

    /**
     * @see ETestingRangeFirst
     */
    ETestingRangeLast = KMaxGroupId
    };

/**
 * The Group IDs in the Reserved range should be used by the majority of
 * trace points. This range of Group IDs are intended to identify which
 * of the most common trace use-cases a trace point is contributing to.
 *
 * @see TGroupId
 * @see TGroupIdRange
 * @see EOstReservedRangeFirst
 */
enum TGroupIdReserved
    {
    /**
     * Used when a fatal error, such as a panic, has occurred or when providing information 
     * on the execution state immediately before the decision to panic.
     *
     * A trace point with this Group ID should be used when a fatal condition is detected 
     * which will result in the flow of execution being halted in the thread associated with 
     * the trace point.
     *
     * Can also provide information describing where a panic has been dealt with. 
     *
     * Trace points using this Group ID should be present in a release device. 
     */
    TRACE_FATAL = 149,

    /**
     * Used when an error has occurred which means that the current operation cannot continue 
     * but is not sufficiently serious to cause a fatal error. These trace packets should 
     * contain not just the error code but any relevant information about the execution state 
     * when the error occurred.
     *
     * To be used for all types of error including include situations where the errors are 
     * returned from a function or via a leave. 
     *
     * This Group ID also provides information describing where an error has been handled. 
     */
    TRACE_ERROR=150,

    /**
     * Used when something unexpected or unusual has occurred that does not stop the
     * current operation from happening but may result in unintended side effects or
     * actual errors later on.
     */
    TRACE_WARNING = 151,

    /**
     * Used to describe activity at the edges of a trace component. 
     *
     * Includes data about exported or published functions defined by a trace component as 
     * well as calls out of the component to get significant information. Exactly what 
     * is significant depends on the trace component in question. For instance, reading in a 
     * setting from an INI file would be significant but calling RArray::Count() would not be. 
     *
     * The information in this Group ID should be enough to allow someone unfamiliar with the 
     * trace component to get a high level understanding of what functionality it has executed.
     */
    TRACE_BORDER = 152,
    
    /**
    * @deprecated Use TRACE_BORDER instead
    */
    TRACE_API = TRACE_BORDER,
    
    /**
     * @deprecated Use TRACE_NORMAL or one of the other reserved Group IDs instead
     */
    TRACE_IMPORTANT = 153,
    
    /**
     * Used to described the normal activity within a trace component that might be of interest
     * to people who use the component.
     *
     * The information in this Group ID should be enough to allow someone unfamiliar with the 
     * trace component to start to understand why a component is behaving the way it is perhaps 
     * to help with diagnosing problems with the way the component is being used.
     */
    TRACE_NORMAL = 154,

    /**
     * Intended for tracing the state transitions of an application or service such as those
     * performed by a machine.
     *
     * Trace packets using this Group ID should contain the name of the
     * changed state variable and the new value.
     */
    TRACE_STATE  = 155,

    /**
     * Used to provide detailed information about the normal activity of a trace component
     * to help a developer, who is familiar with the component, to understand what it is doing.
     */
    TRACE_INTERNALS = 156,

    /**
    * @deprecated Use TRACE_INTERNALS instead
    */
    TRACE_DETAILED = TRACE_INTERNALS,
    
    /**
     * Used when there is a need to output large amounts of data through individual trace
     * points that would likely cause significant intrusion if included under one of the
     * other Group IDs.
     *
     * This Group ID is intended to be used in conjunction with the TRACE_INTERNALS
     * Group ID to provide more details when debugging a specific trace component.
     */
    TRACE_DUMP = 157,

    /**
    * @deprecated Use TRACE_DUMP instead
    */    
    TRACE_DEBUG = TRACE_DUMP,
    
    /**
     * Used to provide comprehensive information on what paths the execution takes within
     * functions.
     *
     * This Group ID is intended mainly to be used by tools that add temporary instrumentation 
     * points specifically to output this data.
     */
    TRACE_FLOW = 158,

    /**
     * Used to output data about the execution time, memory usage, disk usage, power
     * utilisation and any other performance characteristics of the associated trace 
     * component.
     *
     * This data may need to be processed before it can provide effective metrics. E.g.
     * the time between two timestamps might need to be computed.
     *
     * Intended only to be used to output a small amount of data to ensure that it 
     * creates the smallest possible intrusion since otherwise the act of tracing would 
     * devalue the information it is intended to provide.
     */
    TRACE_PERFORMANCE = 159,

    /**
     * May be used when adding temporary trace points during a debugging session to 
     * distinguish them from existing instrumentation. 
     */
    TRACE_ADHOC = 160,
    
    /**
     * This Group ID is reserved for future use to allow the Group ID range to be expanded 
     * to cover more than current 256 different values.
     *
     * If trace is output on this Group ID at some point in the future then this indicates 
     * that another mechanism (yet to be decided) will be used to indicate the actual 
     * Group ID for the trace.
     */
    TRACE_EXTENSION = 161,

    /**
	 * Not intended to be used by code including this header.
	 * 
     * Provided to allow the following compile time assert (should NOT be used):
     * EGroupIdReservedHighWaterMark <= EOstReservedRangeLast + 1
     *
     */
    EGroupIdReservedHighWaterMark
    } ;

// Check high water mark for the reserved Group ID range
__ASSERT_COMPILE(EGroupIdReservedHighWaterMark <= EOstReservedRangeLast + 1);

/**
 * @see TGroupId
 * @see ETestingRangeFirst
 * @test
 */
enum TGroupIdTesting
    {
    /**
     * This Group ID may be used for testing purposes and is not intended to be used in 
     * production code. 
     */
    TRACE_TESTING1 = ETestingRangeFirst,

    /**
     * The same as for TRACE_TESTING1
     */
    TRACE_TESTING2 = 155,

    /**
	 * Not intended to be used by code including this header.
	 * 
     * Provided to allow the following compile time assert (should NOT be used):
     * EGroupIdTestingHighWaterMark <= ETestingRangeLast + 1
     *
     */
    EGroupIdTestingHighWaterMark
    };

// Check high water marks for the testing Group ID range
__ASSERT_COMPILE(EGroupIdTestingHighWaterMark <= ETestingRangeLast + 1);

/**
 * @deprecated Use enumerations from TGroupIdReserved instead
 * @see TGroupId
 * @see TGroupIdRange
 * @see EOstReservedRangeFirst
 */
enum TClassificationAll
    {
    EPanic = TRACE_FATAL,
    EError = TRACE_ERROR,
    EWarning = TRACE_WARNING,
    EBorder = TRACE_BORDER,
    EState = TRACE_STATE,
    EInternals = TRACE_INTERNALS,
    EDump = TRACE_DUMP,
    EFlow = TRACE_FLOW,
    ESystemCharacteristicMetrics = TRACE_PERFORMANCE,
    EAdhoc = TRACE_ADHOC,
    EClassificationAllHighWaterMark
    };

// Check high water mark for the 'All' classification range
__ASSERT_COMPILE(EClassificationAllHighWaterMark <= EOstReservedRangeLast + 1);

/**
 * @deprecated Use enumerations from TGroupIdReserved instead
 * @see TGroupId
 * @see TGroupIdRange
 * @see EOstReservedRangeFirst
 */
enum TClassificationSymbianTwo
	{
	EClassificationExtension = TRACE_EXTENSION,
	EClassificationSymbianTwoHighWaterMark
	};

// Check high water marks for the Symbian Two classification range
__ASSERT_COMPILE(EClassificationSymbianTwoHighWaterMark <= EOstReservedRangeLast + 1);

/**
 * @deprecated Use enumerations from TGroupIdTesting instead
 * @see TGroupId
 * @see TGroupIdRange
 * @see ETestingRangeFirst
 * @test
 */
enum TClassificationTesting
	{
	ETesting1 = TRACE_TESTING1,
	ETesting2 = TRACE_TESTING2,
	EClassificationTestingHighWaterMark,
	};

// Check high water marks for classification ranges
__ASSERT_COMPILE(EClassificationTestingHighWaterMark <= ETestingRangeLast + 1);


#endif //OPENSYSTEMTRACE_TYPES_H

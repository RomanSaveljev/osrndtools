// Created by TraceCompiler 2.1.2
// DO NOT EDIT, CHANGES WILL BE LOST

#ifndef __HELLOWORLD_E9FBE6EE_TRACEDEFINITIONS_H__
#define __HELLOWORLD_E9FBE6EE_TRACEDEFINITIONS_H__

#define AUTOGEN_TRACES_HAVE_FIXED_IDS
#include <isi_macros.h>

#undef HELLOWORLD_COMPONENT
#define HELLOWORLD_COMPONENT 0xe9fbe6ee
#undef UNICODE_STRING_TEST
#define UNICODE_STRING_TEST 0xde
#undef TRACE0
#define TRACE0 0x1
#undef TRACE1
#define TRACE1 0x2
#undef TRACE2
#define TRACE2 0x3
#undef TRACE3
#define TRACE3 0x4
#undef TRACE4
#define TRACE4 0x5
#undef TRACE5
#define TRACE5 0x6
#undef TRACE7
#define TRACE7 0x7
#undef TRACE8
#define TRACE8 0x8
#undef TRACE9
#define TRACE9 0x9
#undef TRACE10
#define TRACE10 0xa
#undef TRACE11
#define TRACE11 0xb
#undef TRACE12
#define TRACE12 0xc
#undef TRACE13
#define TRACE13 0xd
#undef TRACE14
#define TRACE14 0xe
#undef TRACE15
#define TRACE15 0xf
#undef TRACE16
#define TRACE16 0x10
#undef TRACE17
#define TRACE17 0x11
#undef TRACE18
#define TRACE18 0x12
#undef TRACE19
#define TRACE19 0x13
#undef TRACE20
#define TRACE20 0x14
#undef TRACE21
#define TRACE21 0x15
#undef TRACE22
#define TRACE22 0x16
#undef TRACE23
#define TRACE23 0x17
#undef TRACE24
#define TRACE24 0x18
#undef TRACE25
#define TRACE25 0x19
#undef TRACE26
#define TRACE26 0x1a
#undef TRACE27
#define TRACE27 0x1b
#undef TRACE28
#define TRACE28 0x1c
#undef TRACE29
#define TRACE29 0x1d
#undef TRACE30
#define TRACE30 0x1e
#undef TRACE31
#define TRACE31 0x1f
#undef TRACE32
#define TRACE32 0x20
#undef TRACE33
#define TRACE33 0x21
#undef TRACE34
#define TRACE34 0x22
#undef TRACE35
#define TRACE35 0x23
#undef TRACE36
#define TRACE36 0x24

RES_BEGIN( RESOURCE_TRC_SYMBIAN, HELLOWORLD_COMPONENT, HELLOWORLD_TRACE, "HELLOWORLD", "", FALSE )
	
	#include <SharedTraceDefinitions.h>
	
	TRACE_GROUP_BEGIN( UNICODE_STRING_TEST, "HelloWorld: UNICODE_STRING_TEST: ", ON )
		
		TRACE_BEGIN( TRACE0, "Test different kind of unicode strings." )
			AUTOGEN_BTRACE_HEADER_MAPPED
		TRACE_END()
		
		TRACE_BEGIN( TRACE1, "ascii(5):  ascii(4):" )
			AUTOGEN_BTRACE_HEADER_MAPPED
			PROPERTY( PROPERTY_PMD_IS_NOT_PARAMETER )
			REFERENCE( 32, SYMBIAN_ENDIANESS, STR08len, "STR08_len", STR08_lenref )
			PROPERTY( PROPERTY_PMD_PARAMETER )
			STRING_REF( STRING_ASCII, BE, STR08, "STR08", STR08_lenref, ISIHDR_DONT_GENERATE )
			FILLER( FILLER_VARIABLE, 32 )
			PROPERTY( PROPERTY_PMD_IS_NOT_PARAMETER )
			REFERENCE( 32, SYMBIAN_ENDIANESS, STR8len, "STR8_len", STR8_lenref )
			PROPERTY( PROPERTY_PMD_PARAMETER )
			STRING_REF( STRING_ASCII, BE, STR8, "STR8", STR8_lenref, ISIHDR_DONT_GENERATE )
			FILLER( FILLER_VARIABLE, 32 )
		TRACE_END()
		
		TRACE_BEGIN( TRACE2, "unicode(5):  unicode(5):" )
			AUTOGEN_BTRACE_HEADER_MAPPED
			PROPERTY( PROPERTY_PMD_IS_NOT_PARAMETER )
			REFERENCE( 32, SYMBIAN_ENDIANESS, STR16len, "STR16_len", STR16_lenref )
			PROPERTY( PROPERTY_PMD_PARAMETER )
			STRING_REF( STRING_UNICODE, SYMBIAN_ENDIANESS, STR16, "STR16", STR16_lenref, ISIHDR_DONT_GENERATE )
			FILLER( FILLER_VARIABLE, 32 )
			PROPERTY( PROPERTY_PMD_IS_NOT_PARAMETER )
			REFERENCE( 32, SYMBIAN_ENDIANESS, STR162len, "STR162_len", STR162_lenref )
			PROPERTY( PROPERTY_PMD_PARAMETER )
			STRING_REF( STRING_UNICODE, SYMBIAN_ENDIANESS, STR162, "STR162", STR162_lenref, ISIHDR_DONT_GENERATE )
			FILLER( FILLER_VARIABLE, 32 )
		TRACE_END()
		
		TRACE_BEGIN( TRACE3, "ascii(4):  unicode(5):" )
			AUTOGEN_BTRACE_HEADER_MAPPED
			PROPERTY( PROPERTY_PMD_IS_NOT_PARAMETER )
			REFERENCE( 32, SYMBIAN_ENDIANESS, STR8len, "STR8_len", STR8_lenref )
			PROPERTY( PROPERTY_PMD_PARAMETER )
			STRING_REF( STRING_ASCII, BE, STR8, "STR8", STR8_lenref, ISIHDR_DONT_GENERATE )
			FILLER( FILLER_VARIABLE, 32 )
			PROPERTY( PROPERTY_PMD_IS_NOT_PARAMETER )
			REFERENCE( 32, SYMBIAN_ENDIANESS, STR16len, "STR16_len", STR16_lenref )
			PROPERTY( PROPERTY_PMD_PARAMETER )
			STRING_REF( STRING_UNICODE, SYMBIAN_ENDIANESS, STR16, "STR16", STR16_lenref, ISIHDR_DONT_GENERATE )
			FILLER( FILLER_VARIABLE, 32 )
		TRACE_END()
		
		TRACE_BEGIN( TRACE4, "unicode(5):  ascii (5):" )
			AUTOGEN_BTRACE_HEADER_MAPPED
			PROPERTY( PROPERTY_PMD_IS_NOT_PARAMETER )
			REFERENCE( 32, SYMBIAN_ENDIANESS, STR16len, "STR16_len", STR16_lenref )
			PROPERTY( PROPERTY_PMD_PARAMETER )
			STRING_REF( STRING_UNICODE, SYMBIAN_ENDIANESS, STR16, "STR16", STR16_lenref, ISIHDR_DONT_GENERATE )
			FILLER( FILLER_VARIABLE, 32 )
			PROPERTY( PROPERTY_PMD_IS_NOT_PARAMETER )
			REFERENCE( 32, SYMBIAN_ENDIANESS, STR08len, "STR08_len", STR08_lenref )
			PROPERTY( PROPERTY_PMD_PARAMETER )
			STRING_REF( STRING_ASCII, BE, STR08, "STR08", STR08_lenref, ISIHDR_DONT_GENERATE )
			FILLER( FILLER_VARIABLE, 32 )
		TRACE_END()
		
		TRACE_BEGIN( TRACE5, "ascii(5):" )
			AUTOGEN_BTRACE_HEADER_MAPPED
			PROPERTY( PROPERTY_PMD_PARAMETER )
			STRING_REF( STRING_ASCII_ZERO_TERMINATED, BE, STR08, "STR08", REF_LENGTH_DETERMINED_BY_ZERO, ISIHDR_DONT_GENERATE )
		TRACE_END()
		
		TRACE_BEGIN( TRACE7, "unicode(5):" )
			AUTOGEN_BTRACE_HEADER_MAPPED
			PROPERTY( PROPERTY_PMD_PARAMETER )
			STRING_REF( STRING_UNICODE_ZERO_TERMINATED, SYMBIAN_ENDIANESS, STR16, "STR16", REF_LENGTH_DETERMINED_BY_ZERO, ISIHDR_DONT_GENERATE )
		TRACE_END()
		
		TRACE_BEGIN( TRACE8, "ascii(1):" )
			AUTOGEN_BTRACE_HEADER_MAPPED
			PROPERTY( PROPERTY_PMD_PARAMETER )
			STRING_REF( STRING_ASCII_ZERO_TERMINATED, BE, arg1, "arg1", REF_LENGTH_DETERMINED_BY_ZERO, ISIHDR_DONT_GENERATE )
		TRACE_END()
		
		TRACE_BEGIN( TRACE9, "unicode(1):" )
			AUTOGEN_BTRACE_HEADER_MAPPED
			PROPERTY( PROPERTY_PMD_PARAMETER )
			STRING_REF( STRING_UNICODE_ZERO_TERMINATED, SYMBIAN_ENDIANESS, arg1, "arg1", REF_LENGTH_DETERMINED_BY_ZERO, ISIHDR_DONT_GENERATE )
		TRACE_END()
		
		TRACE_BEGIN( TRACE10, "ascii(4):" )
			AUTOGEN_BTRACE_HEADER_MAPPED
			PROPERTY( PROPERTY_PMD_PARAMETER )
			STRING_REF( STRING_ASCII_ZERO_TERMINATED, BE, STR8, "STR8", REF_LENGTH_DETERMINED_BY_ZERO, ISIHDR_DONT_GENERATE )
		TRACE_END()
		
		TRACE_BEGIN( TRACE11, "unicode(4):" )
			AUTOGEN_BTRACE_HEADER_MAPPED
			PROPERTY( PROPERTY_PMD_PARAMETER )
			STRING_REF( STRING_UNICODE_ZERO_TERMINATED, SYMBIAN_ENDIANESS, ST16, "ST16", REF_LENGTH_DETERMINED_BY_ZERO, ISIHDR_DONT_GENERATE )
		TRACE_END()
		
		TRACE_BEGIN( TRACE12, "ascii(6):  unicode (8):" )
			AUTOGEN_BTRACE_HEADER_MAPPED
			PROPERTY( PROPERTY_PMD_IS_NOT_PARAMETER )
			REFERENCE( 32, SYMBIAN_ENDIANESS, STR008len, "STR008_len", STR008_lenref )
			PROPERTY( PROPERTY_PMD_PARAMETER )
			STRING_REF( STRING_ASCII, BE, STR008, "STR008", STR008_lenref, ISIHDR_DONT_GENERATE )
			FILLER( FILLER_VARIABLE, 32 )
			PROPERTY( PROPERTY_PMD_IS_NOT_PARAMETER )
			REFERENCE( 32, SYMBIAN_ENDIANESS, STR00016len, "STR00016_len", STR00016_lenref )
			PROPERTY( PROPERTY_PMD_PARAMETER )
			STRING_REF( STRING_UNICODE, SYMBIAN_ENDIANESS, STR00016, "STR00016", STR00016_lenref, ISIHDR_DONT_GENERATE )
			FILLER( FILLER_VARIABLE, 32 )
		TRACE_END()
		
		TRACE_BEGIN( TRACE13, "unicode(4):  ascii(8):" )
			AUTOGEN_BTRACE_HEADER_MAPPED
			PROPERTY( PROPERTY_PMD_IS_NOT_PARAMETER )
			REFERENCE( 32, SYMBIAN_ENDIANESS, ST16len, "ST16_len", ST16_lenref )
			PROPERTY( PROPERTY_PMD_PARAMETER )
			STRING_REF( STRING_UNICODE, SYMBIAN_ENDIANESS, ST16, "ST16", ST16_lenref, ISIHDR_DONT_GENERATE )
			FILLER( FILLER_VARIABLE, 32 )
			PROPERTY( PROPERTY_PMD_IS_NOT_PARAMETER )
			REFERENCE( 32, SYMBIAN_ENDIANESS, STR00008len, "STR00008_len", STR00008_lenref )
			PROPERTY( PROPERTY_PMD_PARAMETER )
			STRING_REF( STRING_ASCII, BE, STR00008, "STR00008", STR00008_lenref, ISIHDR_DONT_GENERATE )
			FILLER( FILLER_VARIABLE, 32 )
		TRACE_END()
		
		TRACE_BEGIN( TRACE14, "unicode(4):  ascii(8):  int:" )
			AUTOGEN_BTRACE_HEADER_MAPPED
			PROPERTY( PROPERTY_PMD_IS_NOT_PARAMETER )
			REFERENCE( 32, SYMBIAN_ENDIANESS, ST16len, "ST16_len", ST16_lenref )
			PROPERTY( PROPERTY_PMD_PARAMETER )
			STRING_REF( STRING_UNICODE, SYMBIAN_ENDIANESS, ST16, "ST16", ST16_lenref, ISIHDR_DONT_GENERATE )
			FILLER( FILLER_VARIABLE, 32 )
			PROPERTY( PROPERTY_PMD_IS_NOT_PARAMETER )
			REFERENCE( 32, SYMBIAN_ENDIANESS, STR00008len, "STR00008_len", STR00008_lenref )
			PROPERTY( PROPERTY_PMD_PARAMETER )
			STRING_REF( STRING_ASCII, BE, STR00008, "STR00008", STR00008_lenref, ISIHDR_DONT_GENERATE )
			FILLER( FILLER_VARIABLE, 32 )
			PROPERTY( PROPERTY_PMD_PARAMETER )
			VALUE( -32, SYMBIAN_ENDIANESS, arg3, "arg3", DEC )
		TRACE_END()
		
		TRACE_BEGIN( TRACE15, "unicode(4):  ascii(0):  int:" )
			AUTOGEN_BTRACE_HEADER_MAPPED
			PROPERTY( PROPERTY_PMD_IS_NOT_PARAMETER )
			REFERENCE( 32, SYMBIAN_ENDIANESS, ST16len, "ST16_len", ST16_lenref )
			PROPERTY( PROPERTY_PMD_PARAMETER )
			STRING_REF( STRING_UNICODE, SYMBIAN_ENDIANESS, ST16, "ST16", ST16_lenref, ISIHDR_DONT_GENERATE )
			FILLER( FILLER_VARIABLE, 32 )
			PROPERTY( PROPERTY_PMD_IS_NOT_PARAMETER )
			REFERENCE( 32, SYMBIAN_ENDIANESS, arg2len, "arg2_len", arg2_lenref )
			PROPERTY( PROPERTY_PMD_PARAMETER )
			STRING_REF( STRING_ASCII, BE, arg2, "arg2", arg2_lenref, ISIHDR_DONT_GENERATE )
			FILLER( FILLER_VARIABLE, 32 )
			PROPERTY( PROPERTY_PMD_PARAMETER )
			VALUE( -32, SYMBIAN_ENDIANESS, arg3, "arg3", DEC )
		TRACE_END()
		
		TRACE_BEGIN( TRACE16, "unicode(60):" )
			AUTOGEN_BTRACE_HEADER_MAPPED
			PROPERTY( PROPERTY_PMD_PARAMETER )
			STRING_REF( STRING_UNICODE_ZERO_TERMINATED, SYMBIAN_ENDIANESS, buf60, "buf60", REF_LENGTH_DETERMINED_BY_ZERO, ISIHDR_DONT_GENERATE )
		TRACE_END()
		
		TRACE_BEGIN( TRACE17, "unicode(333):" )
			AUTOGEN_BTRACE_HEADER_MAPPED
			PROPERTY( PROPERTY_PMD_PARAMETER )
			STRING_REF( STRING_UNICODE_ZERO_TERMINATED, SYMBIAN_ENDIANESS, buf333, "buf333", REF_LENGTH_DETERMINED_BY_ZERO, ISIHDR_DONT_GENERATE )
		TRACE_END()
		
		TRACE_BEGIN( TRACE18, "unicode(600):" )
			AUTOGEN_BTRACE_HEADER_MAPPED
			PROPERTY( PROPERTY_PMD_PARAMETER )
			STRING_REF( STRING_UNICODE_ZERO_TERMINATED, SYMBIAN_ENDIANESS, buf600, "buf600", REF_LENGTH_DETERMINED_BY_ZERO, ISIHDR_DONT_GENERATE )
		TRACE_END()
		
		TRACE_BEGIN( TRACE19, "unicode(5):  ascii(0):" )
			AUTOGEN_BTRACE_HEADER_MAPPED
			PROPERTY( PROPERTY_PMD_IS_NOT_PARAMETER )
			REFERENCE( 32, SYMBIAN_ENDIANESS, STR16len, "STR16_len", STR16_lenref )
			PROPERTY( PROPERTY_PMD_PARAMETER )
			STRING_REF( STRING_UNICODE, SYMBIAN_ENDIANESS, STR16, "STR16", STR16_lenref, ISIHDR_DONT_GENERATE )
			FILLER( FILLER_VARIABLE, 32 )
			PROPERTY( PROPERTY_PMD_IS_NOT_PARAMETER )
			REFERENCE( 32, SYMBIAN_ENDIANESS, arg2len, "arg2_len", arg2_lenref )
			PROPERTY( PROPERTY_PMD_PARAMETER )
			STRING_REF( STRING_ASCII, BE, arg2, "arg2", arg2_lenref, ISIHDR_DONT_GENERATE )
			FILLER( FILLER_VARIABLE, 32 )
		TRACE_END()
		
		TRACE_BEGIN( TRACE20, "unicode(0):  ascii(5):" )
			AUTOGEN_BTRACE_HEADER_MAPPED
			PROPERTY( PROPERTY_PMD_IS_NOT_PARAMETER )
			REFERENCE( 32, SYMBIAN_ENDIANESS, arg1len, "arg1_len", arg1_lenref )
			PROPERTY( PROPERTY_PMD_PARAMETER )
			STRING_REF( STRING_UNICODE, SYMBIAN_ENDIANESS, arg1, "arg1", arg1_lenref, ISIHDR_DONT_GENERATE )
			FILLER( FILLER_VARIABLE, 32 )
			PROPERTY( PROPERTY_PMD_IS_NOT_PARAMETER )
			REFERENCE( 32, SYMBIAN_ENDIANESS, STR08len, "STR08_len", STR08_lenref )
			PROPERTY( PROPERTY_PMD_PARAMETER )
			STRING_REF( STRING_ASCII, BE, STR08, "STR08", STR08_lenref, ISIHDR_DONT_GENERATE )
			FILLER( FILLER_VARIABLE, 32 )
		TRACE_END()
		
		TRACE_BEGIN( TRACE21, "ascii(0):" )
			AUTOGEN_BTRACE_HEADER_MAPPED
			PROPERTY( PROPERTY_PMD_PARAMETER )
			STRING_REF( STRING_ASCII_ZERO_TERMINATED, BE, arg1, "arg1", REF_LENGTH_DETERMINED_BY_ZERO, ISIHDR_DONT_GENERATE )
		TRACE_END()
		
		TRACE_BEGIN( TRACE22, "unicode(0):" )
			AUTOGEN_BTRACE_HEADER_MAPPED
			PROPERTY( PROPERTY_PMD_PARAMETER )
			STRING_REF( STRING_UNICODE_ZERO_TERMINATED, SYMBIAN_ENDIANESS, arg1, "arg1", REF_LENGTH_DETERMINED_BY_ZERO, ISIHDR_DONT_GENERATE )
		TRACE_END()
		
		TRACE_BEGIN( TRACE23, "ascii(4):  unicode(0):" )
			AUTOGEN_BTRACE_HEADER_MAPPED
			PROPERTY( PROPERTY_PMD_IS_NOT_PARAMETER )
			REFERENCE( 32, SYMBIAN_ENDIANESS, STR8len, "STR8_len", STR8_lenref )
			PROPERTY( PROPERTY_PMD_PARAMETER )
			STRING_REF( STRING_ASCII, BE, STR8, "STR8", STR8_lenref, ISIHDR_DONT_GENERATE )
			FILLER( FILLER_VARIABLE, 32 )
			PROPERTY( PROPERTY_PMD_IS_NOT_PARAMETER )
			REFERENCE( 32, SYMBIAN_ENDIANESS, arg2len, "arg2_len", arg2_lenref )
			PROPERTY( PROPERTY_PMD_PARAMETER )
			STRING_REF( STRING_UNICODE, SYMBIAN_ENDIANESS, arg2, "arg2", arg2_lenref, ISIHDR_DONT_GENERATE )
			FILLER( FILLER_VARIABLE, 32 )
		TRACE_END()
		
		TRACE_BEGIN( TRACE24, "ascii(0):  unicode(5):" )
			AUTOGEN_BTRACE_HEADER_MAPPED
			PROPERTY( PROPERTY_PMD_IS_NOT_PARAMETER )
			REFERENCE( 32, SYMBIAN_ENDIANESS, arg1len, "arg1_len", arg1_lenref )
			PROPERTY( PROPERTY_PMD_PARAMETER )
			STRING_REF( STRING_ASCII, BE, arg1, "arg1", arg1_lenref, ISIHDR_DONT_GENERATE )
			FILLER( FILLER_VARIABLE, 32 )
			PROPERTY( PROPERTY_PMD_IS_NOT_PARAMETER )
			REFERENCE( 32, SYMBIAN_ENDIANESS, STR16len, "STR16_len", STR16_lenref )
			PROPERTY( PROPERTY_PMD_PARAMETER )
			STRING_REF( STRING_UNICODE, SYMBIAN_ENDIANESS, STR16, "STR16", STR16_lenref, ISIHDR_DONT_GENERATE )
			FILLER( FILLER_VARIABLE, 32 )
		TRACE_END()
		
		TRACE_BEGIN( TRACE25, "ascii(5):  ascii(0):" )
			AUTOGEN_BTRACE_HEADER_MAPPED
			PROPERTY( PROPERTY_PMD_IS_NOT_PARAMETER )
			REFERENCE( 32, SYMBIAN_ENDIANESS, STR08len, "STR08_len", STR08_lenref )
			PROPERTY( PROPERTY_PMD_PARAMETER )
			STRING_REF( STRING_ASCII, BE, STR08, "STR08", STR08_lenref, ISIHDR_DONT_GENERATE )
			FILLER( FILLER_VARIABLE, 32 )
			PROPERTY( PROPERTY_PMD_IS_NOT_PARAMETER )
			REFERENCE( 32, SYMBIAN_ENDIANESS, arg2len, "arg2_len", arg2_lenref )
			PROPERTY( PROPERTY_PMD_PARAMETER )
			STRING_REF( STRING_ASCII, BE, arg2, "arg2", arg2_lenref, ISIHDR_DONT_GENERATE )
			FILLER( FILLER_VARIABLE, 32 )
		TRACE_END()
		
		TRACE_BEGIN( TRACE26, "unicode(5):  unicode(0):" )
			AUTOGEN_BTRACE_HEADER_MAPPED
			PROPERTY( PROPERTY_PMD_IS_NOT_PARAMETER )
			REFERENCE( 32, SYMBIAN_ENDIANESS, STR16len, "STR16_len", STR16_lenref )
			PROPERTY( PROPERTY_PMD_PARAMETER )
			STRING_REF( STRING_UNICODE, SYMBIAN_ENDIANESS, STR16, "STR16", STR16_lenref, ISIHDR_DONT_GENERATE )
			FILLER( FILLER_VARIABLE, 32 )
			PROPERTY( PROPERTY_PMD_IS_NOT_PARAMETER )
			REFERENCE( 32, SYMBIAN_ENDIANESS, arg2len, "arg2_len", arg2_lenref )
			PROPERTY( PROPERTY_PMD_PARAMETER )
			STRING_REF( STRING_UNICODE, SYMBIAN_ENDIANESS, arg2, "arg2", arg2_lenref, ISIHDR_DONT_GENERATE )
			FILLER( FILLER_VARIABLE, 32 )
		TRACE_END()
		
		TRACE_BEGIN( TRACE27, "ascii(0):  ascii(4):" )
			AUTOGEN_BTRACE_HEADER_MAPPED
			PROPERTY( PROPERTY_PMD_IS_NOT_PARAMETER )
			REFERENCE( 32, SYMBIAN_ENDIANESS, arg1len, "arg1_len", arg1_lenref )
			PROPERTY( PROPERTY_PMD_PARAMETER )
			STRING_REF( STRING_ASCII, BE, arg1, "arg1", arg1_lenref, ISIHDR_DONT_GENERATE )
			FILLER( FILLER_VARIABLE, 32 )
			PROPERTY( PROPERTY_PMD_IS_NOT_PARAMETER )
			REFERENCE( 32, SYMBIAN_ENDIANESS, STR8len, "STR8_len", STR8_lenref )
			PROPERTY( PROPERTY_PMD_PARAMETER )
			STRING_REF( STRING_ASCII, BE, STR8, "STR8", STR8_lenref, ISIHDR_DONT_GENERATE )
			FILLER( FILLER_VARIABLE, 32 )
		TRACE_END()
		
		TRACE_BEGIN( TRACE28, "unicode(0):  unicode(5):" )
			AUTOGEN_BTRACE_HEADER_MAPPED
			PROPERTY( PROPERTY_PMD_IS_NOT_PARAMETER )
			REFERENCE( 32, SYMBIAN_ENDIANESS, arg1len, "arg1_len", arg1_lenref )
			PROPERTY( PROPERTY_PMD_PARAMETER )
			STRING_REF( STRING_UNICODE, SYMBIAN_ENDIANESS, arg1, "arg1", arg1_lenref, ISIHDR_DONT_GENERATE )
			FILLER( FILLER_VARIABLE, 32 )
			PROPERTY( PROPERTY_PMD_IS_NOT_PARAMETER )
			REFERENCE( 32, SYMBIAN_ENDIANESS, STR16len, "STR16_len", STR16_lenref )
			PROPERTY( PROPERTY_PMD_PARAMETER )
			STRING_REF( STRING_UNICODE, SYMBIAN_ENDIANESS, STR16, "STR16", STR16_lenref, ISIHDR_DONT_GENERATE )
			FILLER( FILLER_VARIABLE, 32 )
		TRACE_END()
		
		TRACE_BEGIN( TRACE29, "unicode(333):  ascii(0):  int:" )
			AUTOGEN_BTRACE_HEADER_MAPPED
			PROPERTY( PROPERTY_PMD_IS_NOT_PARAMETER )
			REFERENCE( 32, SYMBIAN_ENDIANESS, buf333len, "buf333_len", buf333_lenref )
			PROPERTY( PROPERTY_PMD_PARAMETER )
			STRING_REF( STRING_UNICODE, SYMBIAN_ENDIANESS, buf333, "buf333", buf333_lenref, ISIHDR_DONT_GENERATE )
			FILLER( FILLER_VARIABLE, 32 )
			PROPERTY( PROPERTY_PMD_IS_NOT_PARAMETER )
			REFERENCE( 32, SYMBIAN_ENDIANESS, arg2len, "arg2_len", arg2_lenref )
			PROPERTY( PROPERTY_PMD_PARAMETER )
			STRING_REF( STRING_ASCII, BE, arg2, "arg2", arg2_lenref, ISIHDR_DONT_GENERATE )
			FILLER( FILLER_VARIABLE, 32 )
			PROPERTY( PROPERTY_PMD_PARAMETER )
			VALUE( -32, SYMBIAN_ENDIANESS, arg3, "arg3", DEC )
		TRACE_END()
		
		TRACE_BEGIN( TRACE30, "unicode(333):  unicode(333):" )
			AUTOGEN_BTRACE_HEADER_MAPPED
			PROPERTY( PROPERTY_PMD_IS_NOT_PARAMETER )
			REFERENCE( 32, SYMBIAN_ENDIANESS, buf333len, "buf333_len", buf333_lenref )
			PROPERTY( PROPERTY_PMD_PARAMETER )
			STRING_REF( STRING_UNICODE, SYMBIAN_ENDIANESS, buf333, "buf333", buf333_lenref, ISIHDR_DONT_GENERATE )
			FILLER( FILLER_VARIABLE, 32 )
			PROPERTY( PROPERTY_PMD_IS_NOT_PARAMETER )
			REFERENCE( 32, SYMBIAN_ENDIANESS, buf3332len, "buf3332_len", buf3332_lenref )
			PROPERTY( PROPERTY_PMD_PARAMETER )
			STRING_REF( STRING_UNICODE, SYMBIAN_ENDIANESS, buf3332, "buf3332", buf3332_lenref, ISIHDR_DONT_GENERATE )
			FILLER( FILLER_VARIABLE, 32 )
		TRACE_END()
		
		TRACE_BEGIN( TRACE31, "unicode(65):" )
			AUTOGEN_BTRACE_HEADER_MAPPED
			PROPERTY( PROPERTY_PMD_PARAMETER )
			STRING_REF( STRING_UNICODE_ZERO_TERMINATED, SYMBIAN_ENDIANESS, Application, "Application", REF_LENGTH_DETERMINED_BY_ZERO, ISIHDR_DONT_GENERATE )
		TRACE_END()
		
		TRACE_BEGIN( TRACE32, "CDataOutPut::DumpL()" )
			AUTOGEN_BTRACE_HEADER_MAPPED
			PROPERTY( PROPERTY_PMD_PARAMETER )
			STRING_REF( STRING_UNICODE_ZERO_TERMINATED, SYMBIAN_ENDIANESS, fileName, "fileName", REF_LENGTH_DETERMINED_BY_ZERO, ISIHDR_DONT_GENERATE )
		TRACE_END()
		
		TRACE_BEGIN( TRACE33, "unicode abc =" )
			AUTOGEN_BTRACE_HEADER_MAPPED
			PROPERTY( PROPERTY_PMD_PARAMETER )
			STRING_REF( STRING_UNICODE_ZERO_TERMINATED, SYMBIAN_ENDIANESS, abc, "abc", REF_LENGTH_DETERMINED_BY_ZERO, ISIHDR_DONT_GENERATE )
		TRACE_END()
		
		TRACE_BEGIN( TRACE34, "ascii abc =" )
			AUTOGEN_BTRACE_HEADER_MAPPED
			PROPERTY( PROPERTY_PMD_PARAMETER )
			STRING_REF( STRING_ASCII_ZERO_TERMINATED, BE, abc, "abc", REF_LENGTH_DETERMINED_BY_ZERO, ISIHDR_DONT_GENERATE )
		TRACE_END()
		
		TRACE_BEGIN( TRACE35, "unicode(333):" )
			AUTOGEN_BTRACE_HEADER_MAPPED
			PROPERTY( PROPERTY_PMD_PARAMETER )
			STRING_REF( STRING_UNICODE_ZERO_TERMINATED, SYMBIAN_ENDIANESS, buf333, "buf333", REF_LENGTH_DETERMINED_BY_ZERO, ISIHDR_DONT_GENERATE )
		TRACE_END()
		
		TRACE_BEGIN( TRACE36, "ascii(600):" )
			AUTOGEN_BTRACE_HEADER_MAPPED
			PROPERTY( PROPERTY_PMD_PARAMETER )
			STRING_REF( STRING_ASCII_ZERO_TERMINATED, BE, ascii, "ascii", REF_LENGTH_DETERMINED_BY_ZERO, ISIHDR_DONT_GENERATE )
		TRACE_END()
	
	TRACE_GROUP_END()

RES_END

#undef AUTOGEN_TRACES_HAVE_FIXED_IDS
#include <isi_macros.h>

#endif
/*
* Copyright (c) 2009 Nokia Corporation and/or its subsidiary(-ies).
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
* Description:  Bluetooth service searcher.
*
*/


#ifndef __BTSERVICESEARCHER_H__
#define __BTSERVICESEARCHER_H__

// INCLUDES
#include <e32base.h>
#include <bttypes.h>
#include <btextnotifiers.h>

#include "SdpAttributeParser.h"
#include "SdpAttributeNotifier.h"

// CONSTANTS
#include "MessageProtocolConstants.h"

// CLASS DECLARATIONS
/**
* CBTServiceSearcher
* Searches for a service on a remote machine
*/

class CBTServiceSearcher : public CBase,
                           public MSdpAgentNotifier,
                           public MSdpAttributeNotifier
    {
    public: // Destructor

        /**
        * ~CBTServiceSearcher()
        * Destroy the object and release all memory objects
        */
        virtual ~CBTServiceSearcher();

    public: // New functions

        /**
        * SelectDeviceByDiscoveryL()
        * Select a device
        * @param aObserverRequestStatus the observer that is to
        * be notified when the device selection is complete.
        */
        void SelectDeviceByDiscoveryL( TRequestStatus&
                                       aObserverRequestStatus );

       /**
        * SelectDeviceByNameL()
        * Select a device by BT device name.
        * @param aDeviceName the name of the device to search and select.
        * @param aObserverRequestStatus the observer that is to
        * be notified when the device selection is complete.
        */
        void SelectDeviceByNameL( const TDesC& aDeviceName,
                                  TRequestStatus& aObserverRequestStatus );

        /**
        * FindServiceL()
        * Find a service on the specified device
        * @param aDeviceAddress the BT address of the device to search for
        * the service
        * @param aObserverRequestStatus the observer that is to be notified
        * when the service search is complete
        */
        void FindServiceL( const TBTDevAddr& aDeviceAddress,
            TRequestStatus& aObserverRequestStatus );

        /**
        * BTDevAddr()
        * @return the bluetooth device address
        */
        const TBTDevAddr& BTDevAddr();

        /**
        * ResponseParams()
        * @return Information about the device selected by the user
        */
        const TBTDeviceResponseParams& ResponseParams();

    protected:  // New functions

        /**
        * CBTServiceSearcher()
        * Constructs this object
        */
        CBTServiceSearcher();

        /**
        * Finished()
        * The search has finished. Notify the observer
        * that the process is complete.
        */
        virtual void Finished( TInt aError = KErrNone );

        /**
        * HasFinishedSearching()
        * Is the instance still wanting to search.
        * @return EFalse if the instance wants searching to continue.
        */
        virtual TBool HasFinishedSearching() const;

        /**
        * HasFoundService()
        * @return ETrue if a service has been found
        */
        TBool HasFoundService() const;

    protected: // abstract methods

        /**
        * ProtocolList()
        * The list of Protocols required by the service.
        */
        virtual const TSdpAttributeParser::TSdpAttributeList&
                                           ProtocolList() const = 0;

        /**
        * ServiceClass()
        * The service class to search for
        * @return the service class UUID
        */
        virtual const TUUID& ServiceClass() const = 0;

        /**
        * FoundElementL()
        * Read the data element
        * @param aKey a key that identifies the element
        * @param aValue the data element
        */
        virtual void FoundElementL( TInt aKey, CSdpAttrValue& aValue ) = 0;

    public: // from MSdpAgentNotifier

        /**
        * NextRecordRequestComplete()
        * Process the result of the next record request
        * @param aError the error code
        * @param aHandle the handle of the service record
        * @param aTotalRecordsCount the total number of matching
        * service records
        */
        void NextRecordRequestComplete( TInt aError,
                                        TSdpServRecordHandle aHandle,
                                        TInt aTotalRecordsCount );

        /**
        * AttributeRequestResult()
        * Process the next attribute requested
        * @param aHandle the handle of the service record
        * @param aAttrID the id of the attribute
        * @param aAttrValue the value of the attribute
        */
        void AttributeRequestResult( TSdpServRecordHandle aHandle,
                                     TSdpAttributeID aAttrID,
                                     CSdpAttrValue* aAttrValue );

        /**
        * AttributeRequestComplete()
        * Process the arrtibute request completion
        * @param aHandle the handle of the service record
        * @param aError the error code
        */
        void AttributeRequestComplete( TSdpServRecordHandle aHandle,
                                       TInt aError );

    private:    // Functions from base classes

        /**
        * NextRecordRequestCompleteL()
        * Process the result of the next record request
        * @param aError the error code
        * @param aHandle the handle of the service record
        * @param aTotalRecordsCount the total number of
        * matching service records
        */
        void NextRecordRequestCompleteL( TInt aError,
                                         TSdpServRecordHandle aHandle,
                                         TInt aTotalRecordsCount );

        /**
        * AttributeRequestResultL()
        * Process the next attribute requested
        * @param aHandle the handle of the service record
        * @param aAttrID the id of the attribute
        * @param aAttrValue the value of the attribute
        */
        void AttributeRequestResultL( TSdpServRecordHandle aHandle,
                                      TSdpAttributeID aAttrID,
                                      CSdpAttrValue* aAttrValue );

        /**
        * AttributeRequestCompleteL()
        * Process the arrtibute request completion
        * @param aHandle the handle of the service record
        * @param aError the error code
        */
        void AttributeRequestCompleteL( TSdpServRecordHandle,
                                        TInt aError );

    private:    // data

        /**
        * iStatusObserver pointer to the request status observer
        * Not owned by CBTServiceSearcher
        */
        TRequestStatus* iStatusObserver;

        /**
        * iIsDeviceSelectorConnected is the device
        * selector connected?
        */
        TBool iIsDeviceSelectorConnected;

        /**
        * iDeviceSelector
        * a handle to the bluetooth device selector notifier
        */
        RNotifier iDeviceSelector;

        /**
        * iResponse
        * the response of the device selection.
        */
        TBTDeviceResponseParamsPckg iResponse;

        /**
        * iSelectionFilter
        * Request a device selection
        */
        TBTDeviceSelectionParamsPckg iSelectionFilter;
        /**
        * iAgent a connetction to the SDP client
        * Owned by CBTServiceSearcher
        */
        CSdpAgent* iAgent;

        /**
        * iSdpSearchPattern a search pattern
        * Owned by CBTServiceSearcher
        */
        CSdpSearchPattern* iSdpSearchPattern;

        /** iHasFoundService has the service been found ? */
        TBool iHasFoundService;
    };

#endif // __BTSERVICESEARCHER_H__

// End of File

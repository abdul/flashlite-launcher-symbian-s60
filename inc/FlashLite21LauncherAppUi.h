/*
============================================================================
 Name        : FlashLite21LauncherAppUi.h
 Author      : Abdul Qabiz
 Copyright   : © 2007-2008 Abdul Qabiz (http://www.abdulqabiz.com)
 Description : Declares UI class for application.
============================================================================
*/

#ifndef FLASHLITE21LAUNCHERAPPUI_H
#define FLASHLITE21LAUNCHERAPPUI_H

// INCLUDES
#include <aknappui.h>

// FORWARD DECLARATIONS
class CFlashLite21LauncherContainer;


// CLASS DECLARATION

/**
* Application UI class.
* Provides support for the following features:
* - EIKON control architecture
*
*/
class CFlashLite21LauncherAppUi : public CAknAppUi
    {
    public: // // Constructors and destructor

        /**
        * EPOC default constructor.
        */
        void ConstructL();

        /**
        * Destructor.
        */
        ~CFlashLite21LauncherAppUi();

    public: // New functions
		static TInt WaitTimerCallbackL( TAny* aThis ); 
    public: // Functions from base classes

    private:
    
    		void LaunchSWF ();
        // From MEikMenuObserver
        void DynInitMenuPaneL(TInt aResourceId,CEikMenuPane* aMenuPane);

    private:
        /**
        * From CEikAppUi, takes care of command handling.
        * @param aCommand command to be handled
        */
        void HandleCommandL(TInt aCommand);

        /**
        * From CEikAppUi, handles key events.
        * @param aKeyEvent Event to handled.
        * @param aType Type of the key event.
        * @return Response code (EKeyWasConsumed, EKeyWasNotConsumed).
        */
        virtual TKeyResponse HandleKeyEventL(
            const TKeyEvent& aKeyEvent,TEventCode aType);

    private: //Data
        //CFlashLite21LauncherContainer* iAppContainer;
        CPeriodic* iWaitTimer;
        
    };

#endif



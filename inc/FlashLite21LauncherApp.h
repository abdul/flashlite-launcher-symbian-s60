/*
============================================================================
 Name        : FlashLite21LauncherApp.h
 Author      : Abdul Qabiz
 Copyright   : © 2007-2008 Abdul Qabiz (http://www.abdulqabiz.com)
 Description : Declares main application class.
============================================================================
*/

#ifndef FLASHLITE21LAUNCHERAPP_H
#define FLASHLITE21LAUNCHERAPP_H

// INCLUDES
#include <aknapp.h>

// CONSTANTS
// UID of the application
const TUid KUidFlashLite21Launcher = { 0x01ABB294 };

// CLASS DECLARATION

/**
* CFlashLite21LauncherApp application class.
* Provides factory to create concrete document object.
*
*/
class CFlashLite21LauncherApp : public CAknApplication
    {

    public: // Functions from base classes
    private:

        /**
        * From CApaApplication, creates CFlashLite21LauncherDocument document object.
        * @return A pointer to the created document object.
        */
        CApaDocument* CreateDocumentL();

        /**
        * From CApaApplication, returns application's UID (KUidFlashLite21Launcher).
        * @return The value of KUidFlashLite21Launcher.
        */
        TUid AppDllUid() const;
    };

#endif




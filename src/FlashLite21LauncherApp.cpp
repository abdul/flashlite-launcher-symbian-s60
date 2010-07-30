/*
============================================================================
 Name        : FlashLite21LauncherApp.cpp
 Author      : Abdul Qabiz
 Copyright   : © 2007-2008 Abdul Qabiz (http://www.abdulqabiz.com)
 Description : Main application class
============================================================================
*/

// INCLUDE FILES
#include    "FlashLite21LauncherApp.h"
#include    "FlashLite21LauncherDocument.h"

// ================= MEMBER FUNCTIONS =======================

// ---------------------------------------------------------
// CFlashLite21LauncherApp::AppDllUid()
// Returns application UID
// ---------------------------------------------------------
//
TUid CFlashLite21LauncherApp::AppDllUid() const
    {
    return KUidFlashLite21Launcher;
    }


// ---------------------------------------------------------
// CFlashLite21LauncherApp::CreateDocumentL()
// Creates CFlashLite21LauncherDocument object
// ---------------------------------------------------------
//
CApaDocument* CFlashLite21LauncherApp::CreateDocumentL()
    {
    return CFlashLite21LauncherDocument::NewL( *this );
    }

// ================= OTHER EXPORTED FUNCTIONS ==============
//
// ---------------------------------------------------------
// NewApplication()
// Constructs CFlashLite21LauncherApp
// Returns: created application object
// ---------------------------------------------------------
//
EXPORT_C CApaApplication* NewApplication()
    {
    return new CFlashLite21LauncherApp;
    }

// ---------------------------------------------------------
// E32Dll(TDllReason)
// Entry point function for EPOC Apps
// Returns: KErrNone: No error
// ---------------------------------------------------------
//
GLDEF_C TInt E32Dll( TDllReason )
    {
    return KErrNone;
    }




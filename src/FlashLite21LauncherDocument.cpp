/*
============================================================================
 Name        : FlashLite21LauncherDocument.cpp
 Author      : Abdul Qabiz
 Copyright   : © 2007-2008 Abdul Qabiz (http://www.abdulqabiz.com)
 Description : CFlashLite21LauncherDocument implementation
============================================================================
*/

// INCLUDE FILES
#include "FlashLite21LauncherDocument.h"
#include "FlashLite21LauncherAppui.h"

// ================= MEMBER FUNCTIONS =======================

// constructor
CFlashLite21LauncherDocument::CFlashLite21LauncherDocument(CEikApplication& aApp)
: CAknDocument(aApp)
    {
    }

// destructor
CFlashLite21LauncherDocument::~CFlashLite21LauncherDocument()
    {
    }

// EPOC default constructor can leave.
void CFlashLite21LauncherDocument::ConstructL()
    {
    }

// Two-phased constructor.
CFlashLite21LauncherDocument* CFlashLite21LauncherDocument::NewL(
        CEikApplication& aApp)     // CFlashLite21LauncherApp reference
    {
    CFlashLite21LauncherDocument* self = new (ELeave) CFlashLite21LauncherDocument( aApp );
    CleanupStack::PushL( self );
    self->ConstructL();
    CleanupStack::Pop();

    return self;
    }

// ----------------------------------------------------
// CFlashLite21LauncherDocument::CreateAppUiL()
// constructs CFlashLite21LauncherAppUi
// ----------------------------------------------------
//
CEikAppUi* CFlashLite21LauncherDocument::CreateAppUiL()
    {
    return new (ELeave) CFlashLite21LauncherAppUi;
    }



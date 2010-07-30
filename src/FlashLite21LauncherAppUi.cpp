/*
============================================================================
 Name        : CFlashLite21LauncherAppUi.cpp
 Author      : Abdul Qabiz
 Copyright   : © 2007-2008 Abdul Qabiz (http://www.abdulqabiz.com)
 Description : CFlashLite21LauncherAppUi implementation
============================================================================
*/

// INCLUDE FILES
#include "FlashLite21LauncherAppui.h"
//#include "FlashLite21LauncherContainer.h"
#include <FlashLite21Launcher.rsg>
#include "FlashLite21Launcher.hrh"
#include "FlashLite21LauncherConstants.h"

#include <avkon.hrh>
#include <aknnotewrappers.h>
#include <aknnotewrappers.h>
#include <apgcli.h>
#include <e32Keys.h>
#include <uikon.hrh>

// ================= MEMBER FUNCTIONS =======================
//
// ----------------------------------------------------------
// CFlashLite21LauncherAppUi::ConstructL()
//
// ----------------------------------------------------------
//
void CFlashLite21LauncherAppUi::ConstructL()
    {
    BaseConstructL();
	
	//timer
    iWaitTimer = CPeriodic::NewL( KWaitCallBackPriority );

	TThreadId id;
	RApaLsSession ls;
	User::LeaveIfError(ls.Connect());
	TApaAppInfo appinfo;
	TInt KError = ls.GetAppInfo(appinfo, KUidFlash21);
	CleanupClosePushL(ls);

	if(KError == KErrNone)
	{
		//Search for open player
		TFileName fnAppPath = appinfo.iFullName;
		TApaTaskList taskList( CEikonEnv::Static()->WsSession() );
		TApaTask task = taskList.FindApp( KUidFlash21 );
		
		if(task.Exists()) //If player is already running
		{
			TInt err = task.SwitchOpenFile( KLitSwfFileToLaunch );
			if(err == KErrNone)
			{
				//everything is fine
			} else 
			{
				//any error
			}
			task.BringToForeground();
		}
		else 
		{
			if(KError == KErrNone) //the player is not running so we launch it
			{
				
				TInt result = ls.StartDocument(fnAppPath,id);
				
				
				if (result!=KErrNone)
				{
					//any error
				} 
				else
				{
					if ( iWaitTimer->IsActive())
        			{
				        iWaitTimer->Cancel();
			        }
			        TCallBack callback( WaitTimerCallbackL, this );
			        iWaitTimer->Start( ( TTimeIntervalMicroSeconds32 ) KMaxWaitTime,
			                              ( TTimeIntervalMicroSeconds32 ) KMaxWaitTime, 
			                               callback );
				}
				CleanupStack::PopAndDestroy(); // Destroy cmd
			}
		}

	} 
	else 
	{
		//FlashPlayer not installed
	}
	
    /*iAppContainer = new (ELeave) CFlashLite21LauncherContainer;
    iAppContainer->SetMopParent( this );
    iAppContainer->ConstructL( ClientRect() );
    AddToStackL( iAppContainer );*/
    }

// ----------------------------------------------------
// CFlashLite21LauncherAppUi::~CFlashLite21LauncherAppUi()
// Destructor
// Frees reserved resources
// ----------------------------------------------------
//
CFlashLite21LauncherAppUi::~CFlashLite21LauncherAppUi()
    {
    	delete iWaitTimer;
   }

// -----------------------------------------------------------------------------
// CAknExNoteContainer::WaitTimerCallbackL()
// Callback function for deleting wait note.
// -----------------------------------------------------------------------------
//    
TInt CFlashLite21LauncherAppUi::WaitTimerCallbackL( TAny* aThis )
    {

    CFlashLite21LauncherAppUi* app = static_cast<CFlashLite21LauncherAppUi*>( aThis );
    app->iWaitTimer->Cancel();
    app->LaunchSWF();
    app->Exit ();
    return 0;
    }
// -----------------------------------------------------------------------------
// CTwitterLauncherAppContainer::LaunchSWF()
// method to open SWF file in FlashLite player.
// -----------------------------------------------------------------------------
//    
void CFlashLite21LauncherAppUi::LaunchSWF ()
{
	
	//Search for open player
	TApaTaskList taskList( CEikonEnv::Static()->WsSession() );
	TApaTask task = taskList.FindApp( KUidFlash21 );

	if( task.Exists()) //If player is already running
	{
		TInt err = task.SwitchOpenFile( KLitSwfFileToLaunch );
		if(err == KErrNone)
		{
			//everything is fine
		} else 
		{
			//any error
		}
		task.BringToForeground();
	}
}

// ------------------------------------------------------------------------------
// CFlashLite21LauncherAppUi::DynInitMenuPaneL(TInt aResourceId,CEikMenuPane* aMenuPane)
//  This function is called by the EIKON framework just before it displays
//  a menu pane. Its default implementation is empty, and by overriding it,
//  the application can set the state of menu items dynamically according
//  to the state of application data.
// ------------------------------------------------------------------------------
//
void CFlashLite21LauncherAppUi::DynInitMenuPaneL(
    TInt /*aResourceId*/,CEikMenuPane* /*aMenuPane*/)
    {
    }

// ----------------------------------------------------
// CFlashLite21LauncherAppUi::HandleKeyEventL(
//     const TKeyEvent& aKeyEvent,TEventCode /*aType*/)
// takes care of key event handling
// ----------------------------------------------------
//
TKeyResponse CFlashLite21LauncherAppUi::HandleKeyEventL(
    const TKeyEvent& /*aKeyEvent*/,TEventCode /*aType*/)
    {
    return EKeyWasNotConsumed;
    }

// ----------------------------------------------------
// CFlashLite21LauncherAppUi::HandleCommandL(TInt aCommand)
// takes care of command handling
// ----------------------------------------------------
//
void CFlashLite21LauncherAppUi::HandleCommandL(TInt aCommand)
    {
    switch ( aCommand )
        {
        case EAknSoftkeyBack:
        case EEikCmdExit:
            {
            Exit();
            break;
            }
        case EFlashLite21LauncherCmdAppTest:
            {
			// Info message shown only in the emulator
			iEikonEnv->InfoMsg(_L("test"));

			// Load localized message from the resource file
			HBufC* message = CEikonEnv::Static()->AllocReadResourceLC(R_MESSAGE_TEXT);
			// Show information note dialog
            CAknInformationNote* note = new (ELeave) CAknInformationNote;
            note->ExecuteLD(message->Des());
			CleanupStack::PopAndDestroy(message);
            break;
            }
        // TODO: Add Your command handling code here

        default:
            break;
        }
    }





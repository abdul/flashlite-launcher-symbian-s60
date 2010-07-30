#ifndef FLASHLITE21LAUNCHERCONSTANTS_H_
#define FLASHLITE21LAUNCHERCONSTANTS_H_

// CONSTANTS


// Define wait-time for player-splash-animation
// Unit is microsecond. 
const TInt KMaxWaitTime( 10 * 1000000 ); 
const TInt KAknExWaitPriorityTimer = 0;

//FlashPlayer 2.1 UID
const TUid KUidFlash21 = { 0x200077D6 }; 


const TInt KWaitCallBackPriority( CActive::EPriorityStandard );

//PATH of SWF to launch
_LIT(KLitSwfFileToLaunch, "E:\\Others\\Opera\\Twitter-FlashLite.swf");

//PATH of FlashLite Player
//_LIT(KLitFlashLitePath, "\\System\\Apps\\saflash2\\saflash2.app");


#endif /*FLASHLITE21LAUNCHERCONSTANTS_H_*/

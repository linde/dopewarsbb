
/****************************************************************************

	$Id: Main.cpp,v 1.2 2000/12/02 18:37:38 tedly Exp $
	$Souce$
 
	Description:
    


	Copyright (c) 2000 Monkeypants.com

	Thanks to Matt Lee for his work porting	Dope Wars to the Palm. This
	RIM version borrows a lot from his addictive, but straight-forward 
	verion of the game.

	Permission is hereby granted, free of charge, to any person obtaining a 
	copy of this software and associated documentation files (the "Software"), 
	to deal in the Software without restriction, including without limitation 
	the rights to use, copy, modify, merge, publish, distribute, sublicense, 
	and/or sell copies of the Software, and to permit persons to whom the 
	Software is furnished to do so, subject to the following conditions:

	The above copyright notice, acknowledgment of Matt Lee's original
	contribution, and this permission notice shall be included in all copies 
	or substantial portions of the Software.

	THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, 
	EXPRESS	OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF 
	MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. 
	IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY
	CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, 
	TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE 
	SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

	$Log: Main.cpp,v $
	Revision 1.2  2000/12/02 18:37:38  tedly
	pretty reasonable checkpoint here. lets call it alpha.
	

 
 ***************************************************************************/

#include <UI32.h>
#include <ribbon.h>
#include <OKDialog.h>


#include "DopeBitmap.h"
#include "DopeTable.h"
#include "DopeMenu.h"
#include "Player.h"


#define GAME_MESSAGE_COUNT		17
#define CITY_COUNT				6


char VersionPtr[] = "Dope Wars";
int AppStackSize = 6144;



/////// suggested by RIM SDK readme.txt ///////// 

static int LcdWidth()
{
    LcdConfig cur;
    LcdGetConfig( &cur );
    return(cur.width);
}

int WidthOfScreen = LcdWidth();

/////////////////////////////////////////////// 

 

void MyThread(void) {

	PID pid;
   
    //enable this app
    pid.Name = VersionPtr;
    pid.EnableForeground = true;
    pid.Icon = NULL;
    RimSetPID( &pid );

    UIEngine myUiEngine;
    myUiEngine.Initialize();
	
	DopeMenu myMenu (myUiEngine);
	TransactionDialog transDialog (myUiEngine);
	DopeTable dopetable (transDialog);

	Screen screen;
	Player player (myUiEngine, dopetable);
	player.setCurrentLocation ( myMenu.getStartLocation() );

    Title title;
    screen.AddLabel(title);
	screen.AddField ( dopetable );
	
	int menuSelection;
	MESSAGE msg;
	
    for(;;) {

		title.SetText ( player.getGameTitle() );
		myUiEngine.ProcessScreen(screen);
				
		RimGetMessage(&msg);

		int result = myUiEngine.HandleInput(msg);
		switch (result) {
			case CLICKED:	
				menuSelection = myMenu.handleMenu();
				if ( player.doMenuSelection(menuSelection) == Player::CLOSE ) {
					RibbonShowRibbon();
					return;
				}
				break;

			case UNHANDLED:
				if (msg.Event == KEY_DOWN && msg.SubMsg == KEY_ESCAPE) {
					if ( player.confirmGameEnd() ) {
						RibbonShowRibbon();
						return;
					}
				} else if (msg.Event == KEY_DOWN && 
					(msg.SubMsg == 'B' || msg.SubMsg == 'b') ) {
					player.doExchange (true); 

				} else if (msg.Event == KEY_DOWN && 
					(msg.SubMsg == 'S' || msg.SubMsg == 's') ) {
					player.doExchange (false); 

				} else if (msg.Event == KEY_DOWN && 
					(msg.SubMsg == 'J' || msg.SubMsg == 'j') ) {

					int dfltMenuSelection = DopeMenu::getStartLocationIndex ();
					menuSelection = myMenu.handleMenu(dfltMenuSelection);				
					if ( player.doMenuSelection(menuSelection) == Player::CLOSE ) {
						RibbonShowRibbon();
						return;
					}	

				}
				break;

			default:
				break;
		}	// end of switch
    }	// end of for 

    RibbonShowRibbon();

}

void PagerMain () {
    
	DEVICE_INFO info;
	RimGetDeviceInfo( &info ); 

	const BitMap *ribbonBitMap = &tokenBitMap24;

	// override with a smaller icon for pagers
	if ( info.deviceType == DEV_PAGER ){ 
		ribbonBitMap = &tokenBitMap16; 
	}

	RibbonRegisterFunction( VersionPtr, ribbonBitMap, 0, 34, MyThread, AppStackSize ); 

}




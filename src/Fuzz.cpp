
/****************************************************************************

	$Id: Fuzz.cpp,v 1.1 2000/12/02 19:13:28 tedly Exp $
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

	$Log: Fuzz.cpp,v $
	Revision 1.1  2000/12/02 19:13:28  tedly
	another small step
	

 
 ***************************************************************************/

#include <stdlib.h>
#include <OKDialog.h>


#include "Fuzz.h"

void Fuzz::checkForEncounter (UIEngine& uiEngine, DopeTable& dopeTable) {

	int curCopCount = dopeTable.getCopCount();
	if ( ! curCopCount ) {
		return;
	}

	TransactionDialog transDialog(uiEngine);
	char *choices [2];
	choices [RUN] = "Run";
	choices [FIGHT] = "Fight";
	char *msgStr = FUZZ_RUNFIGHT;
	
	while ( curCopCount ) {
		int selection = transDialog.getSelection(msgStr, NULL, choices, 0, true);

		if ( selection == RUN ) {
			if ( !(rand() % FLEE_SUCCESS_FREQUENCY) ) {
				return;	
			} 

			if ( !(rand() % BUSTED_FREQUENCY) ) {
				displayMessage (uiEngine, FUZZ_KID_BUSTED);
				dopeTable.handleBusted();
				return;	
			}
			msgStr = FUZZ_STILL_AROUND;
			continue;

		} else if ( selection == FIGHT ) {
			
			if ( !dopeTable.hasGun() ) {
				displayMessage (uiEngine, FUZZ_KID_HAS_NO_GUN);
				continue;
			} 
			
			
			if ( ! (rand() % FUZZ_DOWNED_FREQUENCY) ) {
				if ( --curCopCount ) {
					msgStr = FUZZ_DOWN;
				} 

				dopeTable.adjustCopCount(-1);
				continue;
			} else {
				displayMessage (uiEngine, FUZZ_KID_BUSTED);
				dopeTable.handleBusted();
				return;
			}
		}
	}	// end of while curCopCount

	displayMessage (uiEngine, FUZZ_FINISHED);
	return;
}


//////////////////////////////////////////////////////

void Fuzz::displayMessage (UIEngine& uiEngine, char *msg) {

	OKDialog dialog (msg);
	dialog.Go (uiEngine);
}

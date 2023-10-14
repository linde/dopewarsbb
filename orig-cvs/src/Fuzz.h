
/****************************************************************************

	$Id: Fuzz.h,v 1.1 2000/12/02 19:13:28 tedly Exp $
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

	$Log: Fuzz.h,v $
	Revision 1.1  2000/12/02 19:13:28  tedly
	another small step
	

 
 ***************************************************************************/


#ifndef fuzz_h_included
#define fuzz_h_included

#include <UI32.h>
#include <OKDialog.h>


#include "DopeWars.h"
#include "DopeTable.h"
#include "TransactionDialog.h"


#define FUZZ_RUNFIGHT			"You smell bacon! What will you do?"
#define FUZZ_STILL_AROUND		"They're still after you, what now?"
#define FUZZ_KID_HAS_NO_GUN		"You need a gun to fight!"
#define FUZZ_DOWN				"Officer down, you got one! Now what?"
#define FUZZ_FINISHED			"You finished off the cops."
#define FUZZ_KID_BUSTED			"Busted! You lose half you cash and all your dope."


class Fuzz {

    public:
	static void checkForEncounter (UIEngine& uiEngine, DopeTable& dopeTable);
	
	enum {
		RUN = 0,
		FIGHT = 1,
		BUSTED,
		LOST_THEM,
		FUZZ_GONE
	};

	protected:
	static void displayMessage (UIEngine& uiEngine, char *msg);

};

#endif // fuzz_h_included
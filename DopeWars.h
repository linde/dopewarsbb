
/****************************************************************************

	$Id: DopeWars.h,v 1.6 2001/06/17 21:35:18 tedly Exp $
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

	$Log: DopeWars.h,v $
	Revision 1.6  2001/06/17 21:35:18  tedly
	some minor stuff
	
	Revision 1.5  2001/01/11 06:32:56  tedly
	got rid of awful div by zero bug by preventing folks from buying unavailable drugs.
	
	Revision 1.4  2001/01/07 21:00:56  tedly
	now leave out a few drugs like the original ...
	
	Revision 1.3  2000/12/02 19:13:28  tedly
	another small step
	
	Revision 1.2  2000/12/02 18:37:38  tedly
	pretty reasonable checkpoint here. lets call it alpha.
	

 
 ***************************************************************************/

#ifndef dopewars_h_included
#define dopewars_h_included
  

#define DOPE_TABLE_QUERY_SIZE		40

#define NUM_DRUGS					8
#define NUM_GAME_DAYS				20
#define NUM_DRUGS_TO_LEAVE_OUT		3
#define INTEREST_PERCENTAGE			20
#define COAT_FREQUENCY				10
#define FLEE_SUCCESS_FREQUENCY		3
#define BUSTED_FREQUENCY			5
#define FUZZ_DOWNED_FREQUENCY		4
#define FUZZ_ENCOUNTER_FREQUENCY	7

#define INIT_CASH					5400
#define INIT_DEBT					5400
#define INIT_POCKETS				100
#define INIT_COP_COUNT				3
#define INIT_HAS_GUN				true // false


#define MSG_NOT_ENOUGH_CASH		"Not enough cash!"
#define MSG_NOT_HOLDING			"You aren't holding any!"
#define MSG_NOT_ENOUGH_DOPE		"You don't have that much!"
#define MSG_NOT_ENOUGH_POCKETS	"You don't have room!"
#define MSG_DRUG_NOT_AVAILABLE	"That drug's not available here!"
#define MSG_NOTHING_SELECTED	"Nothing selected!"
#define MSG_OK					"Done!"
#define MSG_ASK_BUY_COAT		"Would you like to buy a coat with more pockets for $200?"

#define MSG_GAMEEND_LOAN_SHARK	"The Loan Shark's thugs broke your legs.";
#define MSG_GAMEEND_RETIRED		"You retired a millionaire in the Carribbean with %d.";
#define MSG_GAMEEND_HALFBAD		"Congratulations! You didn't do half bad with %d.";
#define MSG_GAMEEND_NOMONEY		"You didn't make any money! You only had %d.";

#define MSG_DOPEWARS_VERSION	"dopewarsbb\nbeta_04"


#endif // dopewars_h_included



/****************************************************************************

	$Id: DopeWars.h,v 1.1 2000/12/01 01:15:56 tedly Exp $
	$Souce$
 
	Description:
    


	Copyright (c) 2000 Monkeypants.com

	Permission is hereby granted, free of charge, to any person obtaining a 
	copy of this software and associated documentation files (the "Software"), 
	to deal in the Software without restriction, including without limitation 
	the rights to use, copy, modify, merge, publish, distribute, sublicense, 
	and/or sell copies of the Software, and to permit persons to whom the 
	Software is furnished to do so, subject to the following conditions:

	The above copyright notice and this permission notice shall be included 
	in all copies or substantial portions of the Software.

	THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, 
	EXPRESS	OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF 
	MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. 
	IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY
	CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, 
	TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE 
	SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

	$Log: DopeWars.h,v $
	Revision 1.1  2000/12/01 01:15:56  tedly
	baseline very pre-alpha version ...
	

 
 ***************************************************************************/

#ifndef dopewars_h_included
#define dopewars_h_included
  

#define DOPE_TABLE_QUERY_SIZE		40

#define NUM_DRUGS					8
#define NUM_GAME_DAYS				20
#define INTEREST_PERCENTAGE			20

#define INIT_CASH					5400
#define INIT_DEBT					0 // 5400
#define INIT_POCKETS				100


#define MSG_NOT_ENOUGH_CASH		"Not enough cash!"
#define MSG_NOT_HOLDING			"You aren't holding any!"
#define MSG_NOT_ENOUGH_DOPE		"You don't have that much!"
#define MSG_NOT_ENOUGH_POCKETS	"You don't have room!"
#define MSG_NOTHING_SELECTED	"Nothing selected!"
#define MSG_OK					"Done!"


#endif // dopewars_h_included


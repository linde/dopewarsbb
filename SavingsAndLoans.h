
/****************************************************************************

	$Id: SavingsAndLoans.h,v 1.3 2001/01/07 17:57:41 tedly Exp $
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

	$Log: SavingsAndLoans.h,v $
	Revision 1.3  2001/01/07 17:57:41  tedly
	moving the banking stuff around to avoid asking redundant quesstions
	
	Revision 1.2  2000/12/02 18:37:38  tedly
	pretty reasonable checkpoint here. lets call it alpha.
	

 
 ***************************************************************************/


#ifndef savingsandloans_h_included
#define savingsandloans_h_included

#include <UI32.h>

#include "DopeTable.h"
#include "TransactionDialog.h"


#define SNL_VISIT_LOANSHARK		"Would you like to visit the loan skark?"	
#define SNL_VISIT_BANK			"Would you like to visit the bank?"

#define SNL_HOW_MUCH_FORMAT		"How much will you %s?"
#define SNL_BORROW				"borrow"
#define SNL_REPAY				"repay"
#define SNL_DEPOSIT				"deposit"
#define SNL_WITHDRAW			"withdraw"


class SavingsAndLoans {

    public:
	static void checkForBanking (UIEngine& uiEngine, DopeTable& dopeTable);

	protected:
	static void handleBankVisit (TransactionDialog& td, DopeTable& dt);
	static void handleSharkVisit (TransactionDialog& td, DopeTable& dt);


};

#endif // savingsandloans_h_included
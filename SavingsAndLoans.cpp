
/****************************************************************************

	$Id: SavingsAndLoans.cpp,v 1.1 2000/12/01 01:15:56 tedly Exp $
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

	$Log: SavingsAndLoans.cpp,v $
	Revision 1.1  2000/12/01 01:15:56  tedly
	baseline very pre-alpha version ...
	

 
 ***************************************************************************/

#include <YesNoDialog.h>
#include <OKDialog.h>


#include "SavingsAndLoans.h"


void SavingsAndLoans::checkForBanking (UIEngine& uiEngine, 
									  DopeTable& dopeTable) {
	YesNoDialog visitQuery;
	TransactionDialog transDialog(uiEngine);

	visitQuery.SetQuestion (SNL_VISIT_LOANSHARK);
	if ( visitQuery.Go(uiEngine) == YesNoDialog::ITEM_YES ) {

		int curCash = dopeTable.getCash();
		int curDebt = dopeTable.getDebt();
		int suggestedQty;

		int borrow = transDialog.getQuantity (SNL_BORROW, SNL_HOW_MUCH_FORMAT);
		if ( borrow >= 0 ) {
			dopeTable.handleLoan (borrow);
		}

		suggestedQty = (curCash > curDebt) ? curDebt : curCash;
		int repay = transDialog.getQuantity (SNL_REPAY, 
											 SNL_HOW_MUCH_FORMAT, 
											 suggestedQty);
		if ( repay >= 0 ) {
			if ( repay > curCash ) {
				OKDialog notEnoughCash (MSG_NOT_ENOUGH_CASH);
				notEnoughCash.Go(uiEngine);
			} else {		
				dopeTable.handleLoan (-repay);
			}
		}
	}

	/** now handle bank visits if the player has any cash on hand or in the bank. **/

	int curCash = dopeTable.getCash();
	int curSavings = dopeTable.getSavings();
	if ( (curCash + curSavings) < 1) {
		return;
	}
		
	visitQuery.SetQuestion (SNL_VISIT_BANK);
	if ( visitQuery.Go(uiEngine) == YesNoDialog::ITEM_YES ) {
		
		int deposit = transDialog.getQuantity (SNL_DEPOSIT, 
											   SNL_HOW_MUCH_FORMAT, 
											   curCash);
		if ( deposit >= 0 ) {
			if ( deposit > curCash ) {
				deposit = curCash;
			}
			dopeTable.handleDeposit(deposit);
		}


		curSavings = dopeTable.getSavings();
		int withdraw = transDialog.getQuantity (SNL_WITHDRAW, 
											    SNL_HOW_MUCH_FORMAT, 
											    curSavings);
		if ( withdraw >= 0 ) {
			if ( withdraw > curSavings ) {
				withdraw = curSavings;
			}
			dopeTable.handleDeposit(-curSavings);
		}
	} // end of handling banking

}
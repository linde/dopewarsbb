
/****************************************************************************

	$Id: DopeTable.cpp,v 1.4 2001/01/11 06:32:56 tedly Exp $
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

	$Log: DopeTable.cpp,v $
	Revision 1.4  2001/01/11 06:32:56  tedly
	got rid of awful div by zero bug by preventing folks from buying unavailable drugs.
	
	Revision 1.3  2001/01/07 21:00:56  tedly
	now leave out a few drugs like the original ...
	
	Revision 1.2  2000/12/02 18:37:38  tedly
	pretty reasonable checkpoint here. lets call it alpha.
	

 
 ***************************************************************************/


#include <stdlib.h>

#include "DopeTable.h"


DopeTable::DopeTable (TransactionDialog& transDialog)
	: m_transDialog ( transDialog ),
		m_cash ( INIT_CASH ),
		m_debt ( INIT_DEBT ),
		m_savings ( 0 ),
		m_pockets ( INIT_POCKETS ),
		m_hasGun ( INIT_HAS_GUN ),
		m_copCount ( INIT_COP_COUNT )
{
	// SetTableStructure (3, NUM_DRUGS, DEF_COLUMN_WIDTH * 4/3);
	SetTableStructure (4, NUM_DRUGS, DEF_COLUMN_WIDTH);
	SetJustification ( JUST_FULL );

	setPrices();
	for (int i=0; i< NUM_DRUGS; i++) {
		strcpy (m_tableCache[i][CITY_COLUMN], drugList[i].name);
	}
	
	strcpy (m_tableCache[PLAYER_CASH_LABEL_ROW][PLAYER_COLUMN], LABEL_CASH);
	strcpy (m_tableCache[PLAYER_DEBT_LABEL_ROW][PLAYER_COLUMN], LABEL_DEBT);
	strcpy (m_tableCache[PLAYER_SAVINGS_LABEL_ROW][PLAYER_COLUMN], LABEL_SAVINGS);
	strcpy (m_tableCache[PLAYER_COAT_LABEL_ROW][PLAYER_COLUMN], LABEL_COAT);

	clearHoldings();
	
	SetHighlight (HF_HIGHLIGHT_CELL);
			// HF_HIGHLIGHT_NONE, HF_HIGHLIGHT_OUTLINE,
			// HF_HIGHLIGHT_CELL, HF_HIGHLIGHT_CORNERS,
			// HF_HIGHLIGHT_ELBOW, HF_HIGHLIGHT_CROSS

	SetSelectedCell (1);

}


void DopeTable::writeCacheValue (int row, int col, int value) {
	writeCacheValue(row, col, "%ld", value, 0);
}


void DopeTable::writeCacheValue (int row, int col, 
								 char *format, int value1, int value2) {

	RimSprintf(m_tableCache [row][col], CELL_SIZE, format, value1, value2);
}

int DopeTable::updateQuantity (boolean buy, int qty) {
	int drug = GetSelectedRow();	
	return updateQuantity (buy, qty, drug);
}

int DopeTable::updateQuantity (boolean buy, int qty, int drug) {
	
	if ( drug < 0 ) {
		return -1;
	}
	int relativeQty = (buy) ? qty : -qty;
	m_totalHoldings += relativeQty;
	m_holdings [drug] += relativeQty;	
	writeCacheValue ( drug, HOLDING_COLUMN, m_holdings [drug] );
	writePlayerColumnToCache();
	
	return m_holdings [drug];
}

void DopeTable::handleBusted () { 
	m_cash /= 2;
	clearHoldings ();	// this calls writePlayerColumnToCache
	writePlayerColumnToCache();
}

void DopeTable::handleLoan (int amt) { 
	m_debt += amt;
	m_cash += amt;
	writePlayerColumnToCache();
}

void DopeTable::handleDeposit (int amt) { 
	m_savings += amt;
	m_cash -= amt;
	writePlayerColumnToCache();
}

void DopeTable::adjustCash (int add) { 
	m_cash += add; 
	writePlayerColumnToCache();
}	
		
void DopeTable::adjustPockets (int add) { 
	m_pockets += add; 
	writePlayerColumnToCache();
}

void DopeTable::writePlayerColumnToCache () {
	
	writeCacheValue ( PLAYER_CASH_VALUE_ROW, PLAYER_COLUMN, m_cash );
	writeCacheValue ( PLAYER_DEBT_VALUE_ROW, PLAYER_COLUMN, m_debt );
	writeCacheValue ( PLAYER_SAVINGS_VALUE_ROW, PLAYER_COLUMN, m_savings );
	
	writeCacheValue ( PLAYER_COAT_VALUE_ROW, PLAYER_COLUMN, 
						"%d/%d", m_totalHoldings, m_pockets );
}

void DopeTable::setPrices () {

	for (int i=0; i< NUM_DRUGS; i++) {
		int newPrice = drugList[i].baseCost;
		newPrice += rand () % drugList[i].variance;
		m_prices[i] = newPrice;
		writeCacheValue ( i, PRICE_COLUMN, newPrice);
	}

	for (i = 0; i < NUM_DRUGS_TO_LEAVE_OUT; i++) {
		int drugToLeaveOut = rand () % NUM_DRUGS;
		m_prices [drugToLeaveOut] = 0;
		writeCacheValue ( drugToLeaveOut, PRICE_COLUMN, 0);
	}

}

	
void DopeTable::compoundDebt () { 

	// we do odd integer math to avoid libs needed for casting	
	int newDebt = (100 + INTEREST_PERCENTAGE) * m_debt;
	m_debt = newDebt / 100; 
	writePlayerColumnToCache();
}


void DopeTable::clearHoldings () {

	for (int i=0; i<NUM_DRUGS; i++) {
		m_holdings[i] = 0;
		m_totalHoldings = 0;
		writeCacheValue ( i, HOLDING_COLUMN, 0) ;
	}
	
	writePlayerColumnToCache();
}
		

char *DopeTable::handleRandomStuff (int idx) {
	
	if ( rand () % drugMessages[idx].freq ) {
		return NULL;
	}

	int drug = drugMessages[idx].drug;		

	// first the random stuff which affects price	
	if ( drugMessages[idx].plus > 0) {
		int newPrice = m_prices [drug] * drugMessages[idx].plus;
		m_prices [drug] = newPrice;
		writeCacheValue ( drug, PRICE_COLUMN, newPrice);
	}
	if ( drugMessages[idx].minus > 0) {
		int newPrice = m_prices [drug] / drugMessages[idx].minus;
		m_prices [drug] = newPrice;
		writeCacheValue ( drug, PRICE_COLUMN, newPrice);
	}
	
	// now the random stuff for when you find drugs on the train
	int addcount = drugMessages[idx].add;
	if ( addcount != 0 ) {
		if ( (m_totalHoldings + addcount) <= m_pockets ) {
			updateQuantity (true, addcount, drugMessages[idx].drug);
		}
	}

	return drugMessages[idx].msg;
} // end of handleRandomStuff


char *DopeTable::handleExchange (boolean buy) {

	if ( buy && ( m_totalHoldings == m_pockets) ) {
		return MSG_NOT_ENOUGH_POCKETS;
	} 
		
	int drug = GetSelectedRow();	
	if ( drug < 0 ) {
		return NULL;
	}

	char *queryStr = drugList[drug].queryString;
	int price = m_prices[drug];
	int holdings = m_holdings[drug];	

	// dont let someone buy an unavailable drug, 
	// i.e. one that has a zero price

	if ( buy && price < 1 ) {
		return MSG_DRUG_NOT_AVAILABLE;
	} 


	
	int suggestedQty = buy ? (m_cash/price) : holdings;	
	if (buy && suggestedQty < 1) {
		return MSG_NOT_ENOUGH_CASH;
	} else if (!buy && holdings < 1) {
		return MSG_NOT_HOLDING;
	} 

	char *verb = buy ? "Buy" : "Sell";
	int qty = m_transDialog.getQuantity (queryStr, verb, suggestedQty);
	if ( qty < 1 ) {
		return NULL;
	} 
	if ( buy && ((qty * price) > m_cash ) ) {
		return MSG_NOT_ENOUGH_CASH;
	} 	
	if ( buy && ( (qty + holdings) > m_pockets) ) {
		qty = m_pockets - holdings;
	}
	
	int value = qty * price;
	m_cash += (buy) ? -value : value;
	updateQuantity (buy, qty, drug);

	return NULL;
}


typedef struct GameEndMessageType {
	char*	msg;
	int		worth;
} GameEndMessage;


char *DopeTable::handleGameEnd () {
	int netWorth = getNetWorth();
	
	if ( m_debt > 0 ) {
		return MSG_GAMEEND_LOAN_SHARK;
	} else if ( netWorth > 1000000 ) {
		return MSG_GAMEEND_RETIRED;
	} else if ( netWorth > 2000 ) {
		return MSG_GAMEEND_HALFBAD;
	} 
	
	return MSG_GAMEEND_NOMONEY;
}



int DopeTable::getNetWorth () {

	int netWorth = m_cash + m_savings - m_debt;

	for (int i=0; i<NUM_DRUGS; i++) {
		netWorth += m_prices[i];
	}

	return netWorth;
}



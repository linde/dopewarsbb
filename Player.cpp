
/****************************************************************************

	$Id: Player.cpp,v 1.1 2000/12/01 01:15:56 tedly Exp $
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

	$Log: Player.cpp,v $
	Revision 1.1  2000/12/01 01:15:56  tedly
	baseline very pre-alpha version ...
	

 
 ***************************************************************************/

#include <stdlib.h>

#include <YesNoDialog.h>

#include "Player.h"
#include "SavingsAndLoans.h"


void Player::doExchange (boolean buy) {

	char *statusMsg = m_dopeTable.handleExchange (buy);
	if (statusMsg) {
		displayMessage (statusMsg);	
	}
}


void Player::setCurrentLocation (const char* loc) { 
	m_curLocation = loc; 
	refreshGameTitle(); 
}


bool Player::confirmGameEnd () {

	YesNoDialog closePrompt ("End Game?", YesNoDialog::ITEM_NO);
	return ( closePrompt.Go ( m_uiEngine ) == YesNoDialog::ITEM_YES );
}



int Player::doMenuSelection(int menuSelection) {

	if ( DopeMenu::menuSelectionWasLocation(menuSelection) ) {
		
		const char *destName = DopeMenu::getLocationForIndex (menuSelection);
		return doJet(destName);

	} else if ( DopeMenu::menuSelectionWasBuy(menuSelection) ) {
		
		doExchange (true); 
		
	} else if ( DopeMenu::menuSelectionWasSell(menuSelection) ) {

		doExchange (false); 	

	} else if ( DopeMenu::menuSelectionWasClose(menuSelection) ) {
		// might want to consider saving game?
		if ( confirmGameEnd() ) {
			return CLOSE;
		}					
	}

	return CONTINUE;
}


//////////////////////////////////////////////////////

void Player::displayMessage (char *msg) {
	m_confirmDialog.SetQuestion (msg);
	m_confirmDialog.Go (m_uiEngine);
}

void Player::refreshGameTitle () {

	RimSprintf(m_gameTitle, sizeof(m_gameTitle), 
				"%s, %d days left", 
				 m_curLocation, m_daysLeft);
}

int Player::doJet (const char *destName) {

	// dont bother going where we already are	
	if ( !strcmp (m_curLocation, destName ) ){
		return CONTINUE;
	}

	m_curLocation = destName;
	if ( --m_daysLeft == 0 ) {
		doEndOfGame();
		return CLOSE;
	}

	refreshGameTitle();
 
	Status subwayPause ( "Subway ...", 50);
	m_dopeTable.setPrices();
	m_dopeTable.compoundDebt();
	doRandomStuff();

	SavingsAndLoans::checkForBanking (m_uiEngine, m_dopeTable);

	return CONTINUE;
}

void Player::doRandomStuff () {

	for (int i = 0; i < GAME_MESSAGE_COUNT; i++) {

		char *msg = m_dopeTable.handleRandomStuff (i);
		if ( msg ) {
			OKDialog alert(msg);
			alert.Go( m_uiEngine );
		}
	}
}

void Player::doEndOfGame () {

	char *gameEndMsg = m_dopeTable.handleGameEnd();
	int networth = m_dopeTable.getNetWorth();
	char displayMsg [64];

	RimSprintf(displayMsg, sizeof(displayMsg), gameEndMsg, networth);
	displayMessage(displayMsg);

}


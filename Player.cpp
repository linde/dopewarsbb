
/****************************************************************************

	$Id: Player.cpp,v 1.3 2000/12/02 19:13:29 tedly Exp $
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

	$Log: Player.cpp,v $
	Revision 1.3  2000/12/02 19:13:29  tedly
	another small step
	
	Revision 1.2  2000/12/02 18:37:38  tedly
	pretty reasonable checkpoint here. lets call it alpha.
	

 
 ***************************************************************************/

#include <stdlib.h>

#include <YesNoDialog.h>

#include "Player.h"
#include "SavingsAndLoans.h"
#include "Fuzz.h"


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

	// if we're not just starting and are in the top city, check to
	// see if the player would like to visit the loan shark or bank.
	if ( m_daysLeft < (NUM_GAME_DAYS - 1) &&
		 !strcmp (m_curLocation, DopeMenu::getStartLocation() ) )
	{
		SavingsAndLoans::checkForBanking (m_uiEngine, m_dopeTable);
	}

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

	if ( ! (rand() % COAT_FREQUENCY) ) {
		doCoatCheck();
	}

	if ( ! (rand() % FUZZ_ENCOUNTER_FREQUENCY) ) {
		Fuzz::checkForEncounter(m_uiEngine, m_dopeTable);
	}
}

void Player::doEndOfGame () {

	char *gameEndMsg = m_dopeTable.handleGameEnd();
	int networth = m_dopeTable.getNetWorth();
	char displayMsg [64];

	RimSprintf(displayMsg, sizeof(displayMsg), gameEndMsg, networth);
	displayMessage(displayMsg);
}

void Player::doCoatCheck () {

	if ( m_dopeTable.getCash() < 200 ) {
		return;
	}

	YesNoDialog coatQuery (MSG_ASK_BUY_COAT);
	if ( coatQuery.Go(m_uiEngine) == YesNoDialog::ITEM_YES ) {
		m_dopeTable.adjustCash(-200);
		m_dopeTable.adjustPockets(40);
	}

}
		


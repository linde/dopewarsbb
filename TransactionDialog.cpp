
/****************************************************************************

	$Id: TransactionDialog.cpp,v 1.2 2000/12/02 18:37:38 tedly Exp $
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

	$Log: TransactionDialog.cpp,v $
	Revision 1.2  2000/12/02 18:37:38  tedly
	pretty reasonable checkpoint here. lets call it alpha.
	

 
 ***************************************************************************/


#include "TransactionDialog.h"

int TransactionDialog::getQuantity (char *queryStr, 
									char *verb, 
									int suggestedQty, bool required) {
	
	char label [DOPE_TABLE_QUERY_SIZE];
	RimSprintf(label, DOPE_TABLE_QUERY_SIZE, queryStr, verb);

	m_dialog.SetDisplayString(label);
	m_dialog.RemoveAllFields();
	m_dialog.AddField (m_decEdit);

	if (suggestedQty != NO_SUGGESTION ) {
		m_decEdit.SetNumber(suggestedQty);
	}
	
	m_uiEngine.ProcessDialog(m_dialog);
	int qty = handleInput(m_decEdit, required);
	m_uiEngine.ClearDialog();

	return qty;	
}


int TransactionDialog::getSelection (char *queryStr, 
									 char *verb, 
									 char const * const * const choices,
									 int defaultIndex,
									 bool required) {

	char label [DOPE_TABLE_QUERY_SIZE];
	RimSprintf(label, DOPE_TABLE_QUERY_SIZE, queryStr, verb);

	m_dialog.SetDisplayString(label);
	m_dialog.RemoveAllFields();
	
	m_choice.SetChoices (choices, defaultIndex);
	m_dialog.AddField (m_choice);

	m_uiEngine.ProcessDialog(m_dialog);
	int qty = handleInput(m_choice, required);
	m_uiEngine.ClearDialog();

	return qty;	
}

int TransactionDialog::handleInput (Field& control, bool required) {

	MESSAGE msg;
	int qty = -1;
	boolean checkAgain = true;
		
	while (checkAgain) {

        RimGetMessage(&msg);
		int result = m_uiEngine.HandleInput(msg);

		switch (result) {

			case CLICKED:
				if ( &control == &m_decEdit ) {
					qty = m_decEdit.GetNumber();
				} else if ( &control == &m_choice ) {
					qty = m_choice.GetSelectedIndex();
				}
				checkAgain = false;
				break;

			case UNHANDLED:
				if ( msg.Event == KEY_DOWN && msg.SubMsg == KEY_ESCAPE ) {
					if ( !required ) {
						checkAgain = false;
					} 					
				} 
               break;		 								
        }
		m_uiEngine.ProcessDialog(m_dialog);	
    }

	m_uiEngine.ClearDialog();	
	return qty;
}
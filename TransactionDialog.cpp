
/****************************************************************************

	$Id: TransactionDialog.cpp,v 1.1 2000/12/01 01:15:56 tedly Exp $
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

	$Log: TransactionDialog.cpp,v $
	Revision 1.1  2000/12/01 01:15:56  tedly
	baseline very pre-alpha version ...
	

 
 ***************************************************************************/


#include "TransactionDialog.h"

int TransactionDialog::getQuantity (char *verb, 
									char *queryStr, 
									int suggestedQty ) {
	
	char label [DOPE_TABLE_QUERY_SIZE];
	RimSprintf(label, DOPE_TABLE_QUERY_SIZE, queryStr, verb);

	// m_decEdit.SetLabel (label);	
	m_dialog.SetDisplayString(label);
	if (suggestedQty != NO_SUGGESTION ) {
		m_decEdit.SetNumber(suggestedQty);
	}
	
	m_uiEngine.ProcessDialog(m_dialog);
	int qty = handleInput();
	m_uiEngine.ClearDialog();

	return qty;	
}

			  

int TransactionDialog::handleInput () {

	MESSAGE msg;
	int qty = -1;
	boolean checkAgain = true;
		
	while (checkAgain) {

        RimGetMessage(&msg);
		int result = m_uiEngine.HandleInput(msg);

		switch (result) {

			case CLICKED:
				qty = m_decEdit.GetNumber();
				checkAgain = false;
				break;

			case UNHANDLED:
               if (msg.Event == KEY_DOWN && msg.SubMsg == KEY_ESCAPE) {
                  checkAgain = false;
               } 
               break;		 								
        }
		m_uiEngine.ProcessDialog(m_dialog);	
    }

	m_uiEngine.ClearDialog();	
	return qty;
}
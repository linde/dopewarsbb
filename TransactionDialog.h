
/****************************************************************************

	$Id: TransactionDialog.h,v 1.3 2001/01/07 17:57:41 tedly Exp $
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

	$Log: TransactionDialog.h,v $
	Revision 1.3  2001/01/07 17:57:41  tedly
	moving the banking stuff around to avoid asking redundant quesstions
	
	Revision 1.2  2000/12/02 18:37:38  tedly
	pretty reasonable checkpoint here. lets call it alpha.
	

 
 ***************************************************************************/


#ifndef transactiondialog_h_included
#define transactiondialog_h_included
  

#include <UI32.h>

#include "DopeWars.h"

#define DIALOG_LABEL	"How Many?"

class TransactionDialog {

    public:
		enum {
			NO_SUGGESTION = -99999
		};
		
		TransactionDialog (UIEngine& uiEngine) 
			: m_uiEngine( uiEngine ) 
		{
			m_dialog.SetBitmap ( Bitmaps::QUESTION );
		};

		int getQuantity (char *queryStr, 
							char *verb, 
							int suggestedQty = NO_SUGGESTION,
							bool required = false);	
		int getSelection (char *queryStr,	
							char *verb, 
							char const * const * const choices,
							int defaultIndex=0,
							bool required = false);

		void warn (char *str);

    protected:

		int handleInput (Field& control, bool required);		
		void clearEditBuffer (Edit& edit);
		
		UIEngine&	m_uiEngine;
		Dialog		m_dialog;
		DecimalEdit m_decEdit;
		Choice		m_choice;

};

#endif // transactiondialog_h_included


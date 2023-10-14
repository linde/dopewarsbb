
/****************************************************************************

	$Id: MenuMgr.cpp,v 1.2 2000/12/02 18:37:38 tedly Exp $
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

	$Log: MenuMgr.cpp,v $
	Revision 1.2  2000/12/02 18:37:38  tedly
	pretty reasonable checkpoint here. lets call it alpha.
	

 
 ***************************************************************************/


#include "MenuMgr.h"

int MenuMgr::handleMenu( int defaultSelection ) { 

    RESULT result;

	if ( defaultSelection != -1 ) {
		m_menu.SetSelectedIndex ( defaultSelection );
	}

    // Display the menu on the screen
    m_uiEngine.ProcessMenu( m_menu );

    for( ; ; ) {

        //Get the next message for this task
        MESSAGE msg;
        RimGetMessage( &msg );

        //If it is a keyboard event, pass it to the UIEngine object
        //to handle.
	    if( msg.Device == DEVICE_KEYPAD ) {
		    result = m_uiEngine.HandleInput( msg );

            if( result == CLICKED ) {
			    
                //If the user clicked or pressed enter,
                //return the index of the selected item.
                m_uiEngine.ClearMenu();
                return( m_menu.GetSelectedIndex() );

            } else if(   ( result == UNHANDLED ) 
                      || ( result == HIDE_MENU )
                      || ( result == UI_SWITCH_TO_BACKGROUND ) ) {
                
                //If the user pressed backspace, return -1.
                m_uiEngine.ClearMenu();
                return( -1 );

            }
        }
    }
}

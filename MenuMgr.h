
/****************************************************************************

	$Id: MenuMgr.h,v 1.1 2000/12/01 01:15:56 tedly Exp $
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

	$Log: MenuMgr.h,v $
	Revision 1.1  2000/12/01 01:15:56  tedly
	baseline very pre-alpha version ...
	

 
 ***************************************************************************/


#ifndef menumgr_h_included
#define menumgr_h_included

#include "UI32.h"


class MenuMgr {

    public:
        
        MenuMgr( UIEngine&					uiEngine,
                 char const * const * const menuItems,
                 int  const                 numMenuItems )
            :m_menu( menuItems, numMenuItems ),
             m_uiEngine( uiEngine )
        {}

        int handleMenu (int defaultSelection = -1);

    protected:

        //The menu for the screen.
        Menu     m_menu;

        //The UIEngine object to use when processing the screen
        UIEngine & m_uiEngine;
};

#endif // menumgr_h_included
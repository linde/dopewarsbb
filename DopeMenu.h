
/****************************************************************************

	$Id: DopeMenu.h,v 1.1 2000/12/01 01:15:56 tedly Exp $
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

	$Log: DopeMenu.h,v $
	Revision 1.1  2000/12/01 01:15:56  tedly
	baseline very pre-alpha version ...
	

 
 ***************************************************************************/

#ifndef dopemenu_h_included
#define dopemenu_h_included


#include "MenuMgr.h"

static int const			NUM_CHOICE_MENU_ITEMS = 12;
static char const * const	MENU_SEPARATOR_BAR = "__";
static int					MIN_CITY_INDEX = 4;
static int					MAX_CITY_INDEX = 9;


char const * const sampleChoiceMenuItems[ NUM_CHOICE_MENU_ITEMS ] = {
							MENU_SEPARATOR_BAR,
	                       "Buy",				// 1			
		                    "Sell",				// 2
							MENU_SEPARATOR_BAR,
							"Bronx",			// 4
							"Ghetto",			// 5
							"Central Park",		// 6
							"Manhattan",		// 7
							"Coney Island",		// 8
							"Brooklyn",			// 9
							MENU_SEPARATOR_BAR,
					        "Close"				// 11
};

class DopeMenu : public MenuMgr {

    public:
        
        DopeMenu ( UIEngine& uiEngine )
            : MenuMgr ( uiEngine, sampleChoiceMenuItems, NUM_CHOICE_MENU_ITEMS )
        {}

		inline static boolean menuSelectionWasLocation (int idx) { 
			return ( idx >= MIN_CITY_INDEX && 
					 idx <= MAX_CITY_INDEX );
		}

		inline static boolean menuSelectionWasBuy (int idx) { 
			return ( idx == 1 );
		}

		inline static boolean menuSelectionWasSell (int idx) { 
			return ( idx == 2 );
		}		

		inline static boolean menuSelectionWasClose (int idx) { 
			return ( idx == 11 );
		}		

		inline static char const * const getLocationForIndex (int idx) {
			return sampleChoiceMenuItems[idx];	
		}

		inline static char const * const getStartLocation () {
			return getLocationForIndex (MIN_CITY_INDEX);
		}

		inline static int const getStartLocationIndex () {
			return MIN_CITY_INDEX;
		}

};


#endif // dopemenu_h_included
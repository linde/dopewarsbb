
/****************************************************************************

	$Id: DopeTable.h,v 1.2 2000/12/02 18:37:38 tedly Exp $
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

	$Log: DopeTable.h,v $
	Revision 1.2  2000/12/02 18:37:38  tedly
	pretty reasonable checkpoint here. lets call it alpha.
	

 
 ***************************************************************************/


#ifndef dopetable_h_included
#define dopetable_h_included

#include "UI32.h"

#include "DopeWars.h"
#include "TransactionDialog.h"


#define CELL_SIZE					16
#define GAME_MESSAGE_COUNT			17

#define LABEL_CASH				"Cash:"
#define LABEL_DEBT				"Debt:"
#define LABEL_SAVINGS			"Savings:"
#define LABEL_COAT				"Coat:"


#define GAMEEND_LOAN_SHARK_MSG	"The Loan Shark's thugs broke your legs.";
#define GAMEEND_RETIRED_MSG		"You retired a millionaire in the Carribbean with %d.";
#define GAMEEND_HALFBAD_MSG		"Congratulations! You didn't do half bad with %d.";
#define GAMEEND_NOMONEY_MSG		"You didn't make any money! You only had %d.";


typedef struct DrugType {
	char*	name;
	int		baseCost;
	int		variance;
	char*	queryString;
} Drug;


static DrugType drugList [NUM_DRUGS] = {

	{"Acid", 1000, 3500, "%s how much acid?"},
	{"Cocaine", 15000, 15000, "%s how much blow?"},
	{"Ludes", 10, 50, "%s how many ludes?"},
	{"PCP", 1000, 2500, "%s how much dust?"},
	{"Heroin", 5000, 9000, "%s how much smack?"},
	{"Weed", 300, 600, "%s how much weed, dude?"},
	{"Shrooms", 600, 750, "%s how many shrooms?"},
	{"Speed", 70, 180, "%s how much speed?"}

};

typedef struct DrugMessageType {
	int		freq;
	char*	msg;
	int		drug;
	int		plus;
	int		minus;
	int		add;
} DrugMessage;

static DrugMessage drugMessages [GAME_MESSAGE_COUNT] = {
	{13, "The cops just did a big Weed bust!  Prices are sky-high!", 5, 4, 0, 0},
	{20, "The cops just did a big PCP bust!  Prices are sky-high!", 3, 4, 0, 0},
	{25, "The cops just did a big Heroin bust!  Prices are sky-high!", 4, 4, 0, 0},
	{13, "The cops just did a big Ludes bust!  Prices are sky-high!", 2, 4, 0, 0},
	{35, "The cops just did a big Cocaine bust!  Prices are sky-high!", 1, 4, 0, 0},
	{15, "The cops just did a big Speed bust!  Prices are sky-high!", 7, 4, 0, 0},
	{25, "Addicts are buying Heroin at outrageous prices!", 4, 8, 0, 0},
	{20, "Addicts are buying Speed at outrageous prices!", 7, 8, 0, 0},
	{20, "Addicts are buying PCP at outrageous prices!", 3, 8, 0, 0},
	{17, "Hippies are buying Shrooms at outrageous prices!", 6, 8, 0, 0},
	{35, "Addicts are buying Cocaine at outrageous prices!", 1, 8, 0, 0},
	{17, "The market has been flooded with cheap home-made Acid!", 0, 0, 8, 0},
	{10, "A Columbian freighter dusted the Coast Guard!  Weed prices bottomed out!", 5, 0, 4, 0},
	{11, "A gang raided a local pharmacy and are selling cheap Ludes!", 2, 0, 8, 0},
	{55, "You found some Cocaine on a dead dude in the subway!", 1, 0, 0, 3},
	{45, "You found some Acid on a dead dude in the subway!", 0, 0, 0, 6},
	{35, "You found some PCP on a dead dude in the subway!", 3, 0, 0, 4}
};

class DopeTable : public Table {

    public:

		DopeTable (TransactionDialog& transDialog);

		// over-riding virtual methods
		void NowDisplaying (int const col, int const row) {
			PutCell ( m_tableCache[row][col] );
		}
		bool IsCellSelectable (int const col, int const row) {
			return (col == CITY_COLUMN);
		}

		int getSelectedDrugPrice ();
		int getSelectedDrugHolding ();
		inline int getTotalHoldings () { return m_totalHoldings; };

		char *handleRandomStuff (int idx);
		char *handleExchange (boolean buy);
		char *handleGameEnd ();
		void handleLoan (int amt);
		void handleDeposit (int amt);
		void handleBusted ();


		void adjustDrugPrice (int idx);
		int updateQuantity (boolean buy, int qty, int drug);
		int updateQuantity (boolean buy, int qty);	
		void adjustPockets (int add);
		void adjustCash (int add);
		
		// this adjust can be inline b/c we dont need 
		// to update the cache for this.
		inline void adjustCopCount (int add) { m_copCount += add; }
		
		void setPrices ();


		inline int getCopCount () { return m_copCount; }
		inline int getCash () { return m_cash; }
		inline int getDebt () { return m_debt; }
		inline int getSavings () { return m_savings; }
		inline int getPockets () { return m_pockets; }
		inline bool hasGun () { return m_hasGun; }

		
		
		void compoundDebt ();
		int getNetWorth ();	


    protected:

		enum {  
			HOLDING_COLUMN		= 0,
			CITY_COLUMN			= 1,
			PRICE_COLUMN		= 2,
			PLAYER_COLUMN		= 3
		};

		enum {
			PLAYER_CASH_LABEL_ROW = 0,
			PLAYER_CASH_VALUE_ROW = 1,

			PLAYER_DEBT_LABEL_ROW = 2,
			PLAYER_DEBT_VALUE_ROW = 3,

			PLAYER_SAVINGS_LABEL_ROW = 4,
			PLAYER_SAVINGS_VALUE_ROW = 5,

			PLAYER_COAT_LABEL_ROW = 6,
			PLAYER_COAT_VALUE_ROW = 7
		};

		void clearHoldings ();
		void writePlayerColumnToCache ();
		void writeCacheValue (int row, int col, int value);
		void writeCacheValue (int row, int col, 
							  char *format, int value1, int value2);
		
		int m_prices [NUM_DRUGS];
		int m_holdings [NUM_DRUGS];	
		int m_totalHoldings;		// sum of m_holdings

		int m_copCount;
		int m_cash;
		int m_debt;
		int m_savings;
		int m_pockets;
		bool m_hasGun;
		
		char m_tableCache [NUM_DRUGS][4][CELL_SIZE];

		TransactionDialog	&m_transDialog; 
		
};

#endif // dopetable_h_included

/****************************************************************************

	$Id: DopeBitmap.h,v 1.2 2000/12/02 18:37:38 tedly Exp $
	$Souce$
 
	Description:
    icon for display using the ribbon application
    width = 16, height = 16


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

	$Log: DopeBitmap.h,v $
	Revision 1.2  2000/12/02 18:37:38  tedly
	pretty reasonable checkpoint here. lets call it alpha.
	

 
 ***************************************************************************/

const BYTE _data24[] = {
0x80, 0xFF, 0x01,
0x60, 0x00, 0x06,
0x30, 0x00, 0x0C,
0x10, 0xFE, 0x08,
0x08, 0x18, 0x10,
0x4C, 0x70, 0x20,
0xA6, 0xC0, 0x21,
0x42, 0xF9, 0x67,
0x82, 0x02, 0x40,
0x02, 0x05, 0x40,
0x02, 0xFA, 0x4F,
0x02, 0x02, 0x48,
0x02, 0xFA, 0x4F,
0x02, 0x05, 0x40,
0x82, 0xF2, 0x47,
0x42, 0x19, 0x44,
0xA6, 0x0C, 0x26,
0x4A, 0x0C, 0x33,
0x0A, 0x9E, 0x11,
0x14, 0x00, 0x08,
0x68, 0x00, 0x0E,
0x90, 0xFF, 0x05,
0x20, 0x00, 0x03,
0xC0, 0xFF, 0x00
};

const BitMap tokenBitMap24 = { 1,
 24, 24,
(BYTE *) _data24
};

const BYTE _data16[] = {
0xE0, 0x07,
0x18, 0x18,
0xC4, 0x27,
0x82, 0x61,
0x12, 0x46,
0xAA, 0x5F,
0x51, 0x80,
0xA1, 0x9F,
0x41, 0xA0,
0xA1, 0x9F,
0x52, 0x80,
0x2A, 0x5F,
0x92, 0x48,
0xC4, 0x25,
0x08, 0x10,
0xF0, 0x0F
};

const BitMap tokenBitMap16 = { 1,
 16, 16,
(BYTE *) _data16
};
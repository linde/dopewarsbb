
/****************************************************************************

	$Id: DopeBitmap.h,v 1.1 2000/12/01 01:15:56 tedly Exp $
	$Souce$
 
	Description:
    icon for display using the ribbon application
    width = 16, height = 16


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

	$Log: DopeBitmap.h,v $
	Revision 1.1  2000/12/01 01:15:56  tedly
	baseline very pre-alpha version ...
	

 
 ***************************************************************************/

const BYTE _data[] = {
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

const BitMap bitmapSample = { 
	1, 32, 32, (BYTE *) _data
};


#include <kernel/drivers/term/font.h>

/*
	This font is 'lat1-16.psfu', found at '/usr/share/kbd/consolefonts/'
	in my Arch Linux installation.
	It has been converted to raw format with 'psftools', available at the AUR.
	I don't know whose it is or anything. Don't sue me.
*/
static unsigned char LAT1_16[] = {0,0,126,195,153,153,243,231,231,255,231,231,126,0,0,0,0,0,0,0,0,118,220,0,118,220,0,0,0,0,0,0,0,0,110,248,216,216,220,216,216,216,248,110,0,0,0,0,0,0,0,0,0,110,219,219,223,216,219,110,0,0,0,0,0,0,0,0,16,56,124,254,124,56,16,0,0,0,0,0,0,136,136,248,136,136,0,62,8,8,8,8,0,0,0,0,0,248,128,224,128,128,0,62,32,56,32,32,0,0,0,0,0,112,136,128,136,112,0,60,34,60,36,34,0,0,0,0,0,128,128,128,128,248,0,62,32,56,32,32,0,0,0,0,17,68,17,68,17,68,17,68,17,68,17,68,17,68,17,68,85,170,85,170,85,170,85,170,85,170,85,170,85,170,85,170,221,119,221,119,221,119,221,119,221,119,221,119,221,119,221,119,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,0,0,0,0,0,0,0,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,0,0,0,0,0,0,0,0,0,240,240,240,240,240,240,240,240,240,240,240,240,240,240,240,240,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,0,136,200,168,152,136,0,32,32,32,32,62,0,0,0,0,0,136,136,80,80,32,0,62,8,8,8,8,0,0,0,0,0,0,0,0,14,56,224,56,14,0,254,0,0,0,0,0,0,0,0,0,224,56,14,56,224,0,254,0,0,0,0,0,0,0,0,6,12,254,24,48,254,96,192,0,0,0,0,0,0,0,0,0,6,30,126,254,126,30,6,0,0,0,0,0,0,0,0,0,192,240,252,254,252,240,192,0,0,0,0,0,0,0,24,60,126,24,24,24,24,24,24,24,0,0,0,0,0,0,24,24,24,24,24,24,24,126,60,24,0,0,0,0,0,0,0,0,0,24,12,254,12,24,0,0,0,0,0,0,0,0,0,0,0,48,96,254,96,48,0,0,0,0,0,0,0,0,24,60,126,24,24,24,24,126,60,24,0,0,0,0,0,0,0,0,0,40,108,254,108,40,0,0,0,0,0,0,0,0,0,0,6,54,102,254,96,48,0,0,0,0,0,0,0,0,0,0,0,128,254,110,108,108,108,108,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,24,60,60,60,24,24,24,0,24,24,0,0,0,0,0,102,102,102,36,0,0,0,0,0,0,0,0,0,0,0,0,0,0,108,108,254,108,108,108,254,108,108,0,0,0,0,0,16,16,124,214,208,208,124,22,22,214,124,16,16,0,0,0,0,0,0,194,198,12,24,48,96,198,134,0,0,0,0,0,0,56,108,108,56,118,220,204,204,204,118,0,0,0,0,0,24,24,24,48,0,0,0,0,0,0,0,0,0,0,0,0,0,12,24,48,48,48,48,48,48,24,12,0,0,0,0,0,0,48,24,12,12,12,12,12,12,24,48,0,0,0,0,0,0,0,0,0,102,60,255,60,102,0,0,0,0,0,0,0,0,0,0,0,24,24,126,24,24,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,24,24,24,48,0,0,0,0,0,0,0,0,0,0,254,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,24,24,0,0,0,0,0,0,0,0,0,6,12,24,48,96,192,0,0,0,0,0,0,0,124,198,206,206,214,214,230,230,198,124,0,0,0,0,0,0,24,56,120,24,24,24,24,24,24,126,0,0,0,0,0,0,124,198,6,12,24,48,96,192,198,254,0,0,0,0,0,0,124,198,6,6,60,6,6,6,198,124,0,0,0,0,0,0,12,28,60,108,204,254,12,12,12,30,0,0,0,0,0,0,254,192,192,192,252,6,6,6,198,124,0,0,0,0,0,0,56,96,192,192,252,198,198,198,198,124,0,0,0,0,0,0,254,198,6,6,12,24,48,48,48,48,0,0,0,0,0,0,124,198,198,198,124,198,198,198,198,124,0,0,0,0,0,0,124,198,198,198,126,6,6,6,12,120,0,0,0,0,0,0,0,0,24,24,0,0,0,24,24,0,0,0,0,0,0,0,0,0,24,24,0,0,0,24,24,48,0,0,0,0,0,0,0,6,12,24,48,96,48,24,12,6,0,0,0,0,0,0,0,0,0,254,0,0,254,0,0,0,0,0,0,0,0,0,0,96,48,24,12,6,12,24,48,96,0,0,0,0,0,0,124,198,198,12,24,24,24,0,24,24,0,0,0,0,0,0,124,198,198,198,222,222,222,220,192,124,0,0,0,0,0,0,16,56,108,198,198,254,198,198,198,198,0,0,0,0,0,0,252,102,102,102,124,102,102,102,102,252,0,0,0,0,0,0,60,102,194,192,192,192,192,194,102,60,0,0,0,0,0,0,248,108,102,102,102,102,102,102,108,248,0,0,0,0,0,0,254,102,98,104,120,104,96,98,102,254,0,0,0,0,0,0,254,102,98,104,120,104,96,96,96,240,0,0,0,0,0,0,60,102,194,192,192,222,198,198,102,58,0,0,0,0,0,0,198,198,198,198,254,198,198,198,198,198,0,0,0,0,0,0,60,24,24,24,24,24,24,24,24,60,0,0,0,0,0,0,30,12,12,12,12,12,204,204,204,120,0,0,0,0,0,0,230,102,102,108,120,120,108,102,102,230,0,0,0,0,0,0,240,96,96,96,96,96,96,98,102,254,0,0,0,0,0,0,198,238,254,254,214,198,198,198,198,198,0,0,0,0,0,0,198,230,246,254,222,206,198,198,198,198,0,0,0,0,0,0,124,198,198,198,198,198,198,198,198,124,0,0,0,0,0,0,252,102,102,102,124,96,96,96,96,240,0,0,0,0,0,0,124,198,198,198,198,198,198,214,222,124,12,14,0,0,0,0,252,102,102,102,124,108,102,102,102,230,0,0,0,0,0,0,124,198,198,100,56,12,6,198,198,124,0,0,0,0,0,0,126,126,90,24,24,24,24,24,24,60,0,0,0,0,0,0,198,198,198,198,198,198,198,198,198,124,0,0,0,0,0,0,198,198,198,198,198,198,198,108,56,16,0,0,0,0,0,0,198,198,198,198,214,214,214,254,238,108,0,0,0,0,0,0,198,198,108,124,56,56,124,108,198,198,0,0,0,0,0,0,102,102,102,102,60,24,24,24,24,60,0,0,0,0,0,0,254,198,134,12,24,48,96,194,198,254,0,0,0,0,0,0,60,48,48,48,48,48,48,48,48,60,0,0,0,0,0,0,0,0,0,192,96,48,24,12,6,0,0,0,0,0,0,0,60,12,12,12,12,12,12,12,12,60,0,0,0,0,16,56,108,198,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,255,0,0,48,48,48,24,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,120,12,124,204,204,204,118,0,0,0,0,0,0,224,96,96,120,108,102,102,102,102,124,0,0,0,0,0,0,0,0,0,124,198,192,192,192,198,124,0,0,0,0,0,0,28,12,12,60,108,204,204,204,204,118,0,0,0,0,0,0,0,0,0,124,198,254,192,192,198,124,0,0,0,0,0,0,56,108,100,96,240,96,96,96,96,240,0,0,0,0,0,0,0,0,0,118,204,204,204,204,204,124,12,204,120,0,0,0,224,96,96,108,118,102,102,102,102,230,0,0,0,0,0,0,24,24,0,56,24,24,24,24,24,60,0,0,0,0,0,0,6,6,0,14,6,6,6,6,6,6,102,102,60,0,0,0,224,96,96,102,108,120,120,108,102,230,0,0,0,0,0,0,56,24,24,24,24,24,24,24,24,60,0,0,0,0,0,0,0,0,0,236,254,214,214,214,214,198,0,0,0,0,0,0,0,0,0,220,102,102,102,102,102,102,0,0,0,0,0,0,0,0,0,124,198,198,198,198,198,124,0,0,0,0,0,0,0,0,0,220,102,102,102,102,102,124,96,96,240,0,0,0,0,0,0,118,204,204,204,204,204,124,12,12,30,0,0,0,0,0,0,220,118,102,96,96,96,240,0,0,0,0,0,0,0,0,0,124,198,96,56,12,198,124,0,0,0,0,0,0,16,48,48,252,48,48,48,48,54,28,0,0,0,0,0,0,0,0,0,204,204,204,204,204,204,118,0,0,0,0,0,0,0,0,0,102,102,102,102,102,60,24,0,0,0,0,0,0,0,0,0,198,198,214,214,214,254,108,0,0,0,0,0,0,0,0,0,198,108,56,56,56,108,198,0,0,0,0,0,0,0,0,0,198,198,198,198,198,198,126,6,12,248,0,0,0,0,0,0,254,204,24,48,96,198,254,0,0,0,0,0,0,14,24,24,24,112,24,24,24,24,14,0,0,0,0,0,0,24,24,24,24,24,24,24,24,24,24,0,0,0,0,0,0,112,24,24,24,14,24,24,24,24,112,0,0,0,0,0,0,118,220,0,0,0,0,0,0,0,0,0,0,0,0,0,102,0,102,102,102,102,60,24,24,24,60,0,0,0,0,96,48,0,56,108,198,198,254,198,198,198,198,0,0,0,0,12,24,0,56,108,198,198,254,198,198,198,198,0,0,0,0,16,56,108,0,56,108,198,198,254,198,198,198,0,0,0,0,118,220,0,56,108,198,198,254,198,198,198,198,0,0,0,0,0,108,0,56,108,198,198,254,198,198,198,198,0,0,0,0,56,108,56,0,56,108,198,198,254,198,198,198,0,0,0,0,0,0,62,120,216,216,252,216,216,216,216,222,0,0,0,0,0,0,60,102,194,192,192,192,192,194,102,60,12,102,60,0,96,48,0,254,102,96,96,124,96,96,102,254,0,0,0,0,12,24,0,254,102,96,96,124,96,96,102,254,0,0,0,0,16,56,108,0,254,102,96,124,96,96,102,254,0,0,0,0,0,108,0,254,102,96,96,124,96,96,102,254,0,0,0,0,96,48,0,60,24,24,24,24,24,24,24,60,8,0,0,0,6,12,0,60,24,24,24,24,24,24,24,60,0,0,0,0,24,60,102,0,60,24,24,24,24,24,24,60,0,0,0,0,0,102,0,60,24,24,24,24,24,24,24,60,0,0,0,0,0,0,248,108,102,102,246,102,102,102,108,248,0,0,0,0,118,220,0,198,230,246,254,222,206,198,198,198,0,0,0,0,96,48,0,124,198,198,198,198,198,198,198,124,0,0,0,0,12,24,0,124,198,198,198,198,198,198,198,124,0,0,0,0,16,56,108,0,124,198,198,198,198,198,198,124,0,0,0,0,118,220,0,124,198,198,198,198,198,198,198,124,0,0,0,0,0,108,0,124,198,198,198,198,198,198,198,124,0,0,0,0,0,0,0,0,0,102,60,24,60,102,0,0,0,0,0,0,0,0,126,198,206,206,222,246,230,230,198,252,0,0,0,0,96,48,0,198,198,198,198,198,198,198,198,124,0,0,0,0,12,24,0,198,198,198,198,198,198,198,198,124,0,0,0,0,16,56,108,0,198,198,198,198,198,198,198,124,0,0,0,0,0,108,0,198,198,198,198,198,198,198,198,124,0,0,0,0,6,12,0,102,102,102,102,60,24,24,24,60,0,0,0,0,0,0,240,96,124,102,102,102,102,124,96,240,0,0,0,0,0,0,124,198,198,198,204,198,198,198,214,220,128,0,0,0,0,0,0,0,0,0,0,0,0,0,130,254,0,0,0,0,0,0,0,0,24,24,0,24,24,24,60,60,60,24,0,0,0,0,0,0,16,124,214,208,208,208,214,124,16,0,0,0,0,0,56,108,96,96,240,96,96,102,246,108,0,0,0,0,0,0,0,0,198,124,108,108,124,198,0,0,0,0,0,0,0,0,102,102,60,24,126,24,126,24,24,24,0,0,0,0,0,0,24,24,24,24,0,24,24,24,24,24,0,0,0,0,0,124,198,96,56,108,198,198,108,56,12,198,124,0,0,0,0,108,108,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,60,66,153,165,161,165,153,66,60,0,0,0,0,0,0,0,60,108,108,62,0,126,0,0,0,0,0,0,0,0,0,0,0,0,0,54,108,216,108,54,0,0,0,0,0,0,0,0,0,0,0,0,254,6,6,6,6,0,0,0,0,0,0,0,0,0,0,0,0,126,0,0,0,0,0,0,0,0,0,0,60,66,185,165,185,165,165,66,60,0,0,0,0,0,255,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,56,108,108,56,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,24,24,126,24,24,0,126,0,0,0,0,56,108,24,48,124,0,0,0,0,0,0,0,0,0,0,0,56,108,24,108,56,0,0,0,0,0,0,0,0,0,0,0,0,24,48,96,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,204,204,204,204,204,204,246,192,192,192,0,0,0,127,214,214,118,54,54,54,54,54,54,0,0,0,0,0,0,0,0,0,0,24,24,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,24,108,56,0,48,112,48,48,120,0,0,0,0,0,0,0,0,0,0,0,0,0,56,108,108,56,0,124,0,0,0,0,0,0,0,0,0,0,0,0,0,216,108,54,108,216,0,0,0,0,0,0,96,224,96,96,246,12,24,48,102,206,26,63,6,6,0,0,96,224,96,96,246,12,24,48,110,219,6,12,31,0,0,0,112,216,48,216,118,12,24,48,102,206,26,63,6,6,0,0,0,0,0,0,48,48,0,48,48,48,96,198,198,124,0,0,0,0,0,0,255,0,0,0,0,0,0,0,0,0,0,0,24,24,24,24,24,24,24,24,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,31,0,0,0,0,0,0,0,0,24,24,24,24,24,24,24,31,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,24,24,24,24,24,24,24,24,24,24,24,24,24,24,24,24,24,24,24,24,24,24,24,24,24,0,0,0,0,0,0,0,31,24,24,24,24,24,24,24,24,24,24,24,24,24,24,24,31,24,24,24,24,24,24,24,24,0,0,0,0,0,0,0,248,0,0,0,0,0,0,0,0,24,24,24,24,24,24,24,248,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,255,0,0,0,0,0,0,0,0,24,24,24,24,24,24,24,255,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,248,24,24,24,24,24,24,24,24,24,24,24,24,24,24,24,248,24,24,24,24,24,24,24,24,0,0,0,0,0,0,0,255,24,24,24,24,24,24,24,24,24,24,24,24,24,24,24,255,24,24,24,24,24,24,24,24,0,0,0,0,0,0,0,0,0,0,255,0,0,0,0,0,108,108,108,108,108,108,108,108,124,0,0,0,0,0,0,0,0,0,0,0,0,0,127,96,127,0,0,0,0,0,0,0,108,108,108,108,108,108,111,96,127,0,0,0,0,0,0,0,0,0,0,0,0,0,124,108,108,108,108,108,108,108,108,108,108,108,108,108,108,108,108,108,108,108,108,108,108,108,108,108,0,0,0,0,0,0,127,96,111,108,108,108,108,108,108,108,108,108,108,108,108,108,111,96,111,108,108,108,108,108,108,108,0,0,0,0,0,0,252,12,252,0,0,0,0,0,0,0,108,108,108,108,108,108,236,12,252,0,0,0,0,0,0,0,0,0,0,0,0,0,255,0,255,0,0,0,0,0,0,0,108,108,108,108,108,108,239,0,255,0,0,0,0,0,0,0,0,0,0,0,0,0,252,12,236,108,108,108,108,108,108,108,108,108,108,108,108,108,236,12,236,108,108,108,108,108,108,108,0,0,0,0,0,0,255,0,239,108,108,108,108,108,108,108,108,108,108,108,108,108,239,0,239,108,108,108,108,108,108,108,0,96,48,24,0,120,12,124,204,204,204,118,0,0,0,0,0,24,48,96,0,120,12,124,204,204,204,118,0,0,0,0,0,16,56,108,0,120,12,124,204,204,204,118,0,0,0,0,0,0,118,220,0,120,12,124,204,204,204,118,0,0,0,0,0,0,0,108,0,120,12,124,204,204,204,118,0,0,0,0,0,56,108,56,0,120,12,124,204,204,204,118,0,0,0,0,0,0,0,0,0,126,219,27,127,216,219,126,0,0,0,0,0,0,0,0,0,124,198,192,192,192,198,124,24,108,56,0,0,96,48,24,0,124,198,254,192,192,198,124,0,0,0,0,0,12,24,48,0,124,198,254,192,192,198,124,0,0,0,0,0,16,56,108,0,124,198,254,192,192,198,124,0,0,0,0,0,0,0,108,0,124,198,254,192,192,198,124,0,0,0,0,0,96,48,24,0,56,24,24,24,24,24,60,0,0,0,0,0,12,24,48,0,56,24,24,24,24,24,60,0,0,0,0,0,24,60,102,0,56,24,24,24,24,24,60,0,0,0,0,0,0,0,108,0,56,24,24,24,24,24,60,0,0,0,0,0,120,48,120,12,126,198,198,198,198,198,124,0,0,0,0,0,0,118,220,0,220,102,102,102,102,102,102,0,0,0,0,0,96,48,24,0,124,198,198,198,198,198,124,0,0,0,0,0,12,24,48,0,124,198,198,198,198,198,124,0,0,0,0,0,16,56,108,0,124,198,198,198,198,198,124,0,0,0,0,0,0,118,220,0,124,198,198,198,198,198,124,0,0,0,0,0,0,0,108,0,124,198,198,198,198,198,124,0,0,0,0,0,0,0,0,0,24,0,126,0,24,0,0,0,0,0,0,0,0,0,0,0,126,206,222,254,246,230,252,0,0,0,0,0,96,48,24,0,204,204,204,204,204,204,118,0,0,0,0,0,24,48,96,0,204,204,204,204,204,204,118,0,0,0,0,0,48,120,204,0,204,204,204,204,204,204,118,0,0,0,0,0,0,0,204,0,204,204,204,204,204,204,118,0,0,0,0,0,12,24,48,0,198,198,198,198,198,198,126,6,12,248,0,0,0,240,96,96,124,102,102,102,102,124,96,96,240,0,0,0,0,0,108,0,198,198,198,198,198,198,126,6,12,248,0};

uint8_t isBitSet(uint8_t lat1, char c, int y, int x) {
	uint8_t character = (uint8_t)c;

	// Map.
	if(character >= 0xA0 && lat1 == 3) character += 0x40;

	return LAT1_16[character*16 + y] & (1 << (7-x));
}

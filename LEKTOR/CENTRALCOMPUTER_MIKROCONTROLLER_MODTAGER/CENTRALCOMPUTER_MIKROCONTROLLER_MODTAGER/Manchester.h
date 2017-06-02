//..................................................................................................................................
//.MMMMMM...MMMMMM....AAAAA.....NNNN...NNNN....CCCCCCCC...HHHH...HHHH..EEEEEEEEEEE..SSSSSSSS..TTTTTTTTTTT.EEEEEEEEEEEE.RRRRRRRRRR....
//.MMMMMM...MMMMMM...AAAAAA.....NNNNN..NNNN...CCCCCCCCCC..HHHH...HHHH..EEEEEEEEEEE.SSSSSSSSSS.TTTTTTTTTTT.EEEEEEEEEEEE.RRRRRRRRRRR...
//.MMMMMMM.MMMMMMM...AAAAAA.....NNNNN..NNNN..CCCCCCCCCCC..HHHH...HHHH..EEEEEEEEEEESSSSSSSSSSS.TTTTTTTTTTT.EEEEEEEEEEEE.RRRRRRRRRRR...
//.MMMMMMM.MMMMMMM...AAAAAAA....NNNNNN.NNNN.CCCCCC.CCCCCC.HHHH...HHHH..EEEE.......SSSSS.SSSSS.....TTTT....EEEE.........RRRR...RRRRR..
//.MMMMMMM.MMMMMMM..AAAAAAAA....NNNNNNNNNNN.CCCCC...CCCCC.HHHH...HHHH..EEEE.......SSSSSS..........TTTT....EEEE.........RRRR...RRRRR..
//.MMMMMMM.MMMMMMM..AAAAAAAAA...NNNNNNNNNNN.CCCC..........HHHHHHHHHHH..EEEEEEEEEE..SSSSSSSSS......TTTT....EEEEEEEEEE...RRRRRRRRRRR...
//.MMMMMMMMMMMMMMM..AAA..AAAA...NNNNNNNNNNN.CCCC..........HHHHHHHHHHH..EEEEEEEEEE..SSSSSSSSSS.....TTTT....EEEEEEEEEE...RRRRRRRRRRR...
//.MMMMMMMMMMMMMMM.AAAAAAAAAA...NNNNNNNNNNN.CCCC..........HHHHHHHHHHH..EEEEEEEEEE....SSSSSSSSS....TTTT....EEEEEEEEEE...RRRRRRRRRR....
//.MMMMMMMMMMMMMMM.AAAAAAAAAAA..NNNNNNNNNNN.CCCCC...CCCCC.HHHH...HHHH..EEEE.............SSSSSS....TTTT....EEEE.........RRRRRRRRRR....
//.MMMM.MMMMM.MMMMAAAAAAAAAAAA..NNNN.NNNNNN.CCCCCC.CCCCCC.HHHH...HHHH..EEEE.......SSSSS..SSSSS....TTTT....EEEE.........RRRR.RRRRRR...
//.MMMM.MMMMM.MMMMAAAA....AAAAA.NNNN.NNNNNN..CCCCCCCCCCC..HHHH...HHHH..EEEEEEEEEEESSSSSSSSSSSS....TTTT....EEEEEEEEEEE..RRRR..RRRRR...
//.MMMM.MMMMM.MMMMAAAA....AAAAA.NNNN..NNNNN...CCCCCCCCCC..HHHH...HHHH..EEEEEEEEEEE.SSSSSSSSSS.....TTTT....EEEEEEEEEEE..RRRR...RRRRR..
//.MMMM.MMMMM.MMMMAAAA.....AAAA.NNNN...NNNN....CCCCCCCC...HHHH...HHHH..EEEEEEEEEEE..SSSSSSSS......TTTT....EEEEEEEEEEE..RRRR...RRRRR...h
//..................................................................................................................................
// Skrevet af Patrick Bjerregaard og Kasper Hermansen.
// Version: 1.01RC
// De to nedenst�ende funktioner kan benyttes til at kovertere en given tekststreng til Manchester kode og benytter dynamisk hukommelse til at opn� dette.
// Fungerer b�de p� MCU og PC.

#pragma once
#include <string.h>
#include <stdlib.h>

unsigned char* stringToManchester(unsigned char* toBeConverted);
unsigned char* manchesterToString(unsigned char* toBeConverted);
void freePtr();
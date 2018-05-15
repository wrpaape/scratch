#include "base_map.h" // declarations
#include "limits.h"   // UCHAR_MAX

#if (UCHAR_MAX <= 255)
#	define FULL_TABLE 1
#else
#	define FULL_TABLE 0
#endif


static const unsigned char digit_table[UCHAR_MAX + 1] = {
        ['1'] = 1,
        ['2'] = 2,
        ['3'] = 3,
        ['4'] = 4,
        ['5'] = 5,
        ['6'] = 6,
        ['7'] = 7,
        ['8'] = 8,
        ['9'] = 9,

        ['A'] = ['a'] = 10,
        ['B'] = ['b'] = 11,
        ['C'] = ['c'] = 12,
        ['D'] = ['d'] = 13,
        ['E'] = ['e'] = 14,
        ['F'] = ['f'] = 15,
        ['G'] = ['g'] = 16,
        ['H'] = ['h'] = 17,
        ['I'] = ['i'] = 18,
        ['J'] = ['j'] = 19,
        ['K'] = ['k'] = 20,
        ['L'] = ['l'] = 21,
        ['M'] = ['m'] = 22,
        ['N'] = ['n'] = 23,
        ['O'] = ['o'] = 24,
        ['P'] = ['p'] = 25,
        ['Q'] = ['q'] = 26,
        ['R'] = ['r'] = 27,
        ['S'] = ['s'] = 28,
        ['T'] = ['t'] = 29,
        ['U'] = ['u'] = 30,
        ['V'] = ['v'] = 31,
        ['W'] = ['w'] = 32,
        ['X'] = ['x'] = 33,
        ['Y'] = ['y'] = 34,
        ['Z'] = ['z'] = 35,

        ['\0'	 ... '0'      ] = UCHAR_MAX,
        ['9' + 1 ... 'A' - 1  ] = UCHAR_MAX,
        ['Z' + 1 ... 'a' - 1  ] = UCHAR_MAX
#if FULL_TABLE
      , ['z' + 1 ... UCHAR_MAX] = UCHAR_MAX
#endif
};

unsigned char
get_digit(unsigned char token)
{
#if !FULL_TABLE
	if (token > 'z')
		return UCHAR_MAX;
#endif
	return digit_table[token];
}

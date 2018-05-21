#include "get_digit.h" // declarations
#include "limits.h"    // UCHAR_MAX

#if (UCHAR_MAX <= 255)
#	define FULL_TABLE 1
#else
#	define FULL_TABLE 0
#endif


static const unsigned char digit_table[UCHAR_MAX + 1] = {
        ['0'] = 0,
        ['1'] = 1,
        ['2'] = 2,
        ['3'] = 3,
        ['4'] = 4,
        ['5'] = 5,
        ['6'] = 6,
        ['7'] = 7,
        ['8'] = 8,
        ['9'] = 9,

        ['A'] = 10, ['a'] = 10,
        ['B'] = 11, ['b'] = 11,
        ['C'] = 12, ['c'] = 12,
        ['D'] = 13, ['d'] = 13,
        ['E'] = 14, ['e'] = 14,
        ['F'] = 15, ['f'] = 15,
        ['G'] = 16, ['g'] = 16,
        ['H'] = 17, ['h'] = 17,
        ['I'] = 18, ['i'] = 18,
        ['J'] = 19, ['j'] = 19,
        ['K'] = 20, ['k'] = 20,
        ['L'] = 21, ['l'] = 21,
        ['M'] = 22, ['m'] = 22,
        ['N'] = 23, ['n'] = 23,
        ['O'] = 24, ['o'] = 24,
        ['P'] = 25, ['p'] = 25,
        ['Q'] = 26, ['q'] = 26,
        ['R'] = 27, ['r'] = 27,
        ['S'] = 28, ['s'] = 28,
        ['T'] = 29, ['t'] = 29,
        ['U'] = 30, ['u'] = 30,
        ['V'] = 31, ['v'] = 31,
        ['W'] = 32, ['w'] = 32,
        ['X'] = 33, ['x'] = 33,
        ['Y'] = 34, ['y'] = 34,
        ['Z'] = 35, ['z'] = 35,

        ['\0'	 ... '0' - 1  ] = UCHAR_MAX,
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

#include "convert_base.h" /* convert_base() */
#include "get_digit.h"	  /* get_digit() */
#include <limits.h>	  /* *_MAX */

#define ACC_MAX	ULONG_MAX
typedef unsigned long acc_type;
#if   ((UINT_MAX  * 2) <= ACC_MAX)
#	define WORD_MAX UINT_MAX
	typedef unsigned int   word_type;
#elif ((USHRT_MAX * 2) <= ACC_MAX)
#	define WORD_MAX USHRT_MAX
	typedef unsigned short word_type;
#else
#	define WORD_MAX (ACC_MAX / 2)
	typedef acc_type       word_type;
#endif

static const char token_table[] = {
        '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D',
	'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R',
        'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'
};


int
convert_base(char       *output, unsigned char output_base,
	     const char *input,  unsigned char input_base)
{
	if (*input == '\0') {
		*output = '\0';
		return 0;
	}

	if (input_base > 36)
		return -1;

	const unsigned char *restrict i_ptr = (const unsigned char *) input;

	while (*++i_ptr != '\0')
		; /* start at least significant digit */

	size_t input_length = (i_ptr - input);


	word_type *restrict o_word_ptr = (word_type *) output;

	acc_type o_acc = 0;
	acc_type i_mag  = 1;

	do {
		unsigned char i_digit = get_digit(*--i_ptr);
		if (i_digit >= i_base) {
			return -2; /* input contains out-of-bounds token */
		}
		o_acc += (i_digit * i_mag);
		i_mag *= i_base;
		if (i_mag > WORD_MAX) {
			i_mag	      = 1;
			*o_word_ptr++ = (word_type) (o_acc % WORD_MAX);
			o_acc	     /= WORD_MAX;
		}

		if (o_acc >= WORD_MAX) {
			word_type o_word = o_acc % WORD_MAX;

			o_acc = 1;
			i_mag = 1;
		}

	} while (i_ptr > input);

	uint64_t acc = 0;

	return output_length;


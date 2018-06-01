#include "convert_base.h"   /* convert_base() */
#include "get_digit.h"	    /* get_digit() */
#include "get_max_digits.h" /* get_max_digits() */
#include "add.h"	    /* add() */
#include "multiply.h"	    /* multiply() */
#include <string.h>	    /* memset() */
#include <limits.h>	    /* ULONG_MAX */


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

	if (   (input_base  > 36) || (input_base  < 2)
	    || (output_base > 36) || (output_base < 2))
		return -1;

	unsigned char *restrict	      input_ptr = (unsigned char *) input;
	const unsigned char *restrict input_end = input_ptr;

	while (*++input_end != '\0')
		; /* start at least significant digit */

	/* calculate the maximum size of the output */
	size_t input_length = input_end - input_ptr;
	size_t max_digits   = get_max_digits(input_length,
					     input_base,
					     output_base);
	/* zero out output + terminating NUL */
	(void) memset(output, '\0', max_digits + 1);

	const unsigned long mag_limit = ULONG_MAX
				    / (input_base * (input_base - 1));

	unsigned long input_mag = 1;
	unsigned long acc       = 0;
	do {
		unsigned char input_digit = get_digit(*input_ptr);
		if (input_digit >= input_base) {
			return -2; /* out-of-bounds token */
		}

		input_mag *= input_base;
		acc *= input_base;
		acc += input_digit;
	} while ((++input_ptr < input_end) && (input_mag <= mag_limit));

	unsigned char *restrict output_begin = (unsigned char *) output;
	unsigned char *restrict output_end   = add(output_begin,
						   output_base,
						   acc);

	while (input_ptr < input_end) {
		input_mag = 1;
		acc       = 0;
		do {
			unsigned char input_digit = get_digit(*input_ptr);
			if (input_digit >= input_base) {
				return -2; /* out-of-bounds token */
			}

			input_mag *= input_base;
			acc *= input_base;
			acc += input_digit;
		} while ((++input_ptr < input_end) && (input_mag <= mag_limit));

		output_end = multiply(output_begin,
				      output_base,
				      input_mag,
				      output_end);

		unsigned char *restrict output_ptr = add(output_begin,
							 output_base,
							 acc);
		if (output_ptr > output_end)
			output_end = output_ptr;
	}

	int output_length = (int) (output_end - output_begin);

	/* reverse output, convert to ASCII */
	do {
		char tmp      = token_table[*--output_end];
		*output_end   = token_table[*output_begin];
		*output_begin = tmp;
	} while (output_end > ++output_begin);

	return output_length;
}

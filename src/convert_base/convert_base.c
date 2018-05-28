#include "convert_base.h" /* convert_base() */
#include "get_digit.h"	  /* get_digit() */
#include <limits.h>	  /* UINT_MAX */
#include <string.h>	  /* memset() */

static const char token_table[] = {
        '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D',
	'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R',
        'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'
};


int
convert_base(char       *output, unsigned char output_base,
	     const char *input,  unsigned char input_base)
{
	unsigned int acc_output;
	unsigned int input_mag;
	unsigned int output_digit;
	unsigned int input_token;
	unsigned int input_digit;

	if (*input == '\0') {
		*output = '\0';
		return 0;
	}

	if (   (input_base  > 36) || (input_base  < 2)
	    || (output_base > 36) || (output_base < 2))
		return -1;

	const unsigned int max_input_mag = UINT_MAX / input_base;

	char *restrict		      output_ptr = output;
	const unsigned char *restrict input_ptr  = (const unsigned char *) input;

	while (*++input_ptr != '\0')
		; /* start at least significant digit */

/* 	size_t input_length = (input_ptr - output_ptr); */
/* 	size_t max_output_digits = get_max_digits(input_length, */
/* 						  input_base, */
/* 						  output_base); */
/* 	(void) memset(output, 0, max_output_digits + 1) */ 

	acc_output = 0;
	input_mag  = 1;
	while (1) {
		input_token = *--input_ptr;
		input_digit = get_digit(input_token);
		if (input_digit >= input_base) {
			return -2; /* input contains out-of-bounds token */
		}

		acc_output += (input_digit * input_mag);

		if (((const char *) input_ptr) == input)
			break;

		input_mag *= input_base;
		if (input_mag > max_input_mag) {
			while (1) {
				unsigned int next_mag = input_mag / output_base;
				if (next_mag == 0)
					break;
				input_mag = next_mag;

				output_digit  = acc_output % output_base;
				acc_output   /= output_base;
				*output_ptr++ = token_table[output_digit];
			}
		}
	}

	/* place most significant digits */
	while (acc_output > 0) {
		output_digit  = acc_output % output_base;
		acc_output   /= output_base;
		*output_ptr++ = token_table[output_digit];
	}

	*output_ptr = '\0';

	int output_length = (int) (output_ptr - output);

	/* reverse output */
	do {
		char tmp    = *--output_ptr;
		*output_ptr = *output;
		*output++   = tmp;
	} while (output_ptr > output);

	return output_length;
}

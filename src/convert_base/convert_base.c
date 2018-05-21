#include "convert_base.h"
#include "get_digit.h"

static const char token_table[] = {
        '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D',
	'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R',
        'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'

};


int
convert_base(char       *output, unsigned char output_base,
	     const char *input,  unsigned char input_base)
{
	unsigned char acc_output_digit;
	unsigned char output_digit;
	unsigned char input_token;
	unsigned char input_digit;

	if (input_base > 36)
		return -1;

	if (*input == '\0') {
		*output = '\0';
		return 0;
	}

	char *restrict		      output_ptr = output;
	const unsigned char *restrict input_ptr = (const unsigned char *) input;

	while (*++input_ptr != '\0')
		; /* start at least significant digit */

	acc_output_digit = 0;

	do {
		input_token = *--input_ptr;
		input_digit = get_digit(input_token);
		if (input_digit >= input_base) {
			return -2; /* input contains out-of-bounds token */
		}

		acc_output_digit += input_digit;

		while (acc_output_digit >= output_base) {
			output_digit      = acc_output_digit % output_base;
			acc_output_digit /= output_base;
			*output_ptr++     = token_table[output_digit];
		}
	} while (input_ptr >= (const unsigned char *) input);

	/* place most significant digit */
	*output_ptr++ = token_table[acc_output_digit];
	*output_ptr   = '\0';

	int output_length = (output_ptr - output);

	/* reverse output */
	do {
		char tmp    = *--output_ptr;
		*output_ptr = *output;
		*output++   = tmp;
	} while (output_ptr > output);

	return output_length;
}

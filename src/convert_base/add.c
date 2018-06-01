#include "add.h" /* declarations */


unsigned char *
add(unsigned char *output,
    unsigned long  output_base,
    unsigned long  addend)
{
	/* input_digit*input_base^input_shift
	 *	= x0*output_base^0 + x1*output_base^1 ...
	 */
	unsigned char *output_ptr;

	do {
		unsigned long rem = addend % output_base;
		addend /= output_base; /* shift 1 output digit */

		/* increment starting place */
		output_ptr = output++;

		while (1) {
			rem += *output_ptr;
			if (rem < output_base) {
				*output_ptr++ = rem;
				break;
			}

			*output_ptr++ = (rem - output_base);
			rem = 1; /* carry */
		}
	} while (addend > 0);

	return output_ptr; /* return 1 past last incremented digit */
}

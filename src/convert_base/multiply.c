#include "multiply.h" /* declarations */


unsigned char *
multiply(unsigned char *output,
	 unsigned long	output_base,
	 unsigned long	multiplier,
	 unsigned char *output_end)
{
	unsigned long carry = 0;

	do {
		carry  += *output++ * multiplier;
		*output = carry % output_base;
		carry  /= output_base;
	} while (++output < output_end);

	while (carry > 0) {
		*output++ = carry % output_base;
		carry /= output_base;
	}

	return output; /* return 1 past last digit */
}

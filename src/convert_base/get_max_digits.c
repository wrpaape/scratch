#include "convert_base/get_max_digits.h" /* declaration */
#include <math.h>			 /* log(), ceil() */

size_t
get_max_digits(size_t        input_length,
               unsigned char input_base,
               unsigned char output_base)
{
	/* input_base^input_length = output_base^output_length
	 * log(input_base^input_length) = log(output_base^output_length)
	 * input_length * log(input_base) = output_length * log(output_base)
	 * output_length = input_length * log(input_base) / log(output_base)
	 */
	return (size_t) ceil(
		input_length * log(input_base) / log(output_base)
	);
}

#include "convert_base.h"
#include "get_digit.h"


static inline unsigned char *
convert_base_impl(unsigned char       *restrict output,
		  unsigned char                 output_base,
		  const unsigned char *restrict input,
		  unsigned char                 input_base)
{
	return NULL;
}


char *
convert_base(char       *output, unsigned char output_base,
	     const char *input,  unsigned char input_base)
{
	return (char *) convert_base_impl((unsigned char *) output,
					   output_base,
					   (const unsigned char *) input,
					   input_base);
}

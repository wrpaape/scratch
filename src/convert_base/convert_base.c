#include "convert_base.h"

#include "base_map.h"


static inline unsigned char *
convert_base_impl(unsigned char       *restrict output,
		  unsigned char                 output_base,
		  const unsigned char *restrict input,
		  unsigned char                 input_base)
{

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

#ifndef CONVERT_BASE_MULTIPLY_H
#define CONVERT_BASE_MULTIPLY_H

#ifdef __cplusplus
extern "C" {
#endif

unsigned char *
multiply(unsigned char *output,
         unsigned long	output_base,
         unsigned long	multiplier,
         unsigned char *output_end);

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* ifndef CONVERT_BASE_MULTIPLY_H */

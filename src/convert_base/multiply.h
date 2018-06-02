#ifndef CONVERT_BASE_MULTIPLY_H
#define CONVERT_BASE_MULTIPLY_H

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief         multiplies @p output by @p multiplier
 *
 * @param[in,out] output      byte string of little-endian digits containing the
 *                            result.  Note that this is a string of raw values
 *                            and *not* in ASCII representation.
 * @param[in]     output_base the numerical base of the @p output
 * @param[in]     multiplier  the value to be multiplied by.  To avoid
 *                            arithmetic overflow @p multiplier should be `<=
 *                            ULONG_MAX / (output_base - 1)`
 * @param[in]     output_end  pointer past the most significant digit of @p
 *                            output
 *
 * @returns       if @p multiplier is non-zero, returns a pointer past the most
 *                significant digit of @p output after multiplication has been
 *                applied, otherwise returns @p output_end
 */
unsigned char *
multiply(unsigned char *output,
         unsigned long	output_base,
         unsigned long	multiplier,
         unsigned char *output_end);

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* ifndef CONVERT_BASE_MULTIPLY_H */

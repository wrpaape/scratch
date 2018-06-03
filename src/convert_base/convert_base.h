#ifndef CONVERT_BASE_CONVERT_BASE_H
#define CONVERT_BASE_CONVERT_BASE_H

/**
 * @file
 * @brief header declaring convert_base() used for expressing a number
 *        whose representation is known in one numerical base in an alternative
 *        numerical base
 */

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief      converts an input number represented as a string of ASCII digits
 *             in one base to its equivalent in another base
 *
 * @param[out] output      buffer to contain the result.  Must have room for at
 *                         least `get_max_digits(strlen(input), input_base,
 *                         output_base) + 1` bytes (see get_max_digits()).
 * @param[in]  output_base desired base of the output.  Must be in the range:
 *                         `[2, 36]`.
 * @param[in]  input       NUL-terminated C string of ASCII digits.  Must
 *                         contain characters within the range of valid digits
 *                         defined by @p input_base:
 *                         `[`'`0`'`, ASCII representation of input_base-1]`
 * @param[in]  input_base  base of the @p input.  Must be in the range: `[2,
 *                         36]`.
 *
 * @returns    A non-negative return value indicates a successful conversion
 *             and is equivalent to `strlen(output)`.  A negative return value
 *             indicates one of two failures:  `LONG_MIN` indicates that either
 *             @p input_base or @p output_base are outside the acceptable
 *             limits.  Otherwise, the expression `-return_value-1` can be
 *             used to find the index of the first character of @p input that
 *             does not belong in the range of valid digits defined by @p
 *             input_base.
 */
long
convert_base(char       *output, unsigned char output_base,
             const char *input,  unsigned char input_base);

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* ifndef CONVERT_BASE_CONVERT_BASE_H */

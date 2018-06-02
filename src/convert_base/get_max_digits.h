#ifndef CONVERT_BASE_GET_MAX_DIGITS_H
#define CONVERT_BASE_GET_MAX_DIGITS_H

#include <stddef.h> /* size_t */

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief     used to size the result of convert_base()
 *
 * @details   Given an input number expressed in base @p input_base:
 *
 *            `a0*input_base^0 + a1*input_base^1 ...
 *            a[input_length - 1]*input_base^(input_length - 1)`
 *
 *            get_max_digits() determines the maximum value of `output_length`
 *            if that number where to be expressed in base @p output_base:
 *
 *            `b0*output_base^0 + b1*output_base^1 ...
 *            b[output_length - 1]*output_base^(output_length - 1)`.
 *
 * @param[in] input_length the number of digits used to represent input
 * @param[in] input_base   the numerical base of the input
 * @param[in] output_base  the numerical base of the output
 *
 * @returns   the upper bound of digits in @p output_base required to represent
 *            a number expressed in @p input_length digits of base @p input_base
 */
size_t
get_max_digits(size_t        input_length,
               unsigned char input_base,
               unsigned char output_base);

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* ifndef CONVERT_BASE_GET_MAX_DIGITS_H */

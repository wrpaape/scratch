#ifndef CONVERT_BASE_GET_MAX_DIGITS_H
#define CONVERT_BASE_GET_MAX_DIGITS_H

#include <stddef.h> /* size_t */

#ifdef __cplusplus
extern "C" {
#endif

size_t
get_max_digits(size_t        input_length,
               unsigned char input_base,
               unsigned char output_base);

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* ifndef CONVERT_BASE_GET_MAX_DIGITS_H */

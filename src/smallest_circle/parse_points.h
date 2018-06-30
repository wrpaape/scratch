#ifndef SMALLEST_CIRCLE_PARSE_POINTS_H
#define SMALLEST_CIRCLE_PARSE_POINTS_H

/**
 * @file
 * @brief private header declaring parse_points() used by find_smallest_circle
 */

#ifdef __cplusplus
extern "C" {
#endif

#include <stddef.h> /* size_t */

/**
 * @brief      converts a list of strings
 *
 * @param[out] points consecutive x,y values, must have room for @p count_inputs
 *             x 2 doubles
 * @param[in]  inputs array of NUL-terminated C-strings of the form "<x>,<y>",
 *             where <x> and <y> are in real value representation as defined by
 *             strtod(3)
 * @param[in]  count_inputs length of @p inputs
 *
 * @returns    negative value on success, index of the first error-inducing
 *             input
 */
long
parse_points(double            *points,
             const char **const inputs,
             size_t             count_inputs);

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* ifndef SMALLEST_CIRCLE_PARSE_POINTS_H */

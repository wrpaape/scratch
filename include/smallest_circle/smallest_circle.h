#ifndef SMALLEST_CIRCLE_SMALLEST_CIRCLE_H
#define SMALLEST_CIRCLE_SMALLEST_CIRCLE_H

/**
 * @file
 * @brief header declaring smallest_circle(), used for placing and sizing the
 *        smallest circle about a list of 2D points
 */

#ifdef __cplusplus
extern "C" {
#endif

#include <stddef.h> /* size_t */

/**
 * @brief      for a list of consecutive 2D @p points, solves the location
 *             and size of the smallest enclosing circle
 *
 * @param[out] x      the x-coordinate of the smallest circle
 * @param[out] y      the y-coordinate of the smallest circle
 * @param[out] r      the radius of the smallest circle
 * @param[in]  points a consecutive list of x,y coordinates
 * @param[in]  length number of elements in points, must be a non-zero multiple
 *             of two
 */
void
smallest_circle(double *x, double *y, double *r,
                const double *points,
                size_t        length);

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* ifndef SMALLEST_CIRCLE_SMALLEST_CIRCLE_H */

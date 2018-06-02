#ifndef CONVERT_BASE_ADD_H
#define CONVERT_BASE_ADD_H

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief         adds @p addend into @p output
 *
 * @param[in,out] output      byte string of little-endian digits containing the
 *                            result.  Note that this is a string of raw values
 *                            and *not* in ASCII representation.
 * @param[in]     output_base the numerical base of the @p output
 * @param[in]     addend      the value to be added
 *
 * @returns       pointer past most-significant incremented digit of @p output
 */
unsigned char *
add(unsigned char *output,
    unsigned long  output_base,
    unsigned long  addend);

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* ifndef CONVERT_BASE_ADD_H */

#ifndef CONVERT_BASE_CONVERT_BASE_H
#define CONVERT_BASE_CONVERT_BASE_H

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @param[out] output       NUL-terminated C string
 * @param[in]  output_base the
 * @param[in]  input        NUL-terminated C string
 * @param[in]  input_base
 *
 * @returns    strlen(output) on success or negative if output_base is invalid
 *             or input contains digits outside of the set of valid digits
 *             specified by 'input_base'
 */
long
convert_base(char       *output, unsigned char output_base,
             const char *input,  unsigned char input_base);

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* ifndef CONVERT_BASE_CONVERT_BASE_H */

#ifndef CONVERT_BASE_CONVERT_BASE_H
#define CONVERT_BASE_CONVERT_BASE_H value

/**
 * @param[out] output       NUL-terminated C string 
 * @param[in]  output_base the
 * @param[in]  input        NUL-terminated C string 
 * @param[in]  input_base
 *
 * @returns    output on success or NULL if output_base is invalid or output contains digits
 */
char *
convert_base(char       *output, unsigned char output_base,
             const char *input,  unsigned char input_base);

#endif /* ifndef CONVERT_BASE_CONVERT_BASE_H */

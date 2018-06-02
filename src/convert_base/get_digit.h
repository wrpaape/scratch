#ifndef CONVERT_BASE_GET_DIGIT_H
#define CONVERT_BASE_GET_DIGIT_H

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief     looks up the digit value associated with ASCII @p token
 *
 * @param[in] token an ASCII byte representing a single digit of a number string
 *
 * @returns   the digit value of @p token
 */
unsigned char
get_digit(unsigned char token);

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* ifndef CONVERT_BASE_GET_DIGIT_H */

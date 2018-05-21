#include "gtest/gtest.h" // TEST, ASSERT_*
#include "get_digit.h"   // convert_base()
#include "limits.h"      // UCHAR_MAX

TEST(test_get_digit, mapping_is_correct)
{
    unsigned int token;

    for (token = '\0'; token < '0'; ++token)
        EXPECT_EQ(UCHAR_MAX, get_digit(token));

    EXPECT_EQ(0, get_digit('0'));
    EXPECT_EQ(1, get_digit('1'));
    EXPECT_EQ(2, get_digit('2'));
    EXPECT_EQ(3, get_digit('3'));
    EXPECT_EQ(4, get_digit('4'));
    EXPECT_EQ(5, get_digit('5'));
    EXPECT_EQ(6, get_digit('6'));
    EXPECT_EQ(7, get_digit('7'));
    EXPECT_EQ(8, get_digit('8'));
    EXPECT_EQ(9, get_digit('9'));

    for (token = '9' + 1; token < 'A'; ++token)
        EXPECT_EQ(UCHAR_MAX, get_digit(token));

    EXPECT_EQ(10, get_digit('A'));
    EXPECT_EQ(11, get_digit('B'));
    EXPECT_EQ(12, get_digit('C'));
    EXPECT_EQ(13, get_digit('D'));
    EXPECT_EQ(14, get_digit('E'));
    EXPECT_EQ(15, get_digit('F'));
    EXPECT_EQ(16, get_digit('G'));
    EXPECT_EQ(17, get_digit('H'));
    EXPECT_EQ(18, get_digit('I'));
    EXPECT_EQ(19, get_digit('J'));
    EXPECT_EQ(20, get_digit('K'));
    EXPECT_EQ(21, get_digit('L'));
    EXPECT_EQ(22, get_digit('M'));
    EXPECT_EQ(23, get_digit('N'));
    EXPECT_EQ(24, get_digit('O'));
    EXPECT_EQ(25, get_digit('P'));
    EXPECT_EQ(26, get_digit('Q'));
    EXPECT_EQ(27, get_digit('R'));
    EXPECT_EQ(28, get_digit('S'));
    EXPECT_EQ(29, get_digit('T'));
    EXPECT_EQ(30, get_digit('U'));
    EXPECT_EQ(31, get_digit('V'));
    EXPECT_EQ(32, get_digit('W'));
    EXPECT_EQ(33, get_digit('X'));
    EXPECT_EQ(34, get_digit('Y'));
    EXPECT_EQ(35, get_digit('Z'));

    for (token = 'Z' + 1; token < 'a'; ++token)
        EXPECT_EQ(UCHAR_MAX, get_digit(token));

    EXPECT_EQ(10, get_digit('a'));
    EXPECT_EQ(11, get_digit('b'));
    EXPECT_EQ(12, get_digit('c'));
    EXPECT_EQ(13, get_digit('d'));
    EXPECT_EQ(14, get_digit('e'));
    EXPECT_EQ(15, get_digit('f'));
    EXPECT_EQ(16, get_digit('g'));
    EXPECT_EQ(17, get_digit('h'));
    EXPECT_EQ(18, get_digit('i'));
    EXPECT_EQ(19, get_digit('j'));
    EXPECT_EQ(20, get_digit('k'));
    EXPECT_EQ(21, get_digit('l'));
    EXPECT_EQ(22, get_digit('m'));
    EXPECT_EQ(23, get_digit('n'));
    EXPECT_EQ(24, get_digit('o'));
    EXPECT_EQ(25, get_digit('p'));
    EXPECT_EQ(26, get_digit('q'));
    EXPECT_EQ(27, get_digit('r'));
    EXPECT_EQ(28, get_digit('s'));
    EXPECT_EQ(29, get_digit('t'));
    EXPECT_EQ(30, get_digit('u'));
    EXPECT_EQ(31, get_digit('v'));
    EXPECT_EQ(32, get_digit('w'));
    EXPECT_EQ(33, get_digit('x'));
    EXPECT_EQ(34, get_digit('y'));
    EXPECT_EQ(35, get_digit('z'));

    for (token = 'z' + 1; token <= UCHAR_MAX; ++token)
        EXPECT_EQ(UCHAR_MAX, get_digit(token));
}

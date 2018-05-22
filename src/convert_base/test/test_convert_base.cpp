#include "gtest/gtest.h"  // TEST, ASSERT_*
#include "convert_base.h" // convert_base()
#include <cstring>        // strlen
#include <climits>        // UCHAR_MAX


TEST(test_convert_base, base_validity)
{
    char        output[128] = { '\0' };
    const char *input;
    unsigned int input_base;

    input = "0000000000";
    EXPECT_LT(convert_base(output, 10,
                           input,   0), 0);

    for (input_base = 1; input_base <= 36; ++input_base)
        EXPECT_GE(convert_base(output, 10,
                               input,   input_base), 0);

    for (input_base = 36 + 1; input_base <= UCHAR_MAX; ++input_base)
        EXPECT_LT(convert_base(output, 10,
                               input,   input_base), 0);
}


TEST(test_convert_base, empty)
{
    char output[128] = { '\0' };

    for (unsigned int input_base = 1; input_base <= 36; ++input_base) {
        ASSERT_EQ(0, convert_base(output, 10,
                                  "",     input_base));
        ASSERT_STREQ("", output);
    }
}


TEST(test_convert_base, no_base_change)
{
    char        output[128] = { '\0' };
    int         output_length;
    const char *input;

    input         = "0";
    output_length = convert_base(output, 1,
                                 input,  1);
    ASSERT_EQ(strlen(input), output_length);
    ASSERT_STREQ(input, output);

    input         = "10";
    output_length = convert_base(output, 2,
                                 input,  2);
    ASSERT_EQ(strlen(input), output_length);
    ASSERT_STREQ(input, output);

    input         = "12345670";
    output_length = convert_base(output, 8,
                                 input,  8);
    ASSERT_EQ(strlen(input), output_length);
    ASSERT_STREQ(input, output);

    input         = "1234567890";
    output_length = convert_base(output, 10,
                                 input,  10);
    ASSERT_EQ(strlen(input), output_length);
    ASSERT_STREQ(input, output);

    input         = "1234567890ABCDEF";
    output_length = convert_base(output, 16,
                                 input,  16);
    ASSERT_EQ(strlen(input), output_length);
    ASSERT_STRCASEEQ(input, output);

    input         = "1234567890ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    output_length = convert_base(output, 36,
                                 input,  36);
    ASSERT_EQ(strlen(input), output_length);
    ASSERT_STRCASEEQ(input, output);
}


TEST(test_convert_base, from_unary)
{
    char        output[128]     = { '\0' };
    const char *input           = "0000000000";
    const char *expected_output = "10";

    ASSERT_EQ(strlen(expected_output),
              convert_base(output, 10,
                           input,  1));
    ASSERT_STREQ(expected_output, output);
}

TEST(test_convert_base, to_unary)
{
    char        output[128] = { '\0' };
    const char *input       = "120";
    std::string expected_output('0', 120);

    ASSERT_EQ(expected_output.length(),
              convert_base(output, 1,
                           input,  10));
    ASSERT_STREQ(expected_output.c_str(), output);
}


TEST(test_convert_base, from_binary)
{
    char        output[128]     = { '\0' };
    const char *input           = "1001001100101100000001011010010";
    const char *expected_output = "1234567890";

    ASSERT_EQ(strlen(expected_output),
              convert_base(output, 10,
                           input,  2));
    ASSERT_STREQ(expected_output, output);
}

TEST(test_convert_base, to_binary)
{
    char        output[128]     = { '\0' };
    const char *input           = "99999999999999999999";
    const char *expected_output = "1010110101111000111010111100010110101100011000011111111111111111111";

    ASSERT_EQ(strlen(expected_output),
              convert_base(output, 2,
                           input,  10));
    ASSERT_STREQ(expected_output, output);
}


TEST(test_convert_base, from_octal)
{
    char        output[128]     = { '\0' };
    const char *input           = "1234567";
    const char *expected_output = "342391";

    ASSERT_EQ(strlen(expected_output),
              convert_base(output, 10,
                           input,  8));
    ASSERT_STREQ(expected_output, output);
}

TEST(test_convert_base, to_octal)
{
    char        output[128]     = { '\0' };
    const char *input           = "11111111111111";
    const char *expected_output = "37777";

    ASSERT_EQ(strlen(expected_output),
              convert_base(output, 8,
                           input,  2));
    ASSERT_STREQ(expected_output, output);
}


TEST(test_convert_base, from_decimal)
{
    char        output[128]     = { '\0' };
    const char *input           = "340282366920938463463374607431768211455";
    std::string expected_output('1', 127);

    ASSERT_EQ(expected_output.length(),
              convert_base(output,  2,
                           input,  10));
    ASSERT_STREQ(expected_output.c_str(), output);
}

TEST(test_convert_base, to_decimal)
{
    char        output[128]     = { '\0' };
    const char *input           = "DEADBEEF";
    const char *expected_output = "3735928559";

    ASSERT_EQ(strlen(expected_output),
              convert_base(output, 10,
                           input,   8));
    ASSERT_STREQ(expected_output, output);
}


TEST(test_convert_base, from_hexidecimal)
{
    char        output[128]     = { '\0' };
    const char *input           = "CAFEBABE";
    const char *expected_output = "3405691582";

    ASSERT_EQ(strlen(expected_output),
              convert_base(output, 10,
                           input,  16));
    ASSERT_STRCASEEQ(expected_output, output);
}

TEST(test_convert_base, to_hexidecimal)
{
    char        output[128]     = { '\0' };
    const char *input           = "1300130465";
    const char *expected_output = "B00B135";

    ASSERT_EQ(strlen(expected_output),
              convert_base(output, 16,
                           input,   8));
    ASSERT_STREQ(expected_output, output);
}


TEST(test_convert_base, from_max_base)
{
    char        output[128]     = { '\0' };
    const char *input           = "ZzToP";
    const char *expected_output = "60457993";

    ASSERT_EQ(strlen(expected_output),
              convert_base(output, 10,
                           input,  36));
    ASSERT_STREQ(expected_output, output);
}

TEST(test_convert_base, to_max_base)
{
    char        output[128]     = { '\0' };
    const char *input           = "2296071952654";
    const char *expected_output = "tastyham";

    ASSERT_EQ(strlen(expected_output),
              convert_base(output, 36,
                           input,  10));
    ASSERT_STRCASEEQ(expected_output, output);
}

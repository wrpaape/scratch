#include "gtest/gtest.h"  // TEST, ASSERT_*
#include "multiply.h"     // multiply()
#include "make_array.hpp" // make_array
#include <type_traits>    // std::remove_const_t


TEST(test_multiply, binary)
{
    // 0b10110010110011001000 == 732360
    const auto expected_output = make_array<unsigned char>(
        0, 0, 0, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 1, 0, 0, 1, 1, 0, 1
    );
    // 0b101100111000 == 2872
    std::remove_const_t<decltype(expected_output)> output = {
        0, 0, 0, 1, 1, 1, 0, 0, 1, 1, 0, 1
    };

    unsigned char *output_end = multiply(output.data(),
                                         2,
                                         255,
                                         output.data() + output.size());

    EXPECT_EQ(expected_output.size(), output_end - output.data());
    EXPECT_EQ(expected_output, output);
}


TEST(test_multiply, decimal)
{
    // 800858008580085800858008580085800858008580085800858008580085800858008580085
    const auto expected_output = make_array<unsigned char>(
        5, 8, 0, 0, 8, 5, 8, 0, 0, 8, 5, 8, 0, 0, 8, 5, 8, 0, 0, 8, 5, 8, 0, 0,
        8, 5, 8, 0, 0, 8, 5, 8, 0, 0, 8, 5, 8, 0, 0, 8, 5, 8, 0, 0, 8, 5, 8, 0,
        0, 8, 5, 8, 0, 0, 8, 5, 8, 0, 0, 8, 5, 8, 0, 0, 8, 5, 8, 0, 0, 8, 5, 8,
        0, 0, 8
    );
    // 10000100001000010000100001000010000100001000010000100001000010000100001
    std::remove_const_t<decltype(expected_output)> output = {
        1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0,
        0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0,
        0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1
    };

    unsigned char *output_end = multiply(output.data(),
                                         10,
                                         80085,
                                         output.data() + output.size());

    EXPECT_EQ(expected_output.size(), output_end - output.data());
    EXPECT_EQ(expected_output, output);
}


TEST(test_multiply, max_base)
{
    // zanzibar00000 == 167247261787668655104
    const auto expected_output = make_array<unsigned char>(
        0, 0, 0, 0, 0, 27, 10, 11, 18, 35, 23, 10, 35
    );
    // zanzibar == 2765963929779
    std::remove_const_t<decltype(expected_output)> output = {
        27, 10, 11, 18, 35, 23, 10, 35
    };

    unsigned char *output_end = multiply(output.data(),
                                         36,
                                         36ul * 36ul * 36ul * 36ul * 36ul,
                                         output.data() + output.size());

    EXPECT_EQ(expected_output.size(), output_end - output.data());
    EXPECT_EQ(expected_output, output);
}

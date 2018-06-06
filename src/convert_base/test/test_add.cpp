#include "gtest/gtest.h"       // TEST, ASSERT_*
#include "add.h"               // add()
#include "test/make_array.hpp" // make_array
#include <type_traits>         // std::remove_const_t


TEST(test_add, add_zero)
{
    // 1234567890
    const auto expected_output = make_array<unsigned char>(
        0, 9, 8, 7, 6, 5, 4, 3, 2, 1
    );

    std::remove_const_t<decltype(expected_output)> output = expected_output;

    unsigned char *output_end = add(output.data(), 10, 0);

    EXPECT_EQ(1, output_end - output.data());
    EXPECT_EQ(expected_output, output);
}


TEST(test_add, binary)
{
    // 0b11000001000011 == 12355
    const auto expected_output = make_array<unsigned char>(
        1, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 1
    );
    // 0b1010 == 10
    std::remove_const_t<decltype(expected_output)> output = {
        0, 1, 0, 1
    };

    unsigned char *output_end = add(output.data(), 2, 12345);

    EXPECT_EQ(expected_output.size(), output_end - output.data());
    EXPECT_EQ(expected_output, output);
}


TEST(test_add, decimal)
{
    // 130000000
    const auto expected_output = make_array<unsigned char>(
        0, 0, 0, 0, 0, 0, 0, 0, 3, 1
    );
    // 1234567890
    std::remove_const_t<decltype(expected_output)> output = {
        0, 9, 8, 7, 6, 5, 4, 3, 2, 1
    };

    unsigned char *output_end = add(output.data(), 10, 65432110ul);

    EXPECT_EQ(&output.back(), output_end);
    EXPECT_EQ(expected_output, output);
}

TEST(test_add, max_base)
{
    // iamking == 39824652652
    const auto expected_output = make_array<unsigned char>(
        16, 23, 18, 20, 22, 10, 18
    );
    // iamkind == 39824652649
    std::remove_const_t<decltype(expected_output)> output = {
        13, 23, 18, 20, 22, 10, 18
    };

    unsigned char *output_end = add(output.data(), 36, 3);

    EXPECT_EQ(&output[1], output_end);
    EXPECT_EQ(expected_output, output);
}

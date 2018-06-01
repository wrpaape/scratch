#include "gtest/gtest.h"  // TEST, ASSERT_*
#include "add.h"          // add()
#include "make_array.hpp" // make_array
#include <type_traits>    // std::remove_const_t


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

    output_end = add(output.data(), 2, 0);

    EXPECT_EQ(1, output_end - output.data());
    EXPECT_EQ(expected_output, output);
}

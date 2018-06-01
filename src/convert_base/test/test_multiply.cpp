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

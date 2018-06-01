#include "gtest/gtest.h"    // TEST, ASSERT_*
#include "get_max_digits.h" // get_max_digits()
#include <cstring>          // strlen()

TEST(test_get_max_digits, safe_estimation)
{
    const size_t input_length = strlen("99999999999999999999");

    EXPECT_GE(
        get_max_digits(input_length, 10, 2),
        strlen("1010110101111000111010111100010110101100011000011111111111111111111")
    );
    EXPECT_GE(
        get_max_digits(input_length, 10, 3),
        strlen("220200020122120112010222022122002000100200")
    );
    EXPECT_GE(
        get_max_digits(input_length, 10, 4),
        strlen("1112233013113202311203003333333333")
    );
    EXPECT_GE(
        get_max_digits(input_length, 10, 5),
        strlen("23202330044444444444444444444")
    );
    EXPECT_GE(
        get_max_digits(input_length, 10, 6),
        strlen("33034304013023440042054543")
    );
    EXPECT_GE(
        get_max_digits(input_length, 10, 7),
        strlen("344015313561621001452561")
    );
    EXPECT_GE(
        get_max_digits(input_length, 10, 8),
        strlen("12657072742654303777777")
    );
    EXPECT_GE(
        get_max_digits(input_length, 10, 9),
        strlen("820218515128278060320")
    );
    EXPECT_GE(
        get_max_digits(input_length, 10, 11),
        strlen("16a9322885328081a120")
    );
    EXPECT_GE(
        get_max_digits(input_length, 10, 12),
        strlen("390a66958a9464aa453")
    );
    EXPECT_GE(
        get_max_digits(input_length, 10, 13),
        strlen("b7388131b304451098")
    );
    EXPECT_GE(
        get_max_digits(input_length, 10, 14),
        strlen("33cb3bb449c2a91331")
    );
    EXPECT_GE(
        get_max_digits(input_length, 10, 15),
        strlen("1035749e25953d9969")
    );
    EXPECT_GE(
        get_max_digits(input_length, 10, 16),
        strlen("56bc75e2d630fffff")
    );
    EXPECT_GE(
        get_max_digits(input_length, 10, 17),
        strlen("20ff5dab9g7f47383")
    );
    EXPECT_GE(
        get_max_digits(input_length, 10, 18),
        strlen("eee706h921ebb559")
    );
    EXPECT_GE(
        get_max_digits(input_length, 10, 19),
        strlen("6b2i1gcaddd4ga44")
    );
    EXPECT_GE(
        get_max_digits(input_length, 10, 20),
        strlen("310e14jjjjjjjjjj")
    );
    EXPECT_GE(
        get_max_digits(input_length, 10, 21),
        strlen("19h7djcjj8f750df")
    );
    EXPECT_GE(
        get_max_digits(input_length, 10, 22),
        strlen("g1d1d41kh0d406b")
    );
    EXPECT_GE(
        get_max_digits(input_length, 10, 23),
        strlen("8e93h381mich182")
    );
    EXPECT_GE(
        get_max_digits(input_length, 10, 24),
        strlen("4i24imni329g72f")
    );
    EXPECT_GE(
        get_max_digits(input_length, 10, 25),
        strlen("2h2i0oooooooooo")
    );
    EXPECT_GE(
        get_max_digits(input_length, 10, 26),
        strlen("1e7na9ijd1jl6hl")
    );
    EXPECT_GE(
        get_max_digits(input_length, 10, 27),
        strlen("oi6hfe3q8h209i")
    );
    EXPECT_GE(
        get_max_digits(input_length, 10, 28),
        strlen("fahhbc826cmp8f")
    );
    EXPECT_GE(
        get_max_digits(input_length, 10, 29),
        strlen("9liashaimceq06")
    );
    EXPECT_GE(
        get_max_digits(input_length, 10, 30),
        strlen("6850qa888gnl39")
    );
    EXPECT_GE(
        get_max_digits(input_length, 10, 31),
        strlen("42tlg9if3mmgio")
    );
    EXPECT_GE(
        get_max_digits(input_length, 10, 32),
        strlen("2mnhqu5lhgvvvv")
    );
    EXPECT_GE(
        get_max_digits(input_length, 10, 33),
        strlen("1qvi340qbei9u0")
    );
    EXPECT_GE(
        get_max_digits(input_length, 10, 34),
        strlen("17uopd8lcnm543")
    );
    EXPECT_GE(
        get_max_digits(input_length, 10, 35),
        strlen("tkpxpiyscfert")
    );
    EXPECT_GE(
        get_max_digits(input_length, 10, 36),
        strlen("l3r41ifs0q5tr")
    );
}

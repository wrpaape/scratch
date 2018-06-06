#include "convert_base/convert_base.h"   // convert_base()
#include "convert_base/get_max_digits.h" // get_max_digits()
#include <limits>                        // std::numeric_limits
#include <cstdlib>                       // std::[exit|strtol]
#include <cstring>                       // std::strlen
#include <iostream>                      // std::[cout|cerr]


[[noreturn]] static inline void
usage(const char *program_name)
{
    std::cerr << "usage:"
              << "\n\t" << program_name << " <number> <base_number> <base_desired>"
              << std::endl;
    std::exit(1);
}

[[noreturn]] inline static void
invalid_base(const char *which,
             const char *base,
             int         exit_code)
{
    std::cerr << "error: invalid base_" << which << " (" << base << ") outside"
                 " of acceptable range of values [2, 36]"
              << std::endl;
    std::exit(exit_code);
}

[[noreturn]] inline static void
invalid_number(const char   *number,
               unsigned char base_number,
               std::size_t   index,
               std::size_t   length_number)
{
    std::size_t index_p1      = index + 1;

    std::cerr << "error: number contains digit outside of specified base ("
              << static_cast<unsigned int>(base_number) << ") at index "
              << index
              << "\n"
                 "\n\t";
    std::cerr.write(number, index) << ">>";
    std::cerr.put(number[index])   << "<<";
    std::cerr.write(number + index_p1, length_number - index_p1) << std::endl;
    std::exit(4);
}

[[noreturn]] inline static void
unexpected_invalid_base()
{
    std::cerr << "error: unexpected invalid base_number or base_desired"
              << std::endl;
    std::exit(5);
}


static unsigned char
parse_base(const char *which, char *argv[], int base_index)
{
    const char *base = argv[base_index];
    long parsed      = std::strtol(base, nullptr, 10);
    if ((parsed < 2) || (parsed > 36))
        invalid_base(which, base, base_index);

    return static_cast<unsigned char>(parsed);
}


int
main(int argc, char *argv[])
{
    if (argc != 4)
        usage(argv[0]);

    const char   *number       = argv[1];
    unsigned char base_number  = parse_base("number",  argv, 2);
    unsigned char base_desired = parse_base("desired", argv, 3);

    std::size_t length_number     = std::strlen(number);
    std::size_t max_length_output = get_max_digits(length_number,
                                                   base_number,
                                                   base_desired);
    std::string output(max_length_output, '\0');

    long status = convert_base(output.data(), base_desired,
                               number,        base_number);

    if (status >= 0) {
        output.resize(status);
        std::cout << output << std::endl;
        return 0;
    }

    if (status != std::numeric_limits<long>::min())
        invalid_number(number, base_number, -status - 1, length_number);
    else
        unexpected_invalid_base();
}

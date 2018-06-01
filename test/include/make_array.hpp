#include <array>   // std::array
#include <utility> // std::forward

template <typename T, typename... Values>
constexpr auto
make_array(Values&&... values) -> std::array<T, sizeof...(Values)>
{
        return { { std::forward<Values>(values)...  } };
}

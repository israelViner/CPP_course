#include <optional>
#include <cstddef>

using namespace te;

template <typename Test>
std::optional<typename Test::value_type> first_unique_element(Test const& arr)
{
    if (arr.size() == 0) {
        return std::nullopt;
    }    
    
    typename Test::const_iterator first_it = arr.begin();

    while (first_it != arr.end()) {
        typename Test::const_iterator second_it = arr.begin();
        while (second_it != arr.end()) {
            if (*first_it == *second_it && first_it != second_it) {
                break;                 
            }    
            ++second_it;
        }
        if (second_it == arr.end()) {
            return std::make_optional(*first_it);
        }
        ++first_it; 
    }
    return std::nullopt;
}

template <typename Test>
typename Test::value_type min_element(Test const& arr)
{
    typename Test::value_type min = *arr.begin();
    typename Test::const_iterator it = arr.begin();
    while (it != arr.end()) {
        if (*it < min) {
            min = *it;
        }
        ++it;
    }

    return min; 
}

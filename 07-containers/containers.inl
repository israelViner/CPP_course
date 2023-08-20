#include <cstddef> // std::size_t
#include <array> // std::array
#include <optional> // std::optional
#include <unordered_map> // std::unordered_map
#include <algorithm>


namespace tf {

template <typename Test>
std::optional<typename Test::iterator> find_duplicates(Test& arr)
{
    std::unordered_map<typename Test::value_type, int> frequency_map;

    typename Test::iterator start_it = arr.begin();
    typename Test::iterator end_it = arr.end();

    while (start_it != end_it) {
        if (frequency_map.count(*start_it)) {
            return std::make_optional(start_it);
        }
        frequency_map[*start_it] = 1;
        ++start_it; 
    }
    return std::nullopt;
}

template <typename Test>
bool is_sorted(Test& arr)
{
    if (arr.size() == 0) {
        return true;
    }

    typename Test::iterator it = arr.begin();
    typename Test::iterator bound_it = arr.begin();
    ++bound_it;
    while (bound_it != arr.end()) {
        if (*it > *(bound_it)) {
            return false;
        }
        ++it;
        ++bound_it;
    }
    return true;
}

template <typename Test, typename Condition>
bool is_sorted(Test& arr, Condition function)
{
    typename Test::iterator it = arr.begin();
    typename Test::iterator bound_it = arr.begin();
    ++bound_it;
    while (bound_it != arr.end()) {
        if (function(*it ,*(bound_it))) {
            return false;
        }
        ++it;
        ++bound_it;
    }
    return true;
}

template <typename Test>
bool is_reverse_sorted(Test const& arr)
{
    if (arr.size() == 0) {
        return true;
    }
    
    typename Test::const_iterator it = arr.begin();
    while (it != arr.end() - 1) {
        if (*it < *(it + 1)) {
            return false;
        }
        ++it;
    }
    return true;
}

template <typename Test>
std::optional<typename Test::value_type> first_unique_element(Test& arr)
{
    std::unordered_map<typename Test::value_type, int> frequency_map;

    typename Test::iterator start_it = arr.begin();
    typename Test::iterator end_it = arr.end();

    while (start_it != end_it) {
        if (frequency_map.count(*start_it)) {
            frequency_map[*start_it] += 1;            
        }
        else {
            frequency_map[*start_it] = 1;
        }
        ++start_it; 
    }
    start_it = arr.begin();
    while (start_it != end_it) {
        if (frequency_map[*start_it] == 1) {
            return std::make_optional(*start_it);
        }
        ++start_it;
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

} //size_t namespace con

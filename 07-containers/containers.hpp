#ifndef CONTAINERS_H
#define CONTAINERS_H

#include <cstddef> // std::size_t
#include <array> // std::array
#include <optional> // std::optional

namespace tf {

template <typename Test>
std::optional<typename Test::iterator> find_duplicates(Test& arr);

template <typename Test, typename Condition>
bool is_sorted(Test& arr, Condition function);

template <typename Test>
bool is_sorted(Test& arr);

template <typename Test>
bool is_reverse_sorted(Test const& arr);

template <typename Test>
std::optional<typename Test::value_type> first_unique_element(Test& arr);

template <typename Test>
typename Test::value_type min_element(Test const& arr);


} // namsepace te

#include "containers.inl"

#endif


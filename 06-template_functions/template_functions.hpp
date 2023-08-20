#ifndef TEMPLATE_FUNCTIONS_H
#define TEMPLATE_FUNCTIONS_H

#include <optional>
#include <cstddef>

namespace te {

template <typename Test>
std::optional<typename Test::value_type> first_unique_element(Test const& arr);

template <typename Test>
typename Test::value_type min_element(Test const& arr);

#include "template_functions.inl"

} // namsepace te

#endif


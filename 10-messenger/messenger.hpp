#ifndef MESSENGER_H
#define MESSENGER_H

#include <string>
#include <iostream>
#include "transform.hpp"
#include "input.hpp"
#include "output.hpp"


namespace st {

Output& string_transform(Input& in, Transform const& tr, Output& os);

} // namespace st

#endif
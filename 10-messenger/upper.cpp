#include <string>
#include "upper.hpp"

namespace st {

void Upper::transform(std::string& str) const
{
    auto it = str.begin();
    auto end_it = str.end();
    while (it != end_it) {
        if (*it >= 97 && *it <= 122) {
            *it -= 32;
        }
        ++it;
    }
}

} // namespace st
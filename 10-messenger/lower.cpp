#include <string>
#include "lower.hpp"

namespace st {

void Lower::transform(std::string& str) const
{
    auto it = str.begin();
    auto end_it = str.end();
    while (it != end_it) {
        if (*it >= 65 && *it <= 90) {
            *it += 32;
        }
        ++it;
    }
}

} // namespace st
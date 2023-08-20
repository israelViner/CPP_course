#include <iostream>
#include <string>
#include "atbash.hpp"

namespace st {

void Atbash::transform(std::string& str) const
{
    auto it = str.begin();
    auto end_it = str.end();

    while (it != end_it) {
        if (*it >= 97 && *it <= 122) {
            *it = 'z' - (*it - 'a');
        } else if (*it >= 65 && *it <= 90) {           
           *it = 'Z' - (*it - 'A');      
        }
        ++it;
    }
}

} // namespace st

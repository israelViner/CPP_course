#include <string>
#include "encryption.hpp"

namespace st {

void Encryption::transform(std::string& str) const
{
    auto it = str.begin();
    auto end_it = str.end();

    while (it != end_it) {
        if (*it >= 97 && *it <= 122) {
            *it = (*it + m_jmp - 'a') % 26 + 'a';
        }
        if (*it >= 65 && *it <= 90) {           
           *it = (*it + m_jmp -'A') % 26 + 'A';
        }
        ++it;
    }
}

} // namespace st
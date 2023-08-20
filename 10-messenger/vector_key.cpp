#include <iostream>
#include <string>
#include "vector_key.hpp"

namespace st {

VectorKey::VectorKey(std::string const& key)
{
    auto it = key.begin();
    auto end_it = key.end(); 
    
    while (it != end_it) {
        if (*it >= 'a' && *it <= 'z') {
            m_vector.push_back((*it - 'a') % 26);
        }
        if (*it >= 'A' && *it <= 'A') {
            m_vector.push_back((*it - 'A') % 26);
        }
        if (*it >= '0' && *it <= '9') {
            m_vector.push_back((*it - '0') % 26);
        }
        ++it;
    }
}


void VectorKey::transform(std::string& str) const
{
    auto it = str.begin();
    auto end_it = str.end();
    auto m_it = m_vector.begin();
    auto end_m_it = m_vector.end();

    while (it != end_it) {
        if (*it >= 'a' && *it <= 'z') {
            *it = (*it + *m_it - 'a') % 26 + 'a';
        }
        if (*it >= 'A' && *it <= 'Z') {           
           *it = (*it + *m_it -'A') % 26 + 'A';
        }
        ++it;
        ++m_it;
        if (m_it == end_m_it) {
            m_it = m_vector.begin();
        }
    }
}

} // namespace st

#ifndef STRING_H
#define STRING_H

#include <string>
#include "input.hpp"

namespace st {

class InString: public Input 
{
public:
    InString(std::string& str) : m_str(str) {}
    std::string& get_string() override { return m_str; } 

private:
    std::string m_str;
};

}

#endif
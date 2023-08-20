#ifndef CIN_H
#define CIN_H

#include <string>
#include <iostream>
#include "input.hpp"

namespace st {

class Cin: public Input 
{
public:
    Cin() { std::getline(std::cin, m_str); }
    std::string& get_string() override { return m_str; } 

private:
    std::string m_str;
};

}

#endif
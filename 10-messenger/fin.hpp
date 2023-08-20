#ifndef FIN_H
#define FIN_H

#include <string>
#include <iostream>
#include <fstream>
#include "input.hpp"

namespace st {

class Fin: public Input 
{
public:
    Fin(std::string& st) { std::ifstream file(st); std::getline(file, m_str, '.'); }
    std::string& get_string() override { return m_str; } 

private:
    std::string m_str;
};

}

#endif
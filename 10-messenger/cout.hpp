#ifndef COUT_H
#define COUT_H

#include <string>
#include <iostream>
#include "output.hpp"

namespace st {

class Cout: public Output 
{
public:
    Cout() = default;
    void output(std::string const& str) override { std::cout << str << std::endl; } 
};

}

#endif
#ifndef ONPUT_H
#define ONPUT_H

#include <iostream>

namespace st {

class Output 
{
public:
    virtual ~Output() = default;
    virtual void output(std::string const& str) = 0; 
};

}

#endif
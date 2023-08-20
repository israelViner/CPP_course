#ifndef ATBASH_H
#define ATBASH_H

#include <string>
#include <iostream>
#include <limits>
#include "transform.hpp"

namespace st {

class Atbash: public Transform
{
public:
    void transform(std::string& str) const override;
}; 

} // namespace st

#endif
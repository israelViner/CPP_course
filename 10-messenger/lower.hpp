#ifndef LOWER_H
#define LOWER_H

#include <string>
#include "transform.hpp"

namespace st {

class Lower: public Transform
{
public:
    void transform(std::string& str) const override; 
};

} // namespace st

#endif
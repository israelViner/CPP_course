#ifndef UPPER_H
#define UPPER_H

#include <string>
#include "transform.hpp"

namespace st {

class Upper: public Transform
{
public:
    void transform(std::string& str) const override;
}; 

} // namespace st

#endif
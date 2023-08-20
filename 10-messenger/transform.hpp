#ifndef TRANSFORM_H
#define TRANSFORM_H

#include <string>

namespace st {

class Transform 
{
public:
    virtual ~Transform() = default;

    virtual void transform(std::string& str) const = 0;
};

} // namespace st

#endif
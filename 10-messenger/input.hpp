#ifndef INPUT_H
#define INPUT_H

#include <string>

namespace st {

class Input 
{
public:
    virtual ~Input() = default;
    virtual std::string& get_string() = 0; 
};

}

#endif

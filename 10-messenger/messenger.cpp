#include <string>
#include <iostream>
#include "transform.hpp"
#include "messenger.hpp"
#include "input.hpp"

namespace st {

Output& string_transform(Input& in, Transform const& tr,  Output& os)
{
    std::string str = in.get_string();    
    tr.transform(str);   
    os.output(str);
    return os;
}

} // namespace st

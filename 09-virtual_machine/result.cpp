#include <string> // std::string
#include <vector> // std::vector 
#include <iostream>
#include "result.hpp"

namespace vm {

std::string translate_result(Result const& res, std::vector<std::string> const& masseges)
{
    switch (res)
    {
    case Result::SUCCESS: return masseges[0];
    case Result::MISSING_ELEMENTS : return masseges[1];
    case Result::DIVIDING_BY_ZERO: return masseges[2];
    case Result::END_OF_VECTOR: return masseges[3];
    case Result::EMPTY_VECTOR: return masseges[4];
    case Result::WRONG_COMMAND: return masseges[5];
    case Result::EMPTY_CALL_STACK: return masseges[6];
    case Result::WRONG_INDEX: return masseges[7];   
    
    default: return nullptr;
    }
}

void massege(RunResult const& res, std::vector<std::string> const& masseges)
{
    if (res.m_ok) {
        std::cout << "\n" << masseges[0];
    } else {
        std::cout << "\n" << masseges[static_cast<int32_t>(res.m_res)];
        std::cout << "\nThe error made in index: " << res.m_index << std::endl;
    }

}


} // namespace vm
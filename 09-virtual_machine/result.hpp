#ifndef RESULT_H
#define RESULT_H

#include <cstdint> // int8_t
#include <string> // std::string 

namespace vm {

enum class Result: int8_t 
{
    SUCCESS,
    MISSING_ELEMENTS,
    DIVIDING_BY_ZERO,
    END_OF_VECTOR,
    EMPTY_VECTOR,
    WRONG_COMMAND,
    EMPTY_CALL_STACK,
    WRONG_INDEX        
};

struct RunResult {
    bool m_ok;
    Result m_res;
    int32_t m_index;

    RunResult(bool ok, Result res, int32_t index) : m_ok(ok), m_res(res), m_index(index) {}
};

std::string translate_result(Result const& res, std::vector<std::string> const& masseges);
void massege(RunResult const& res, std::vector<std::string> const& masseges);

}

#endif
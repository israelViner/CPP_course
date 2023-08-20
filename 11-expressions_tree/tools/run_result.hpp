#ifndef RUN_RESULT_H
#define RUN_RESULT_H

#include <cstddef>
#include "token.hpp"

namespace et {

enum class Result : int8_t
{
    Success,    
    EmptyString,
    TwoOperatorsInRow,
    TwoNumbersInRow,
    InvalidChar,
    DivByZero,
    OperatorInLastIndex,
    OperatorInFirstIndex,
    BracketsEndWithoutStart,
    BracketsStartWithoutEnd
};

struct CompileResult
{
    Result m_status;
    size_t m_index;

    CompileResult() : m_status(Result::Success), m_index(0) {}
    CompileResult(Result status, size_t index) : m_status(status), m_index(index) {}
};

} // namespace et

#endif
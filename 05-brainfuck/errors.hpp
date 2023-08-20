#ifndef ERRORS_H
#define ERRORS_H

#include <cstdint>

namespace bf {

enum class Error: int8_t 
{
    Succeeded,
    OutOfMemory,
    InputError, 
    UnmatchedBracketsError,
    OutputError
};
   
}

#endif
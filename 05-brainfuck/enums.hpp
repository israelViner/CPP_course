#ifndef ENUMS_H
#define ENUMS_H

#include <cstdint>

namespace bf {

enum class OpCode: int8_t 
{
    NoOp,
    Left,
    Right,
    Increment,
    Decrement,
    Write,
    Read,
    LoopBegin,
    LoopEnd,
    Halt
};

}

#endif

#ifndef OPCODES_H
#define OPCODES_H

#include <cstdint> // int32_t

namespace vm {

enum class OpCode: int32_t 
{
    ADD,
    SUB,
    MUL,
    DIV,
    POP,
    PUSH,
    DUP,
    SWAP,
    PRINT,
    PRINTC,    
    INC,
    DEC,
    JMP,
    JZ,
    JNZ,
    CALL,
    RET,
    NOP,
    HALT,
};

}

#endif
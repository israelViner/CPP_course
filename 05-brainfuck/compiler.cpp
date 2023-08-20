#include <cstring>
#include "compiler.hpp"

namespace bf {
    
static OpCode translate_command(char c)
{
    switch (c)
    {
    case '<':
        return OpCode::Left;
       
    case '>':
        return OpCode::Right;
       
    case '+':
        return bf::OpCode::Increment;
       
    case '-':
        return bf::OpCode::Decrement;
       
    case (','):
        return bf::OpCode::Write;
        
    case ('.'):
        return bf::OpCode::Read;
        
    case ('['):
        return bf::OpCode::LoopBegin;
        
    case (']'):
        return bf::OpCode::LoopEnd;
        break;
    
    default:
        return bf::OpCode::NoOp;
    }
}

Code translate(const char *commands) 
{
    size_t size = ::strlen(commands) + 1;

    bf::Code code(size);
    
    for (size_t i = 0; i < size-1; ++i) {
        OpCode op = translate_command(commands[i]);
        code.set_value(op, i);
    }
    
    code.set_value(OpCode::Halt, size);
    
    return code;
}

}
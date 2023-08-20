#include "brainfuck.hpp"
#include "iostream"
#include "cassert"

using namespace bf;

Brainfuck::Brainfuck(Code commands)
    : m_bf_memory()
    , m_code(commands)
{
}

Brainfuck::Brainfuck(const Brainfuck& brain)
    : m_bf_memory(brain.m_bf_memory)
    , m_code(brain.m_code)
{
}

Error Brainfuck::run()
{
    m_bf_memory.reset();    
    Error res;

    while (!m_code.is_end()) {
        OpCode operation = m_code.get_current();  
        res = interpreter(operation); 
        ++m_code;      
    }
    return res;
}

Error Brainfuck::interpreter(OpCode command)
{
    Error res = Error::Succeeded;
    
    switch (command)
    {
    case OpCode::Left: left(); break;
    case OpCode::Right: right(); break;
    case OpCode::Increment: increment(); break;
    case OpCode::Decrement: decrement(); break;
    case OpCode::Write: res = write(); break;
    case OpCode::Read: read(); break;
    case OpCode::LoopBegin: res = loop_begin(); break;
    case OpCode::LoopEnd: res = loop_end(); break;
       
    default: break;
    }
    
    return res;
}

void Brainfuck::left()
{
    m_bf_memory<<1;
}

void Brainfuck::right()
{
    m_bf_memory>>1;
}

void Brainfuck::increment()
{
     m_bf_memory++;
}

void Brainfuck::decrement()
{
     m_bf_memory--;
}

Error Brainfuck::write()
{
    Error res = m_bf_memory();
    return res;
}

void Brainfuck::read()
{
    *m_bf_memory;
}

Error Brainfuck::loop_begin()
{
    Error res = Error::Succeeded;

    if (!m_bf_memory.get_value()) {        
            res = jump_forward();
    }
    
    return res;
}

Error Brainfuck::loop_end()
{
    Error res = Error::Succeeded; 

    if (m_bf_memory.get_value()) {
            res = jump_backward();
    } 
    
    return res;    
}

Error Brainfuck::jump_forward()
{
    size_t count = 1;
    if (m_code.get_current() == OpCode::Halt) {
        return Error::UnmatchedBracketsError;
    }
    ++m_code;
    while (count != 0) {
        if (m_code.get_current() == OpCode::Halt) {
            return Error::UnmatchedBracketsError;
        } 
        if (m_code.get_current() == OpCode::LoopBegin) {
            ++count;
        }
        if (m_code.get_current() == OpCode::LoopEnd) {
            --count;
        }
        ++m_code;
    }
    --m_code;

    return Error::Succeeded;
}

Error Brainfuck::jump_backward()
{
    size_t count = 1;
    if (!static_cast<int>(m_code.get_current())) {
        return Error::UnmatchedBracketsError;
    }
    --m_code;
    while (count != 0) {
        if (!static_cast<int>(m_code.get_current())) {
            return Error::UnmatchedBracketsError;
        }
        if (m_code.get_current() == OpCode::LoopEnd) {
            ++count;
        }
        if (m_code.get_current() == OpCode::LoopBegin) {
            --count;
        }
        --m_code;
    }
    ++m_code;
    return Error::Succeeded;
}

Error Brainfuck::dump(std::ostream& os)
{
    Error res = Error::Succeeded;    
    res = m_bf_memory.print(os);
    os << std::endl;
    res = m_code.print(os);
    return res;
} 


    
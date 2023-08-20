#ifndef BRAIN_FUCK_H
#define BRAIN_FUCK_H

#include <cstddef>
#include "compiler.hpp"
#include "bf_memory.hpp"
#include "enums.hpp"
#include "errors.hpp"
#include "code.hpp"

namespace bf {

class Brainfuck
{
public:
    explicit Brainfuck(Code command);
    Brainfuck(const Brainfuck& other);
    Brainfuck& operator=(const Brainfuck& other) = default;
    ~Brainfuck() = default;
    
    Error run();
    Error dump(std::ostream& os);   //Screenshot of the system
    
    Error loop_begin();
    Error loop_end();
    void left();
    void right();
    void increment();
    void decrement();
    Error write();
    void read();

    Error jump_forward();
    Error jump_backward();

private:
    Error interpreter(OpCode command);    

private:
    Memory m_bf_memory;
    Code m_code;
};

} // namespace bf

#endif
#ifndef ET_STACK_H
#define ET_STACK_H

#include <stack>
#include "expression.hpp"

namespace et {

template <typename T>
class Stack
{
public:
    Stack();   

    T pop();
    T top();
    void push(T const& data);
    bool empty();

private:
    std::stack<T> m_stack;
};

} // namespace et

#include "Stack.inl"

#endif
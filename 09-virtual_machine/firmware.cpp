#include <iostream>
#include <vector> // std::vector
#include "firmware.hpp"
#include "result.hpp"

namespace vm {

RunResult add(std::vector<int32_t> const& opcodes, std::ostream& os, int32_t index, std::stack<int32_t>& stk, std::stack<int32_t>& call_stk) 
{
    if (stk.size() < 2) {
        RunResult res(false, Result::MISSING_ELEMENTS, index);
        return res;
    }    

    int32_t a = stk.top(); 
    stk.pop();
    int32_t b = stk.top();
    stk.pop();
    stk.push(a + b);

    return RunResult(true, Result::SUCCESS, index);  
}

RunResult sub(std::vector<int32_t> const& opcodes, std::ostream& os, int32_t index, std::stack<int32_t>& stk, std::stack<int32_t>& call_stk) 
{
    if (stk.size() < 2) {
        RunResult res(false, Result::MISSING_ELEMENTS, index);
        return res;
    }

    int32_t a = stk.top(); 
    stk.pop();
    int32_t b = stk.top();
    stk.pop();
    stk.push(a - b);

    return RunResult(true, Result::SUCCESS, index);  
}

RunResult mul(std::vector<int32_t> const& opcodes, std::ostream& os, int32_t index, std::stack<int32_t>& stk, std::stack<int32_t>& call_stk) 
{
    if (stk.size() < 2) {
        RunResult res(false, Result::MISSING_ELEMENTS, index);
        return res;
    }

    int32_t a = stk.top(); 
    stk.pop();
    int32_t b = stk.top();
    stk.pop();
    stk.push(a * b);

    return RunResult(true, Result::SUCCESS, index);  
}

RunResult divide(std::vector<int32_t> const& opcodes, std::ostream& os, int32_t index, std::stack<int32_t>& stk, std::stack<int32_t>& call_stk) 
{
    if (stk.size() < 2) {
        RunResult res(false, Result::MISSING_ELEMENTS, index);
        return res;
    }  

    int32_t a = stk.top(); 
    stk.pop();
    int32_t b = stk.top();
    stk.pop();

    if (b == 0) {
        RunResult res(false, Result::DIVIDING_BY_ZERO, index);
        return res;
    }

    stk.push(a / b);

    return RunResult(true, Result::SUCCESS, index);  
}

RunResult pop(std::vector<int32_t> const& opcodes, std::ostream& os, int32_t index, std::stack<int32_t>& stk, std::stack<int32_t>& call_stk) 
{
    if (stk.empty()) {
        RunResult res(false, Result::MISSING_ELEMENTS, index);
        return res;
    }
    
    stk.pop(); 

    return RunResult(true, Result::SUCCESS, index);  
}

RunResult push(std::vector<int32_t> const& opcodes, std::ostream& os, int32_t index, std::stack<int32_t>& stk, std::stack<int32_t>& call_stk) 
{
    ++index;
    int32_t a = opcodes[index];
    stk.push(a);     

    return RunResult(true, Result::SUCCESS, index);  
}

RunResult dup(std::vector<int32_t> const& opcodes, std::ostream& os, int32_t index, std::stack<int32_t>& stk, std::stack<int32_t>& call_stk) 
{
    if (stk.size() < 1) {
        RunResult res(false, Result::MISSING_ELEMENTS, index);
        return res;
    }

    int32_t a = stk.top();
    stk.push(a); 

    return RunResult(true, Result::SUCCESS, index);  
}

RunResult swap(std::vector<int32_t> const& opcodes, std::ostream& os, int32_t index, std::stack<int32_t>& stk, std::stack<int32_t>& call_stk) 
{
    if (stk.size() < 2) {
        RunResult res(false, Result::MISSING_ELEMENTS, index);
        return res;
    }
    
    int32_t a = stk.top(); 
    stk.pop();
    int32_t b = stk.top();
    stk.pop();
    stk.push(b);
    stk.push(a);

    return RunResult(true, Result::SUCCESS, index);  
}

RunResult print(std::vector<int32_t> const& opcodes, std::ostream& os, int32_t index, std::stack<int32_t>& stk, std::stack<int32_t>& call_stk)
{
    if (stk.empty()) {
        RunResult res(false, Result::MISSING_ELEMENTS, index);
        return res;
    }

    int32_t a = stk.top();
    stk.pop();
    os << a << ", " << std::flush;     
    
    return RunResult(true, Result::SUCCESS, index);  
}

RunResult printc(std::vector<int32_t> const& opcodes, std::ostream& os, int32_t index, std::stack<int32_t>& stk, std::stack<int32_t>& call_stk) 
{
    if (stk.empty()) {
        RunResult res(false, Result::MISSING_ELEMENTS, index);
        return res;
    }
    
    char a = static_cast<char>(stk.top());
    stk.pop();
    os << a << ", " << std::flush;      

    return RunResult(true, Result::SUCCESS, index);  
}

RunResult inc(std::vector<int32_t> const& opcodes, std::ostream& os, int32_t index, std::stack<int32_t>& stk, std::stack<int32_t>& call_stk)
{
    if (stk.empty()) {
        RunResult res(false, Result::MISSING_ELEMENTS, index);
        return res;
    }
    
    int32_t val = stk.top() + 1;
    stk.pop();
    stk.push(val);
    
    return RunResult(true, Result::SUCCESS, index);  
}

RunResult dec(std::vector<int32_t> const& opcodes, std::ostream& os, int32_t index, std::stack<int32_t>& stk, std::stack<int32_t>& call_stk)
{
    if (stk.empty()) {
        RunResult res(false, Result::MISSING_ELEMENTS, index);
        return res;
    }
    
    int32_t a = stk.top() - 1;
    stk.pop();
    stk.push(a);

    return RunResult(true, Result::SUCCESS, index);  
}

RunResult jmp(std::vector<int32_t> const& opcodes, std::ostream& os, int32_t index, std::stack<int32_t>& stk, std::stack<int32_t>& call_stk)
{
    if (static_cast<int>(index + 1) >  static_cast<int>(opcodes.size()) || static_cast<int>(opcodes[index + 1])  < 0) {
        RunResult res(false, Result::WRONG_INDEX, index);
        return res;
    }    
    
    int32_t address = opcodes[index + 1]; 
    int32_t new_index = address - 1;

    return RunResult(true, Result::SUCCESS, new_index);  
}

RunResult jz(std::vector<int32_t> const& opcodes, std::ostream& os, int32_t index, std::stack<int32_t>& stk, std::stack<int32_t>& call_stk)
{
    if (stk.empty()) {
        RunResult res(false, Result::MISSING_ELEMENTS, index);
        return res;
    }
    
    int32_t a = stk.top();
    stk.pop();
    if (a == 0) {
        index = opcodes[index + 1] - 1; 
    }
    else {
        ++index;
    }

    return RunResult(true, Result::SUCCESS, index);  
}  

RunResult jnz(std::vector<int32_t> const& opcodes, std::ostream& os, int32_t index, std::stack<int32_t>& stk, std::stack<int32_t>& call_stk)
{
    if (stk.empty()) {
        RunResult res(false, Result::MISSING_ELEMENTS, index);
        return res;
    }
    
    int32_t a = stk.top();
    stk.pop();
    if (a != 0) {
        index = opcodes[index + 1] - 1; 
    }
    else { 
        ++index;
    }   

    return RunResult(true, Result::SUCCESS, index);  
}

RunResult call(std::vector<int32_t> const& opcodes, std::ostream& os, int32_t index, std::stack<int32_t>& stk, std::stack<int32_t>& call_stk)
{
    RunResult res(true, Result::SUCCESS, index);
    
    call_stk.push(index);
    res = jmp(opcodes, os, index, stk, call_stk);

    return res;  
}

RunResult ret(std::vector<int32_t> const& opcodes, std::ostream& os, int32_t index, std::stack<int32_t>& stk, std::stack<int32_t>& call_stk)
{
    if (call_stk.size() == 0) {
        RunResult res(false, Result::EMPTY_CALL_STACK, index);
        return res;
    }    
    
    int32_t return_index = call_stk.top();
    call_stk.pop();
    int32_t new_index = return_index + 1;

    return RunResult(true, Result::SUCCESS, new_index);  
}

RunResult nop(std::vector<int32_t> const& opcodes, std::ostream& os, int32_t index, std::stack<int32_t>& stk, std::stack<int32_t>& call_stk) 
{
    return RunResult(true, Result::SUCCESS, index);
}

} // namespace vm
#ifndef FIRMWARE_H
#define FIRMWARE_H

#include <iostream>
#include <vector> // std::vector
#include <stack> // std::stack
#include "result.hpp"
#include "opCodes.hpp"

namespace vm {

RunResult add(std::vector<int32_t> const& opcodes, std::ostream& os, int32_t index, std::stack<int32_t>& stk, std::stack<int32_t>& call_stack);
RunResult sub(std::vector<int32_t> const& opcodes, std::ostream& os, int32_t index, std::stack<int32_t>& stk, std::stack<int32_t>& call_stack); 
RunResult mul(std::vector<int32_t> const& opcodes, std::ostream& os, int32_t index, std::stack<int32_t>& stk, std::stack<int32_t>& call_stack); 
RunResult divide(std::vector<int32_t> const& opcodes, std::ostream& os, int32_t index, std::stack<int32_t>& stk, std::stack<int32_t>& call_stack); 
RunResult pop(std::vector<int32_t> const& opcodes, std::ostream& os, int32_t index, std::stack<int32_t>& stk, std::stack<int32_t>& call_stack); 
RunResult push(std::vector<int32_t> const& opcodes, std::ostream& os, int32_t index, std::stack<int32_t>& stk, std::stack<int32_t>& call_stack); 
RunResult dup(std::vector<int32_t> const& opcodes, std::ostream& os, int32_t index, std::stack<int32_t>& stk, std::stack<int32_t>& call_stack); 
RunResult swap(std::vector<int32_t> const& opcodes, std::ostream& os, int32_t index, std::stack<int32_t>& stk, std::stack<int32_t>& call_stack); 
RunResult print(std::vector<int32_t> const& opcodes, std::ostream& os, int32_t index, std::stack<int32_t>& stk, std::stack<int32_t>& call_stack); 
RunResult printc(std::vector<int32_t> const& opcodes, std::ostream& os, int32_t index, std::stack<int32_t>& stk, std::stack<int32_t>& call_stack); 
RunResult inc(std::vector<int32_t> const& opcodes, std::ostream& os, int32_t index, std::stack<int32_t>& stk, std::stack<int32_t>& call_stack); 
RunResult dec(std::vector<int32_t> const& opcodes, std::ostream& os, int32_t index, std::stack<int32_t>& stk, std::stack<int32_t>& call_stack); 
RunResult jmp(std::vector<int32_t> const& opcodes, std::ostream& os, int32_t index, std::stack<int32_t>& stk, std::stack<int32_t>& call_stack); 
RunResult jz(std::vector<int32_t> const& opcodes, std::ostream& os, int32_t index, std::stack<int32_t>& stk, std::stack<int32_t>& call_stack); 
RunResult jnz(std::vector<int32_t> const& opcodes, std::ostream& os, int32_t index, std::stack<int32_t>& stk, std::stack<int32_t>& call_stack);
RunResult call(std::vector<int32_t> const& opcodes, std::ostream& os, int32_t index, std::stack<int32_t>& stk, std::stack<int32_t>& call_stack); 
RunResult ret(std::vector<int32_t> const& opcodes, std::ostream& os, int32_t index, std::stack<int32_t>& stk, std::stack<int32_t>& call_stack);
RunResult nop(std::vector<int32_t> const& opcodes, std::ostream& os, int32_t index, std::stack<int32_t>& stk, std::stack<int32_t>& call_stack);

} // namespace vm

#endif

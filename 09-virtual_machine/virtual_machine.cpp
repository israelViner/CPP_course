#include <stack> // std::stack
#include <vector>  // std::vector
#include <functional>  // std::function
#include <cassert> // assert
#include "opCodes.hpp"
#include "result.hpp"
#include "virtual_machine.hpp"

namespace vm {

void VirtualMachine::run(std::vector<int32_t> const& opcodes, std::ostream& os, std::vector<std::string> const& messeges, std::unordered_map<OpCode, func> m_functions)
{
    RunResult vm(true, Result::SUCCESS, 0);    
    vm = execute(opcodes, os ,messeges, m_functions);    
    massege(vm, messeges);
}

RunResult VirtualMachine::execute(std::vector<int32_t> const& opcodes, std::ostream& os, std::vector<std::string> const& messeges, std::unordered_map<OpCode, func> m_functions) 
{
    RunResult res(false, Result::EMPTY_VECTOR, 0);
    std::stack<int32_t> stack;
    std::stack<int32_t> call_stack;
    
    if (opcodes.size() == 0) {        
        return res;
    }

    int32_t index = 0;
    while (true) {        
        if (index >= static_cast<int32_t>(opcodes.size())) {
            return RunResult(false, Result::END_OF_VECTOR, index);
        }

        OpCode op = get_next_insruction(opcodes[index]);
        
        if (op == OpCode::HALT) {
            return res;
        }

        if (opcodes[index] < 0 || opcodes[index] > 17) {
            return RunResult(false, Result::WRONG_COMMAND, index);            
        }
        
        res = m_functions[op](opcodes, os, index, stack, call_stack);
        index = res.m_index; 
        ++index;       
    }
}

OpCode VirtualMachine::get_next_insruction(int32_t command)
{
    return static_cast<OpCode>(command);
}

} // namespace vm

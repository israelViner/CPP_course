#ifndef VIRTUAL_MACHINE_H
#define VIRTUAL_MACHINE_H

#include <iostream>
#include <stack> // std::stack
#include <vector> // std::vector
#include <functional> // std::function
#include <unordered_map> // std::unordered_map
#include "result.hpp"
#include "opCodes.hpp"
#include "firmware.hpp" // for the firmware functions

namespace vm {

using func = std::function<RunResult(std::vector<int32_t> const&, std::ostream&, int32_t, std::stack<int32_t>&, std::stack<int32_t>&)>;

class VirtualMachine 
{
public:
    void run(std::vector<int32_t> const& opcodes, std::ostream& os, std::vector<std::string> const& masseges, std::unordered_map<OpCode, func> m_functions);
    RunResult execute(std::vector<int32_t> const& opcodes, std::ostream& os, std::vector<std::string> const& masseges, std::unordered_map<OpCode, func> m_functions);

private:    
    OpCode get_next_insruction(int32_t val);  
};

} // namespace vm

#endif

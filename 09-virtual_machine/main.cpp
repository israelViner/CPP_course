#include <iostream>
#include <stack> // std::stack
#include <vector> // std::vector
#include <functional> // std::function
#include <unordered_map> // std::unordered_map
#include "virtual_machine.hpp"
#include "firmware.hpp" // for the firmware functions


using namespace vm;
  
std::unordered_map<OpCode, func> functions = {
        {OpCode::ADD, &add},
        {OpCode::SUB, &sub}, 
        {OpCode::MUL, &mul}, 
        {OpCode::DIV, &divide}, 
        {OpCode::POP, &pop},
        {OpCode::PUSH, &push},
        {OpCode::DUP, &dup},
        {OpCode::SWAP, &swap},
        {OpCode::PRINT, &print},
        {OpCode::PRINTC, &printc},
        {OpCode::INC, &inc}, 
        {OpCode::DEC, &dec}, 
        {OpCode::JMP, &jmp},
        {OpCode::JZ, &jz},
        {OpCode::JNZ, &jnz},
        {OpCode::CALL, &call},
        {OpCode::RET, &ret},
        {OpCode::NOP, &nop},       
    };

std::vector<std::string> masseges = {
    "The runing has finished successfully", 
    "ERROR: missing elements in the stack", 
    "ERROR:: trying to divide by zero", 
    "ERROR: reached end of vector", 
    "ERROR: the vector is empty", 
    "ERROR: this command does not exsist", 
    "ERROR: the call stack is empty", 
    "ERROR: this index does not exsist"
}; 

void test_phases_1_2()
{
    std::vector<int32_t> op {
        static_cast<int32_t>(OpCode::PUSH),
        64,
        static_cast<int32_t>(OpCode::INC),
        static_cast<int32_t>(OpCode::DUP),
        static_cast<int32_t>(OpCode::PRINTC),
        static_cast<int32_t>(OpCode::DUP),
        static_cast<int32_t>(OpCode::PUSH),
        70,
        static_cast<int32_t>(OpCode::SUB),
        static_cast<int32_t>(OpCode::JNZ),
        2,
        static_cast<int32_t>(OpCode::HALT)
    };
    VirtualMachine a;
    a.run(op, std::cout, masseges, functions);
    std::cout << "\n";
}

void test_phase_3()
{
    std::vector<int32_t> op{
        static_cast<int32_t>(OpCode::PUSH),
        64,
        static_cast<int32_t>(OpCode::CALL),
        10,
        static_cast<int32_t>(OpCode::NOP),
        static_cast<int32_t>(OpCode::CALL),
        10,
        static_cast<int32_t>(OpCode::NOP),
        static_cast<int32_t>(OpCode::HALT),
        static_cast<int32_t>(OpCode::NOP),
        static_cast<int32_t>(OpCode::INC),
        static_cast<int32_t>(OpCode::DUP),
        static_cast<int32_t>(OpCode::PRINTC),
        static_cast<int32_t>(OpCode::RET),
    };
    VirtualMachine a;
    a.run(op, std::cout, masseges, functions);
    std::cout << "\n";
}


void test_functions()
{
    std::vector<int32_t> op{
        static_cast<int32_t>(OpCode::PUSH), // 10
        10,
        static_cast<int32_t>(OpCode::PUSH), // 10, 10
        10,
        static_cast<int32_t>(OpCode::INC), // 10, 11
        static_cast<int32_t>(OpCode::PRINT), // print 11
        static_cast<int32_t>(OpCode::DUP), // 10, 10
        static_cast<int32_t>(OpCode::DEC), // 10, 10
        static_cast<int32_t>(OpCode::PRINT), // print 9
        static_cast<int32_t>(OpCode::DUP), // 10, 10
        static_cast<int32_t>(OpCode::ADD), // 20
        static_cast<int32_t>(OpCode::PUSH), // 20, 25
        25,
        static_cast<int32_t>(OpCode::MUL), // 500
        static_cast<int32_t>(OpCode::PUSH), // 500, 1000
        1000,
        static_cast<int32_t>(OpCode::DIV), // 2
        static_cast<int32_t>(OpCode::DUP), // 2, 2
        static_cast<int32_t>(OpCode::PRINT), // print 2
        static_cast<int32_t>(OpCode::PUSH), // 2, 25
        25,
        static_cast<int32_t>(OpCode::DUP), // 2, 25, 25
        static_cast<int32_t>(OpCode::POP), // 2, 25
        static_cast<int32_t>(OpCode::SUB), // 23
        static_cast<int32_t>(OpCode::NOP),
        static_cast<int32_t>(OpCode::PRINT), // print 23
        static_cast<int32_t>(OpCode::HALT),
    };
    VirtualMachine a;
    a.run(op, std::cout, masseges, functions);
    std::cout << "\n";
}

void test_edge_cases()
{
    
    std::vector<int32_t> op1 = {};
    std::vector<int32_t> op2 = {static_cast<int32_t>(OpCode::HALT)};
    std::vector<int32_t> op3 = {static_cast<int32_t>(OpCode::PUSH), 65, static_cast<int32_t>(OpCode::POP)};
    std::vector<int32_t> op4 = {static_cast<int32_t>(OpCode::RET)};
    std::vector<int32_t> op5 = {static_cast<int32_t>(OpCode::PUSH), 65, 64, };
    std::vector<int32_t> op6 = {static_cast<int32_t>(OpCode::JMP), 65, };
    std::vector<int32_t> op7 = {static_cast<int32_t>(OpCode::PUSH), 0, static_cast<int32_t>(OpCode::PUSH), 10, 
                                static_cast<int32_t>(OpCode::DIV), static_cast<int32_t>(OpCode::HALT)};
    std::vector<int32_t> op8 = {static_cast<int32_t>(OpCode::PUSH), 10, static_cast<int32_t>(OpCode::ADD)};

    VirtualMachine vm;
    vm.run(op1, std::cout, masseges, functions);
    vm.run(op2, std::cout, masseges, functions);
    vm.run(op3, std::cout, masseges, functions);
    vm.run(op4, std::cout, masseges, functions);
    vm.run(op5, std::cout, masseges, functions);
    vm.run(op6, std::cout, masseges, functions);
    vm.run(op7, std::cout, masseges, functions);
    vm.run(op8, std::cout, masseges, functions);
    std::cout << "\n\n";
}

int main()
{
    std::cout << "Test first phases\n";
    test_phases_1_2();

    std::cout << "Test phase 3\n";
    test_phase_3();

    std::cout << "Test the basic functions\n";
    test_functions();

    std::cout << "Test_edge_cases:\n";
    test_edge_cases();

    return 0;
}
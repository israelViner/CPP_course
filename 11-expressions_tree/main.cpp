#include <string>
#include <iostream>
#include <unordered_map>
#include "expressions_tree.hpp"
#include "tree.hpp"
#include "run_result.hpp"

using namespace et;

using Tree_ptr = std::unique_ptr<Tree>;

std::unordered_map<Result, std::string> masseges = {
    {Result::EmptyString, "ERROR: the string is empty\n"},
    {Result::InvalidChar, "ERROR: invalid char in the string\n"},
    {Result::TwoNumbersInRow, "ERROR: two numbers in a row\n"},
    {Result::TwoOperatorsInRow, "ERROR: two operators in a row\n"},
    {Result::DivByZero, "ERROR: trying to divide by zero\n"},
    {Result::OperatorInFirstIndex, "ERROR: the string start with operator\n"},
    {Result::OperatorInLastIndex, "ERROR: the string end with operator\n"},
    {Result::BracketsStartWithoutEnd, "ERROR: a beackets start without end\n"},
    {Result::BracketsEndWithoutStart, "ERROR: a beackets end without start\n"}
};

void test_1()
{
    std::string str = "5 * 4-10/5-2/2+2-1";
    std::cout << "Test the program on the string '5 * 4-10/5-2/2+2-1': \n";
    Tree_ptr a;
    CompileResult res = expressions_tree(str, a);
    if (res.m_status == Result::Success) {
        std::cout << a->value() << std::endl << std::endl;
    } else {
        std::cout << masseges[res.m_status] << "occur in index: " << res.m_index << std::endl << std::endl;
    }
}

void test_2()
{
    std::string str = "1 / 2 + 1 / 2* 3";
    std::cout << "Test the program on the string '1 / 2 + 1 / 2* 3': \n";
    Tree_ptr a;
    CompileResult res = expressions_tree(str, a);
    if (res.m_status == Result::Success) {
        std::cout << a->value() << std::endl << std::endl;
    } else {
        std::cout << masseges[res.m_status] << "occur in index: " << res.m_index << std::endl << std::endl;
    }
}

void test_3()
{
    std::string str = "+ 5 + 3";
    std::cout << "Test the program on the string '+ 5 + 3': \n";
    Tree_ptr a;
    CompileResult res = expressions_tree(str, a);
    if (res.m_status == Result::Success) {
        std::cout << a->value() << std::endl << std::endl;
    } else {
        std::cout << masseges[res.m_status] << "occur in index: " << res.m_index << std::endl << std::endl;
    }
}


void test_4()
{
    std::string str = "5 + 3 + ";
    std::cout << "Test the program on the string '5 + 3 + ': \n";
    Tree_ptr a;
    CompileResult res = expressions_tree(str, a);
    if (res.m_status == Result::Success) {
        std::cout << a->value() << std::endl << std::endl;
    } else {
        std::cout << masseges[res.m_status] << "occur in index: " << res.m_index << std::endl << std::endl;
    }
}

void test_5()
{
    std::string str = "5 # 3";
    std::cout << "Test the program on the string '5 # 3': \n";
    Tree_ptr a;
    CompileResult res = expressions_tree(str, a);
    if (res.m_status == Result::Success) {
        std::cout << a->value() << std::endl << std::endl;
    } else {
        std::cout << masseges[res.m_status] << "occur in index: " << res.m_index << std::endl << std::endl;
    }
}

void test_6()
{
    std::string str = "5 * (4 + 3)";
    std::cout << "Test the program on the string '5 * (4 + 3)': \n";
    Tree_ptr a;
    CompileResult res = expressions_tree(str, a);
    if (res.m_status == Result::Success) {
        std::cout << a->value() << std::endl << std::endl;
    } else {
        std::cout << masseges[res.m_status] << "occur in index: " << res.m_index << std::endl << std::endl;
    }
}

void test_7()
{
    std::string str = "5 + (4 + (4/2) * 3) / 2";
    std::cout << "Test the program on the string '5 + (4 + (4/2) * 3) / 2': \n";
    Tree_ptr a;
    CompileResult res = expressions_tree(str, a);
    if (res.m_status == Result::Success) {
        std::cout << a->value() << std::endl << std::endl;
    } else {
        std::cout << masseges[res.m_status] << "occur in index: " << res.m_index << std::endl << std::endl;
    }
}

void test_8()
{
    std::string str = "";
    std::cout << "Test the program on an empty string: \n";
    Tree_ptr a;
    CompileResult res = expressions_tree(str, a);
    if (res.m_status == Result::Success) {
        std::cout << a->value() << std::endl << std::endl;
    } else {
        std::cout << masseges[res.m_status] << "occur in index: " << res.m_index << std::endl << std::endl;
    }
}

void test_9()
{
    std::string str = "(sqrt81 * 5 + cos0 * (sqrt(sqrt16) + 4/2) * 3 - 1) / sqrt64";
    std::cout << "Test the program for the unary operators on the string '(sqrt81 * 5 + cos0 * (sqrt(sqrt16) + 4/2) * 3 - 1) / sqrt64': \n";
    Tree_ptr a;
    CompileResult res = expressions_tree(str, a);
    if (res.m_status == Result::Success) {
        std::cout << a->value() << std::endl << std::endl;
    } else {
        std::cout << masseges[res.m_status] << "occur in index: " << res.m_index << std::endl << std::endl;
    }
}

void test_10()
{
    std::string str = "2^(2+3)/2^2";
    std::cout << "Test the program for the power operator on the string '2^(2+3)/2^2': \n";
    Tree_ptr a;
    CompileResult res = expressions_tree(str, a);
    if (res.m_status == Result::Success) {
        std::cout << a->value() << std::endl << std::endl;
    } else {
        std::cout << masseges[res.m_status] << "occur in index: " << res.m_index << std::endl << std::endl;
    }
}

void test_11()
{
    std::cout << "Test the program on the input string: \n";
    std::string str;
    std::cout << "Enter the expressins-string that you want to check: \n";
    std::cin >> str;
    Tree_ptr a;
    CompileResult res = expressions_tree(str, a);
    if (res.m_status == Result::Success) {
        std::cout << a->value() << std::endl << std::endl;
    } else {
        std::cout << masseges[res.m_status] << "occur in index: " << res.m_index << std::endl << std::endl;
    }
}

int main()
{
    test_1();
    test_2();
    test_3();
    test_4();
    test_5();
    test_6();
    test_7();
    test_8();
    test_9();
    test_10();
    test_11();

    return 0;
}
#include <cstdint>
#include <vector>
#include <string>
#include <memory>
#include <unordered_map>
#include <functional>
#include "lexer.hpp"
#include "token.hpp"
#include "derive_token.hpp"
#include "groups_enum.hpp"
#include "run_result.hpp"

namespace et {

std::unordered_map<std::string, std::function<Token_ptr()>> get_operator =
{
    {"+" , [](){return std::make_shared<Lexeme>(GroupsEnum::SumGroup, OperEnum::Add);}},
    {"-" ,  [](){return std::make_shared<Lexeme>(GroupsEnum::SumGroup, OperEnum::Sub);}},
    {"*" , [](){return std::make_shared<Lexeme>(GroupsEnum::ProductGroup, OperEnum::Mul);}},
    {"/" ,  [](){return std::make_shared<Lexeme>(GroupsEnum::ProductGroup, OperEnum::Div);}},
    {"^" ,  [](){return std::make_shared<Lexeme>(GroupsEnum::ProductGroup, OperEnum::Pow);}},
    {"(" ,  [](){return std::make_shared<Lexeme>(GroupsEnum::BracketsGroup, OperEnum::OBrac);}},
    {")" ,  [](){return std::make_shared<Lexeme>(GroupsEnum::BracketsGroup, OperEnum::CBrac);}},
    {"sqrt" ,  [](){return std::make_shared<Lexeme>(GroupsEnum::UnarysGroup, OperEnum::Sqrt);}},
    {"sin" ,  [](){return std::make_shared<Lexeme>(GroupsEnum::UnarysGroup, OperEnum::Sin);}},
    {"cos" ,  [](){return std::make_shared<Lexeme>(GroupsEnum::UnarysGroup, OperEnum::Cos);}}
};

static bool is_operator(char c)
{
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '(' || c == ')' || c == '^';
}

static bool is_num(char c)
{
    return c >= '0' && c <= '9';
}

static Result get_num(int32_t& num, std::string::const_iterator& iter, std::string::const_iterator& end_it)
{
    std::string str_res;
    while (iter != end_it && !is_operator(*iter) && *iter >= '0' && *iter <= '9' && *iter != ' ') {
        str_res += *iter;
        ++iter;
    }
    if (iter != end_it && !is_operator(*iter) && *iter != ' ') { 
        return Result::InvalidChar;
    }
    num = stoi(str_res);
    --iter;
    return Result::Success;
}

static CompileResult get_op(std::string const& str, std::string& res, std::string::const_iterator& iter, size_t index)
{
    if (is_operator(*iter)) {
        res = *iter;
        return CompileResult(Result::Success, index);
    }

    if (*iter >= 'a' && *iter <= 'z') {
        while (*iter >= 'a' && *iter <= 'z') {
            res += *iter;
            ++iter;
        }
        --iter;
    } 

    if (!get_operator.count(res)) {
        return CompileResult(Result::InvalidChar, index);
    }
    
    return CompileResult(Result::Success, index);
}

CompileResult lexer(std::string const& str, Stack<int32_t>& num_stk, std::vector<Token_ptr>& tokens_vector)
{
    if(str.empty()) {
        return CompileResult(Result::EmptyString, 0);
    }

    auto iter = str.begin();
    auto end_it = str.end();

    size_t index = 0;
    while (iter != end_it) {
        if (*iter != ' ') {
            if (is_num(*iter)) { 
                int32_t num;               
                Result res = get_num(num, iter, end_it);
                if (res == Result::InvalidChar) {
                    return CompileResult(res, index);
                }
                num_stk.push(num);
                auto tmp = std::make_shared<Lexeme>(GroupsEnum::NumbersGroup, OperEnum::Num);
                tokens_vector.push_back(tmp);
            } else {                
                std::string oper;
                CompileResult res = get_op(str, oper, iter, index);
                if (!(res.m_status == Result::Success)) {
                    return res;
                }
                Token_ptr op = get_operator[oper]();
                tokens_vector.push_back(op);
            } 
            ++index;
        }
        ++iter;
    }  

    return CompileResult(Result::Success, index);
}

} // namespace et

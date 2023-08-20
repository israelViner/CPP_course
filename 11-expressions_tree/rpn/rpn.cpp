#include <cstdint>
#include <vector>
#include <memory>
#include "token.hpp"
#include "derive_token.hpp"
#include "rpn.hpp"
#include "groups_enum.hpp"
#include "Stack.hpp"
#include "run_result.hpp"

namespace et {

static bool is_bigger(Token const& a, Token const& b)
{
    return a.get_group() > b.get_group();
}

static bool is_smaller(Token const& a, Token const& b)
{
    return a.get_group() < b.get_group();
}

static void move_between_stacks(Stack<Token_ptr>& origin, Stack<Token_ptr>& target) 
{
    Token_ptr top =  origin.pop();
    target.push(top);
}

static CompileResult brackets_handeling(Token_ptr const& token, Stack<Token_ptr>& tokens_stk,  Stack<Token_ptr>& auxiliary_stack, size_t index)
{
    if (token->get_type() == OperEnum::OBrac) {
            auxiliary_stack.push(token); 
            return CompileResult(Result::Success, index);
    } else {
        while (!auxiliary_stack.empty() && auxiliary_stack.top()->get_type() != OperEnum::OBrac) {
                move_between_stacks(auxiliary_stack, tokens_stk);
        } 
        if (auxiliary_stack.empty()) {
            return CompileResult(Result::BracketsEndWithoutStart, index);
        }
        if (auxiliary_stack.top()->get_type() == OperEnum::OBrac) {
            auxiliary_stack.pop();
        }
    }
    return CompileResult(Result::Success, index);
}

static CompileResult edge_errors(std::vector<Token_ptr> const& expressions)
{
    auto iter = expressions.begin();

    if ((*iter)->get_group() != GroupsEnum::NumbersGroup && (*iter)->get_group() != GroupsEnum::BracketsGroup  && (*iter)->get_group() != GroupsEnum::UnarysGroup) {
        return CompileResult(Result::OperatorInFirstIndex, 0);
    } 
    
    if (expressions.back()->get_group() != GroupsEnum::NumbersGroup && expressions.back()->get_group() != GroupsEnum::BracketsGroup) {
        return CompileResult(Result::OperatorInLastIndex, expressions.size() - 1);
    }

    return CompileResult(Result::Success, 0);
}

static CompileResult compare_tokens(GroupsEnum const& first_token, GroupsEnum const& second_token, size_t index)
{
    if (second_token != GroupsEnum::BracketsGroup && first_token != GroupsEnum::BracketsGroup && second_token != GroupsEnum::UnarysGroup) {          
        if (first_token == GroupsEnum::NumbersGroup && first_token == second_token) {
            return CompileResult(Result::TwoNumbersInRow, index);
         } else if (first_token != GroupsEnum::NumbersGroup && second_token != GroupsEnum::NumbersGroup) {
            return CompileResult(Result::TwoOperatorsInRow, index);
        }            
    }
    return CompileResult(Result::Success, index);
}

static CompileResult mid_errors(std::vector<Token_ptr> const& expressions, std::vector<Token_ptr>::const_iterator& first, std::vector<Token_ptr>::const_iterator& second, size_t index)
{
    CompileResult res(Result::Success, index);

    if (second != expressions.end()) {        
        res = compare_tokens((*first)->get_group(), (*second)->get_group(), index);                             
    }

    return res;
}

CompileResult convert_to_rpn(std::vector<Token_ptr> const& expressions, Stack<Token_ptr>& tokens_stk)
{
    Stack<Token_ptr> auxiliary_stack;

    CompileResult res(Result::Success, 0);

    auto iter = expressions.begin();
    auto end_it = expressions.end();
    auto next_token = expressions.begin();

    res = edge_errors(expressions);

    if (res.m_status == Result::Success) {
        size_t index = 0;
        while (iter != end_it) {
            ++next_token;        
            
            res = mid_errors(expressions, iter, next_token, index);
            if (res.m_status != Result::Success) { 
                return res;
            }  

            if ((*iter)->get_group() == GroupsEnum::BracketsGroup) {
                res = brackets_handeling(*iter, tokens_stk, auxiliary_stack, index);
                if (res.m_status != Result::Success) { 
                    return res;
                } 
            } else if ((*iter)->get_group() == GroupsEnum::NumbersGroup) {
                tokens_stk.push(*iter);        
            } else {
                if (!auxiliary_stack.empty() && !is_bigger(*(*iter),  *auxiliary_stack.top()) && !((*iter)->get_type() == OperEnum::Pow)) {
                    if (!is_smaller(*(*iter),  *auxiliary_stack.top())) {
                        move_between_stacks(auxiliary_stack, tokens_stk);
                    } else {
                        while (!auxiliary_stack.empty() && !is_bigger(*(*iter), *auxiliary_stack.top())) {
                            move_between_stacks(auxiliary_stack, tokens_stk);
                        } 
                    }
                }        
                auxiliary_stack.push(*iter); 
            }
            
            ++iter;
            ++index;        
        }
        while (!auxiliary_stack.empty()) {
            if (auxiliary_stack.top()->get_type() == OperEnum::OBrac) {
                return CompileResult(Result::BracketsStartWithoutEnd, 0);
            }
            move_between_stacks(auxiliary_stack, tokens_stk);
        }
    }

    return res;
}

} // namespace et

#include <string>
#include <vector>
#include <cassert>
#include <memory>
#include <unordered_map>
#include <functional>
#include "token.hpp"
#include "derive_token.hpp"
#include "expression.hpp"
#include "tree.hpp"
#include "expressions_tree.hpp"
#include "operand.hpp"
#include "binary_operator_node.hpp"
#include "rpn.hpp"
#include "lexer.hpp"
#include "Stack.hpp"
#include "run_result.hpp"
#include "unary_operator.hpp"

namespace et {

std::unordered_map<OperEnum, std::function<Expression_ptr(Expression_ptr&, Expression_ptr&)>> get_expression =
{
    {OperEnum::Add, expression_add},
    {OperEnum::Sub, expression_sub},
    {OperEnum::Mul, expression_mul},
    {OperEnum::Div, expression_div},
    {OperEnum::Pow, expression_pow}
};

std::unordered_map<OperEnum, std::function<Expression_ptr(Expression_ptr&)>> get_unary =
{
    {OperEnum::Sqrt, expression_sqrt},
    {OperEnum::Sin, expression_sin},
    {OperEnum::Cos, expression_cos}  
};

Expression_ptr parser(Stack<Token_ptr>& order_exp, Stack<int32_t>& num_stk)
{
    Token_ptr top = order_exp.pop();
    GroupsEnum top_group = top->get_group();
    OperEnum top_type = top->get_type();
    Expression_ptr head = create_expression(top_type, top_group, order_exp, num_stk);
    return head;
}

Expression_ptr create_expression(OperEnum& m_type, GroupsEnum& group, Stack<Token_ptr>& stk, Stack<int32_t>& num_stk)
{ 
    if (group == GroupsEnum::NumbersGroup) 
    { 
        int32_t num = num_stk.pop();
        return std::make_unique<OperandExp>(num); 
    }
    
    if (group == GroupsEnum::UnarysGroup) {
        Token_ptr tmp = stk.pop();
        GroupsEnum descendant_group = tmp->get_group();
        OperEnum descendant_type = tmp->get_type();
        Expression_ptr descendant = create_expression(descendant_type, descendant_group, stk, num_stk);        
        
        Expression_ptr res = get_unary[m_type](descendant);
        return res;
    }
    
    Token_ptr tmp = stk.pop();
    GroupsEnum left_group = tmp->get_group();
    OperEnum left_type = tmp->get_type();
    Expression_ptr left = create_expression(left_type, left_group, stk, num_stk);
    Token_ptr tmp2 = stk.pop();
    GroupsEnum right_group = tmp2->get_group();
    OperEnum right_type = tmp2->get_type();
    Expression_ptr right = create_expression(right_type, right_group, stk, num_stk);

    Expression_ptr res = get_expression[m_type](left, right);
    return res;
}

CompileResult expressions_tree(std::string str, Tree_ptr& tree)
{
    Stack<int32_t> num_stk;
    std::vector<Token_ptr> tokens_vector;
    CompileResult res_lex = lexer(str, num_stk, tokens_vector);
    if (res_lex.m_status == Result::Success) {
        Stack<Token_ptr> tokens_stk;
        CompileResult res_rpn = convert_to_rpn(tokens_vector, tokens_stk);
        if (res_rpn.m_status == Result::Success) {
            Expression_ptr exp = parser(tokens_stk, num_stk);    
            tree = std::make_unique<Tree>(exp);
        }
        return res_rpn;
    } else {
        return res_lex;
    }
}

} // namespace et
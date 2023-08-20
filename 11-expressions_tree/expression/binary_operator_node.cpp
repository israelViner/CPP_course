#include <memory>
#include <cassert>
#include <cmath>
#include "expression.hpp"
#include "binary_operator_node.hpp"

namespace et {

BinaryOperator::BinaryOperator(Expression_ptr& left, Expression_ptr& right) 
    : m_left(std::move(left))
    , m_right(std::move(right)) 
{    
} 

double BinaryOperator::get_right() const 
{ 
    return m_right->value(); 
}
    
double BinaryOperator::get_left() const 
{ 
    return m_left->value(); 
}

double BinaryOperatorAdd::value() const 
{ 
    return get_right() + get_left();
}

double BinaryOperatorSub::value() const 
{ 
    return get_right() - get_left(); 
}
   
double BinaryOperatorDiv::value() const 
{ 
    double left = get_left();
    assert(left);
    return get_right() / left;
}
   
double BinaryOperatorMul::value() const 
{ 
    return get_right() * get_left(); 
}

double BinaryOperatorPow::value() const 
{ 
    return pow(get_right(), get_left()); 
}

Expression_ptr expression_add(Expression_ptr& left, Expression_ptr& right)
{
    return std::make_unique<BinaryOperatorAdd>(left, right);
}

Expression_ptr expression_sub(Expression_ptr& left, Expression_ptr& right)
{
    return std::make_unique<BinaryOperatorSub>(left, right);
}

Expression_ptr expression_mul(Expression_ptr& left, Expression_ptr& right)
{
    return std::make_unique<BinaryOperatorMul>(left, right);
}

Expression_ptr expression_div(Expression_ptr& left, Expression_ptr& right)
{
    return std::make_unique<BinaryOperatorDiv>(left, right);
}

Expression_ptr expression_pow(Expression_ptr& left, Expression_ptr& right)
{
    return std::make_unique<BinaryOperatorPow>(left, right);
}

} // namespace et

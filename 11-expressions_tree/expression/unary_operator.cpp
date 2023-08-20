#include <memory>
#include <cassert>
#include <cmath>
#include "expression.hpp"
#include "unary_operator.hpp"

namespace et {

UnaryOperator::UnaryOperator(Expression_ptr& descendant) 
    : m_descendant(std::move(descendant))
{    
} 

double UnaryOperator::get_descendant() const 
{ 
    return m_descendant->value(); 
}

double UnaryOperatorSqrt::value() const 
{ 
    return sqrt(get_descendant());
}

double UnaryOperatorSin::value() const 
{ 
    return sin(get_descendant()); 
}

double UnaryOperatorCos::value() const 
{ 
    return cos(get_descendant()); 
}

Expression_ptr expression_sqrt(Expression_ptr& descendant)
{
    return std::make_unique<UnaryOperatorSqrt>(descendant);
}

Expression_ptr expression_sin(Expression_ptr& descendant)
{
    return std::make_unique<UnaryOperatorSin>(descendant);
}

Expression_ptr expression_cos(Expression_ptr& descendant)
{
    return std::make_unique<UnaryOperatorCos>(descendant);
}


} // namespace et
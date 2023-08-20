#ifndef UNARY_OPERATOR_H
#define UNARY_OPERATOR_H

#include <memory>
#include "expression.hpp"

namespace et {

using Expression_ptr = std::unique_ptr<Expression>;

Expression_ptr expression_sqrt(Expression_ptr& descendant);
Expression_ptr expression_sin(Expression_ptr& descendant);
Expression_ptr expression_cos(Expression_ptr& descendant);


class UnaryOperator : public Expression
{
public:
    explicit UnaryOperator(Expression_ptr& descendant); 

protected:
    double get_descendant() const;

private:
    std::shared_ptr<Expression> m_descendant;
};

class UnaryOperatorSqrt : public UnaryOperator
{
public:  
    using UnaryOperator::UnaryOperator;
   
    virtual double value() const override; 
}; 

class UnaryOperatorSin : public UnaryOperator
{
public:  
    using UnaryOperator::UnaryOperator;
   
    virtual double value() const override; 
}; 

class UnaryOperatorCos : public UnaryOperator
{
public:  
    using UnaryOperator::UnaryOperator;
   
    virtual double value() const override; 
}; 


} // namespace et

#endif

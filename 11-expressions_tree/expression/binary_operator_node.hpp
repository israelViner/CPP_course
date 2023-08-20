#ifndef BINARY_OPERATOR_H
#define BINARY_OPERATOR_H

#include <memory>
#include "expression.hpp"

namespace et {

using Expression_ptr = std::unique_ptr<Expression>;

Expression_ptr expression_add(Expression_ptr& left, Expression_ptr& right);
Expression_ptr expression_sub(Expression_ptr& left, Expression_ptr& right);
Expression_ptr expression_mul(Expression_ptr& left, Expression_ptr& right);
Expression_ptr expression_div(Expression_ptr& left, Expression_ptr& right);
Expression_ptr expression_pow(Expression_ptr& left, Expression_ptr& right);

class BinaryOperator : public Expression
{
public:
    explicit BinaryOperator(Expression_ptr& left, Expression_ptr& right); 

protected:
    double get_right() const;
    double get_left() const;

private:
    std::shared_ptr<Expression> m_left;
    std::shared_ptr<Expression> m_right;
};

class BinaryOperatorAdd : public BinaryOperator
{
public:  
    using BinaryOperator::BinaryOperator;
   
    virtual double value() const override; 
}; 

class BinaryOperatorSub : public BinaryOperator
{
public:  
    using BinaryOperator::BinaryOperator;
   
    virtual double value() const override; 
}; 

class BinaryOperatorMul : public BinaryOperator
{
public:
    using BinaryOperator::BinaryOperator;
   
    virtual double value() const override; 
}; 

class BinaryOperatorDiv : public BinaryOperator
{
public:  
    using BinaryOperator::BinaryOperator;
   
    virtual double value() const override;
}; 

class BinaryOperatorPow : public BinaryOperator
{
public:  
    using BinaryOperator::BinaryOperator;
   
    virtual double value() const override;
};

} // namespace et

#endif

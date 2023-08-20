#ifndef OPERAND_H
#define OPERAND_H

#include <cstdint>
#include "expression.hpp"

namespace et
{

class OperandExp : public Expression
{
public:  
    explicit OperandExp(int32_t num) : m_num(num) {} 
    virtual ~OperandExp() = default;
   
    double value() const override { return m_num; };  

private:
    int32_t m_num;   

}; 

} // namespace et

#endif
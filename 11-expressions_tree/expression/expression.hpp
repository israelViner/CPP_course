#ifndef EXPRESSION_H
#define EXPRESSION_H

namespace et
{

class Expression
{
public:  
    virtual ~Expression() = default;
   
    virtual double value() const = 0;  
}; 

} // namespace et

#endif
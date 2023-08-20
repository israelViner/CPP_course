#ifndef GROUPS_ENUMS_H
#define GROUPS_ENUMS_H

#include <cstdint>

namespace et {

enum class GroupsEnum : int8_t
{
    BracketsGroup,
    NumbersGroup,
    SumGroup,
    ProductGroup,
    UnarysGroup
}; 

enum class OperEnum : int8_t
{
    Num,
    Add,
    Sub,
    Mul,
    Div,
    Pow, 
    OBrac,
    CBrac,
    Sqrt,
    Sin,
    Cos
}; 


} // namespace et

#endif

#include <cstdint>
#include "token.hpp"
#include "derive_token.hpp"
#include "groups_enum.hpp"
#include "Stack.hpp"


namespace et {

Lexeme::Lexeme(GroupsEnum group, OperEnum m_type)
    : m_group(group)
    , m_type(m_type)
{    
}

GroupsEnum Lexeme::get_group() const 
{ 
    return m_group; 
}

OperEnum Lexeme::get_type() const 
{ 
    return m_type; 
}

} // namespace et

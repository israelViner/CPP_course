#ifndef DERIVE_TOKEN_H
#define DERIVE_TOKEN_H

#include <cstdint>
#include "token.hpp"
#include "groups_enum.hpp"
#include "Stack.hpp"

namespace et {

class Lexeme : public Token
{
public:
    Lexeme(GroupsEnum group, OperEnum m_type);
   
    GroupsEnum get_group() const override;
    OperEnum get_type() const override;

private:
    GroupsEnum m_group;
    OperEnum m_type;
};

} // namespace et

#endif

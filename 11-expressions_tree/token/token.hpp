#ifndef TOKEN_H
#define TOKEN_H

#include <cstdint>
#include <cstddef>
#include <memory>
#include "expression.hpp"
#include "groups_enum.hpp"
#include "Stack.hpp"


namespace et {

using Expression_ptr = std::unique_ptr<Expression>;

class Token {
public:
    virtual ~Token() = default;

    virtual GroupsEnum get_group() const = 0;
    virtual OperEnum get_type() const = 0;
};

using Token_ptr = std::shared_ptr<Token>;

} // namespace et

#endif

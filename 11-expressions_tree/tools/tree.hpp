#ifndef TREE_H
#define TREE_H

#include <memory>
#include "expression.hpp"

namespace et {

using Expression_ptr = std::unique_ptr<Expression>;

class Tree
{
public:
    Tree() = default;
    explicit Tree(Expression_ptr& other) : m_head(std::move(other)) {}
    Tree(Tree const& other) = default;    
    Tree &operator=(Tree const& other) = delete;

    double value() { return m_head->value(); };

private:
    Expression_ptr m_head;
};

} // namespace et

#endif

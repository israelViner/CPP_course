#ifndef EXPRESSIONS_TREE_H
#define EXPRESSIONS_TREE_H

#include <cstdint>
#include <string>
#include <memory>
#include <vector>
#include "token.hpp"
#include "derive_token.hpp"
#include "expression.hpp"
#include "tree.hpp"
#include "Stack.hpp"
#include "run_result.hpp"

namespace et {

using Token_ptr = std::shared_ptr<Token>;
using Expression_ptr = std::unique_ptr<Expression>;
using Tree_ptr = std::unique_ptr<Tree>;

Expression_ptr parser(Stack<Token_ptr>& order_exp, Stack<int32_t>& num_stk);

Expression_ptr create_expression(OperEnum& m_type, GroupsEnum& group, Stack<Token_ptr>& stk, Stack<int32_t>& num_stk);

CompileResult expressions_tree(std::string str, Tree_ptr& tree);

} // namespace et

#endif
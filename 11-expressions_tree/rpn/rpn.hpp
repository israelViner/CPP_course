#ifndef PARSER_H
#define PARSER_H

#include <cstdint>
#include <vector>
#include <memory>
#include "token.hpp"
#include "Stack.hpp"
#include "run_result.hpp"

namespace et {

using Token_ptr = std::shared_ptr<Token>;

CompileResult convert_to_rpn(std::vector<Token_ptr> const& str, Stack<Token_ptr>& tokens_stk);

} // namespace et

#endif
#ifndef LEXER_H
#define LEXER_H

#include <cstdint>
#include <vector>
#include <string>
#include "token.hpp"
#include "run_result.hpp"

namespace et {

using Token_ptr = std::shared_ptr<Token>;

CompileResult lexer(std::string const& str, Stack<int32_t>& num_stk, std::vector<Token_ptr>& tokens_vector);

} // namespace et

#endif
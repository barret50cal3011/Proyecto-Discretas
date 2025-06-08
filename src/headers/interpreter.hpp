#pragma once

#include <string>
#include <vector>

extern std::string* lexical_tokens;


// Divides the logic formula into its components based on the provided interpreter string.
std::vector<std::string> parseInterpreter(const std::string& equation);
std::vector<std::string> add_parentheses(const std::vector<std::string>& tokens);
std::string tokens_to_string(const std::vector<std::string>& tokens);
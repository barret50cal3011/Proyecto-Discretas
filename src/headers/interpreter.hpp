#pragma once

#include <string>
#include <vector>

// Contains the lexical tokens used for parsing logic formulas.
extern std::string* lexical_tokens;


// Divides the logic formula into its components based on the provided interpreter string.
// @param equation The logic formula as a string.
// @return A vector of strings, each representing a token in the formula.
std::vector<std::string> parseInterpreter(const std::string& equation);


// Adds parentheses to the tokens based on logical precedence and structure.
// Logic precedence is handled as follows:
// 1. Commas (,) - highest precedence
// 2. Negation (!) - second highest precedence
// 3. Conjunction (&, |) - third highest precedence
// 4. Implication (->) and equivalence (<->) - lowest precedence
// @param tokens A vector of strings representing the tokens of the logic formula.
// @return A vector of strings with parentheses added to respect logical precedence.
std::vector<std::string> add_parentheses(const std::vector<std::string>& tokens);


std::string tokens_to_string(const std::vector<std::string>& tokens);
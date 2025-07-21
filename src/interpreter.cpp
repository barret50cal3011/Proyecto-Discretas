#include <string>
#include <vector>
#include <iterator>
#include <iostream>

#include "interpreter.hpp"
#include "util.hpp"

std::string* lexical_tokens = new std::string[37]{
    "(", ")",
    "&", "|", "!", "->", "<->", "T", "F", "=", ",",
    "a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m", "n", "o", "p", "q", "r", "s", "t", "u", "v", "w", "x", "y", "z"
};

std::vector<std::string> parseInterpreter(const std::string& equation)  {
    std::string no_spaces_equation = equation;
    for(size_t i = 0; i < no_spaces_equation.size(); ++i) {
        if (no_spaces_equation[i] == ' ' || no_spaces_equation[i] == '\t') {
            no_spaces_equation.erase(i, 1);
            --i; // Adjust index after erasing
        }
    }

    std::vector<std::string> tokens;

    while (!no_spaces_equation.empty()) {
        for (int i = 0; i < 37; ++i) {
            std::string token = lexical_tokens[i];
            if(!no_spaces_equation.compare(0, token.size(), token)) {
                no_spaces_equation.erase(0, token.size());
                tokens.push_back(token);
                break; // Break to restart the loop with the updated string
            }
        }
    }


    return tokens;
}


std::vector<std::string> add_parentheses(const std::vector<std::string>& tokens) {
    std::vector<std::string> result;
    result.insert(result.begin(), "(");
    // , Priority 1
    for (const auto& token : tokens) {
        if (token == ","){
            result.push_back(")");
            result.push_back(token);
            result.push_back("(");
        } else {
            result.push_back(token);
        }
    }
    result.push_back(")");

    // not ! Priority 2
    for (size_t i = 0; i < result.size(); ++i) {
        if (result[i] == "!") {
            if (isSingleLowerAlpha(result[i + 1])) {
                // Cambiar de (!a) a !(a)
                result.insert(result.begin() + i + 1, "(");
                result.insert(result.begin() + i + 3, ")");
                i += 3;
            } else if (result[i + 1] == "(") {
                // Buscar final de subexpresión y poner paréntesis alrededor, dejando ! afuera
                int depth = 1;
                size_t j = i + 2;
                for (; j < result.size(); ++j) {
                    if (result[j] == "(") depth++;
                    else if (result[j] == ")") depth--;
                    if (depth == 0) break;
                }
                result.insert(result.begin() + i + 1, "("); // después del !
                result.insert(result.begin() + j + 2, ")"); // después del cierre de subexpresión
                i += 2;
            } else if (result[i + 1] == "!") {
                // encadenamiento de negaciones, ej: !!a -> !(!(a))
                size_t j = i + 1;
                while (result[j] == "!") j++;
                if (isSingleLowerAlpha(result[j])) {
                    result.insert(result.begin() + j, "(");
                    result.insert(result.begin() + j + 2, ")");
                    i = j + 2;
                } else if (result[j] == "(") {
                    int depth = 1;
                    size_t k = j + 1;
                    for (; k < result.size(); ++k) {
                        if (result[k] == "(") depth++;
                        else if (result[k] == ")") depth--;
                        if (depth == 0) break;
                    }
                    result.insert(result.begin() + j, "(");
                    result.insert(result.begin() + k + 2, ")");
                    i = k + 2;
                }
            }
        }
    }


    // and, or, |, & Priority 3
    for (size_t i = 0; i < result.size(); ++i) {
        if (result[i] == "and" || result[i] == "or" || result[i] == "&" || result[i] == "|") {
            if (isSingleLowerAlpha(result[i - 1])) {
                result.insert(result.begin() + i - 1, "(");
                i += 1; // Skip over the newly added opening parenthesis
            }else if (result[i - 1] == ")") {
                int depth = 1;
                for (int j = i - 2; j >= 0; --j) {
                    if (result[j] == ")") {
                        depth++;
                    } else if (result[j] == "(") {
                        depth--;
                    }
                    if (depth == 0) {
                        result.insert(result.begin() + j, "(");
                        break;
                    }
                }
                i += 1; // Skip over the newly added opening parenthesis
            }

            if (isSingleLowerAlpha(result[i + 1])) {
                result.insert(result.begin() + i + 2, ")");
            } else if (result[i + 1] == "(") {
                int depth = 1;
                for (size_t j = i + 2; j < result.size(); ++j) {
                    if (result[j] == "(") {
                        depth++;
                    } else if (result[j] == ")") {
                        depth--;
                    }
                    if (depth == 0) {
                        result.insert(result.begin() + j + 1, ")");
                        break;
                    }
                }
            }
        }
    }

    std::cout << "Tokens after & and | processing: " << tokens_to_string(result) << std::endl;

    // implies ->, equiv <-> Priority 4
    for (size_t i = 0; i < result.size(); ++i) {
        if (result[i] == "implies" || result[i] == "->" || result[i] == "equiv" || result[i] == "<->") {
            if (isSingleLowerAlpha(result[i - 1])) {
                result.insert(result.begin() + i - 1, "(");
                i += 1; // Skip over the newly added opening parenthesis
            }else if (result[i - 1] == ")") {
                int depth = 1;
                for (int j = i - 2; j >= 0; --j) {
                    if (result[j] == ")") {
                        depth++;
                    } else if (result[j] == "(") {
                        depth--;
                    }
                    if (depth == 0) {
                        result.insert(result.begin() + j, "(");
                        break;
                    }
                }
                i += 1; // Skip over the newly added opening parenthesis
            }

            if (isSingleLowerAlpha(result[i + 1])) {
                result.insert(result.begin() + i + 2, ")");
            } else if (result[i + 1] == "(") {
                int depth = 1;
                for (size_t j = i + 2; j < result.size(); ++j) {
                    if (result[j] == "(") {
                        depth++;
                    } else if (result[j] == ")") {
                        depth--;
                    }
                    if (depth == 0) {
                        result.insert(result.begin() + j + 1, ")");
                        break;
                    }
                }
            }
        }
    }

    return result;
}

std::string tokens_to_string(const std::vector<std::string>& tokens) {
    std::string result;
    for (const auto& token : tokens) {
        result += token + " ";
    }
    if (!result.empty()) {
        result.pop_back(); // Remove the trailing space
    }
    return result;
}


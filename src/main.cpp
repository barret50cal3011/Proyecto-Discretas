#include <string>
#include <vector>
#include <iostream>

#include "interpreter.hpp"

int main() {
    std::string equation = "!c & (a | b) -> (d <-> e), f, g";
    
    // Parse the equation into tokens
    std::vector<std::string> tokened_equation = parseInterpreter(equation);
    
    // Add parentheses to the tokens
    std::vector<std::string> tokens_with_parentheses = add_parentheses(tokened_equation);
    
    // Convert tokens back to string for output
    std::string result = tokens_to_string(tokens_with_parentheses);
    
    // Output the result
    std::cout << "Parsed and formatted equation: " << result << std::endl;
    
    return 0;
}
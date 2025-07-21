#include <string>
#include <vector>
#include <stdexcept>
#include <algorithm>
#include <iostream>

#include "util.hpp"

bool isSingleLowerAlpha(const std::string& str) {
    return str.size() == 1 && str[0] >= 'a' && str[0] <= 'z';
}


std::string latex_to_logic(const std::string& latex) {
    std::string logic;
    for(int i = 0; i < latex.size(); ++i) {
        if (latex[i] == '\\') {
            i++;
            if(latex.substr(i, 4) == "land") {
                logic += "&"; // Convert \and to &
                i += 4; // Skip the next character
            } else if(latex.substr(i, 3) == "lor") {
                logic += "|"; // Convert \or to |
                i += 3; // Skip the next character
            } else if(latex.substr(i, 4) == "lnot") {
                logic += "!"; // Convert \not to !
                i += 4; // Skip the next character
            } else if(latex.substr(i, 7) == "implies") {
                logic += "->"; // Convert \implies to ->
                i += 7; // Skip the next character
            } else if(latex.substr(i, 3) == "iff") {
                logic += "<->"; // Convert \equiv to <-> 
                i += 3; // Skip the next two characters
            } else{
                throw std::invalid_argument("Unknown LaTeX command, error at position: \\" + i);
            }
            
        } else {
            logic += latex[i]; // Add regular characters directly
        }
    }
    return logic;
}

std::vector<std::string> int_to_binary(int number) {
    std::vector<std::string> binary_digits;
    while (number > 0) {
        binary_digits.push_back(std::to_string(number % 2));
        number = number >> 1;
    }

    // Reverse the binary digits to get the correct order
    std::reverse(binary_digits.begin(), binary_digits.end());

    return binary_digits;
}


std::vector<std::vector<std::string>> create_table(const std::string& str) {

    std::vector<std::vector<std::string>> table;
    // find all the variables in the string
    std::vector<std::string> variables;
    for (char c : str) {
        if (isSingleLowerAlpha(std::string(1, c)) && std::find(variables.begin(), variables.end(), std::string(1, c)) == variables.end()) {
            variables.push_back(std::string(1, c));
        }
    }

    std::vector<std::string> variable_row;
    for (const auto& var: variables) {
        variable_row.push_back(var);
    }
    table.push_back(variable_row); // Add the header row with variable names
    
    std::vector<std::vector<std::string>> table;
    int num_rows = 1 << variables.size(); // 2^n rows for n variables

    for (int i = 0; i < num_rows; ++i) {
        std::vector<std::string> row;
        std::vector<std::string> digits = int_to_binary(i);
        row.insert(row.end(), digits.begin(), digits.end());
        table.push_back(row);
    }
}


void print_table(const std::vector<std::vector<std::string>>& table) {
    std::string out;
    for (const auto& row : table) {
        for (const auto& cell : row) {
            out.append(cell + " ");
        }
        out.append("\n");
    }

    std::cout << out;
}
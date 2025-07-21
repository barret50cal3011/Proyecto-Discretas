#include <string>
#include <vector>
#include <stdexcept>
#include <algorithm>
#include <iostream>

#include "util.hpp"

#include <fstream>
#include <iostream>

bool isSingleLowerAlpha(const std::string& str) {
    return str.size() == 1 && str[0] >= 'a' && str[0] <= 'z';
}


std::string latex_to_logic(const std::string& latex) {
    std::string logic;
    size_t i = 0;

    while (i < latex.size()) {
        if (latex[i] == '\\') {
            // Detectar comandos de LaTeX
            if (latex.compare(i, 5, "\\lnot") == 0) {
                logic += "!";
                i += 5;
            } else if (latex.compare(i, 5, "\\land") == 0) {
                logic += "&";
                i += 5;
            } else if (latex.compare(i, 4, "\\lor") == 0) {
                logic += "|";
                i += 4;
            } else if (latex.compare(i, 8, "\\implies") == 0) {
                logic += "->";
                i += 8;
            } else if (latex.compare(i, 7, "\\equiv") == 0) {
                logic += "<->";
                i += 7;
            } else {
                // Si no es un comando conocido, solo se agrega el backslash
                logic += "\\";
                i++;
            }
        } else {
            // Agrega directamente cualquier otro carácter (como variables, paréntesis, comas, etc.)
            logic += latex[i];
            i++;
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
    for(char c : str) {
        if (isSingleLowerAlpha(std::string(1, c)) && std::find(variables.begin(), variables.end(), std::string(1, c)) == variables.end()) {
            variables.push_back(std::string(1, c));
        }
    }

    std::vector<std::string> variable_row;
    for(const auto& var: variables) {
        variable_row.push_back(var);
    }
    table.push_back(variable_row); // Add the header row with variable names
    
    std::vector<std::vector<std::string>> table;
    int num_rows = 1 << variables.size(); // 2^n rows for n variables

    for(int i = 0; i < num_rows; i++) {
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


std::string read_file(const std::string& filename) {
    std::ifstream file(filename);
    std::string content;
    if (!file.is_open()) {
        std::cerr << "Error al abrir el archivo: " << filename << std::endl;
        return "";
    }

    std::string line;
    while (std::getline(file, line)) {
        content += line + " ";
    }

    file.close();
    return content;
}


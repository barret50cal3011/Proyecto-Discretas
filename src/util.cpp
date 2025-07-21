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


std::vector<std::string> purge_parentheses(std::vector<std::string> tokens) {

    for (size_t i = 0; i < tokens.size(); ++i) {
        if (tokens[i] == "(" && tokens[i + 1] == "(") {
            for(size_t j = i + 1; j < tokens.size(); ++j) {
                int depth = 1;
                if (tokens[j] == "(") {
                    depth++;
                } else if (tokens[j] == ")") {
                    depth--;
                }
                if (depth == 0 && tokens[j] == ")" && tokens[j - 1] == ")") {
                    // Found the matching closing parenthesis
                    tokens.erase(tokens.begin() + j);
                    tokens.erase(tokens.begin() + i);
                    break;
                }
            }
        }
    }
    return tokens;
}

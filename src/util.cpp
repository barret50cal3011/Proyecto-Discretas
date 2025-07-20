#include <string>
#include <vector>

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


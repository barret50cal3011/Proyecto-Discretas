#include <string>
#include <vector>
#include <iostream>

#include "interpreter.hpp"
#include "util.hpp"

int main() {
    // read file containing LaTeX input
    std::string latex_input = read_file("latex.txt");

    if (latex_input.empty()) {
        std::cerr << "No se pudo leer el archivo de entrada.\n";
        return 1;
    }
    // Display the LaTeX input
    std::cout << "Fórmula LaTeX: " << latex_input << std::endl;
    // Convert LaTeX to logic
    std::string logic_equation = latex_to_logic(latex_input);
    std::cout << "Convertida a lógica: " << logic_equation << std::endl;

    std::vector<std::string> tokened_equation = parseInterpreter(logic_equation);
    std::vector<std::string> tokens_with_parentheses = add_parentheses(tokened_equation);
    std::string result = tokens_to_string(tokens_with_parentheses);

    std::cout << "Parsed and formatted equation: " << result << std::endl;
    std::string result_latex = logic_to_latex(result);
    guardar_resultado_latex(latex_input, result_latex);

    return 0;
}

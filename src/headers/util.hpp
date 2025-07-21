#pragma once

#include <string>

// Checks if the given string is a single lowercase alphabetic character.
// @param str The string to check.
// @return True if the string is a single lowercase letter, false otherwise.
bool isSingleLowerAlpha(const std::string& str);

// Converts a LaTeX formatted string to a logical expression.
// @param latex The LaTeX formatted string to convert.
// @return A string representing the logical expression.
std::string latex_to_logic(const std::string& latex);
std::string read_file(const std::string& filename);
// Converts a logical expression back to LaTeX format.
// @param logic The logical expression to convert.
// @return A string representing the LaTeX formatted expression.
std::string logic_to_latex(const std::string& logic);
// Saves the result in LaTeX format to a file.
void guardar_resultado_latex(const std::string& latex_input, const std::string& result_latex);

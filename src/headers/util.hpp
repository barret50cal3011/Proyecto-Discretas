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

// Converts an int into a binary vector representation.
// @param int that will be converted.
// @return A vector of strings, where each string is a binary digit of the integer.
std::vector<std::string> int_to_binary(int number);

// Reads the contents of a text file into a string.
// @param filename The name of the file to read.
// @return A string containing the contents of the file.
std::string read_file(const std::string& filename);

// Converts a logical expression back to LaTeX format.
// @param logic The logical expression to convert.
// @return A string representing the LaTeX formatted expression.
std::string logic_to_latex(const std::string& logic);
// Saves the result in LaTeX format to a file.
void guardar_resultado_latex(const std::string& latex_input, const std::string& result_latex);


// Removes unecesary parentheses from a logical expression string.
// @param str The string representation of the logical expression.
// @return A string with unnecessary parentheses removed.
// @note This function modifies str.
std::vector<std::string> purge_parentheses(std::vector<std::string> str);




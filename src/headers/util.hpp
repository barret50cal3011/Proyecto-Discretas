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

// Creates a truth table from a given string representation of a logical expression.
// @param str The string representation of the logical expression. String needs to have parentheses added.
// @return A vector of vectors of strings, where each inner vector represents a row in the truth table.
std::vector<std::vector<std::string>> create_table(const std::string& str);

// Prints a truth table to the console.
// @param table The truth table to print, represented as a vector of vectors of strings.
void print_table(const std::vector<std::vector<std::string>>& table);
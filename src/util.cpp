#include <string>
#include <vector>

#include "util.hpp"

bool isSingleLowerAlpha(const std::string& str) {
    return str.size() == 1 && str[0] >= 'a' && str[0] <= 'z';
}


std::string latex_to_logic(const std::string& latex) {
    std::string logic;
    for(int i = 0; i < latex.size(); ++i) {
        if (latex[i] == '\\') {
            if(latex.substr(i, 2) == "\\land") {
                logic += "&"; // Convert \and to &
                i += 1; // Skip the next character
            } else if(latex.substr(i, 2) == "\\lor") {
                logic += "|"; // Convert \or to |
                i += 1; // Skip the next character
            } else if(latex.substr(i, 2) == "\\lnot") {
                logic += "!"; // Convert \not to !
                i += 1; // Skip the next character
            } else if(latex.substr(i, 2) == "\\implies") {
                logic += "->"; // Convert \implies to ->
                i += 1; // Skip the next character
            } else if(latex.substr(i, 3) == "\\equiv") {
                logic += "<->"; // Convert \equiv to <-> 
                i += 2; // Skip the next two characters
            } else if(latex[i] == '\\') {
                logic += '\\'; // Keep the backslash if it's not a recognized command
            }
            
        } else {
            logic += latex[i]; // Add regular characters directly
        }
    }
    return logic;
}
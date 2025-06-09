#include <string>
#include <vector>
#include <stdexcept>

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
#include <string>
#include <vector>

#include "util.hpp"

bool isSingleLowerAlpha(const std::string& str) {
    return str.size() == 1 && str[0] >= 'a' && str[0] <= 'z';
}
//
//  lily.cpp
//  Lily
//
//  Created by Filip Peterek on 17/02/2018.
//  Copyright © 2018 Filip Peterek. All rights reserved.
//

#include "lily.hpp"

using namespace Lily;

std::vector<std::string> _files;

std::vector<std::string> & Lily::files() {
    
    return _files;
    
}

std::array<char, 13> _operatorChars = { '+', '-', '*', '/', '&', '|', '>', '<', '~', '=', '!', '^', '?' };

std::array<char, 13> & Lily::operatorChars() {
    return _operatorChars;
}

std::array<char, 9> _specialChars = { '{', '}', '(', ')', '[', ']', '.', ',', ':' };

std::array<char, 9> & Lily::specialChars() {
    return _specialChars;
}

std::array<std::string, 5> _operators = { "and", "or", "not", "return", "in" };

std::array<std::string, 5> & Lily::operators() {
    return _operators;
}

std::array<std::string, 11> _keywords = { "function", "var", "const", "class", "if", "elif", "else", "while", "for",
    "break", "continue"
};

std::array<std::string, 11> & Lily::keywords() {
    return _keywords;
}

bool Lily::isImported(const std::string & filename) {
    
    return contains(_files, filename);
    
}

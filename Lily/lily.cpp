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

std::array<char, 12> _operatorChars = { '+', '-', '*', '/', '&', '|', '>', '<', '~', '=', '!', '^' };

std::array<char, 12> & Lily::operatorChars() {
    return _operatorChars;
}

std::array<char, 9> _specialChars = { '{', '}', '(', ')', '[', ']', '.', ',', ':' };

std::array<char, 9> & Lily::specialChars() {
    return _specialChars;
}

bool Lily::isImported(const std::string & filename) {
    
    return contains(_files, filename);
    
}

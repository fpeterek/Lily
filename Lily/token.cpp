//
//  token.cpp
//  Lily
//
//  Created by Filip Peterek on 17/02/2018.
//  Copyright © 2018 Filip Peterek. All rights reserved.
//

#include "token.hpp"

using namespace Lily;

token & token::operator=(const token & t) {
    
    value = t.value;
    character = t.character;
    line = t.line;
    file = t.file;
    
    return *this;
    
}

std::ostream & Lily::operator<< (std::ostream & os, const token & t) {
    
    return os << t.value << " [line: " << t.line << ", character: " << t.character << ", file: " << t.file << "]";
    
}

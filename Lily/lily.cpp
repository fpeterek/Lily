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

std::vector<std::string> Lily::files() {
    
    return _files;
    
}

bool Lily::isImported(const std::string & filename) {
    
    for (auto & i : _files) {
        if (filename == i) {
            return true;
        }
    }
    
    return false;
    
}

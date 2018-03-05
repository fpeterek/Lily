//
//  lily.hpp
//  Lily
//
//  Created by Filip Peterek on 17/02/2018.
//  Copyright © 2018 Filip Peterek. All rights reserved.
//

#ifndef lily_hpp
#define lily_hpp

#include <string>
#include <vector>
#include <array>

#include "contains.hpp"

namespace Lily {
    
    std::vector<std::string> & files();
    
    std::array<char, 13> & operatorChars();
    std::array<char, 9> & specialChars();
    
    std::array<std::string, 5> & operators();
    std::array<std::string, 11> & keywords();
    
    bool isImported(const std::string & filename);
    
    
}

#endif /* lily_hpp */

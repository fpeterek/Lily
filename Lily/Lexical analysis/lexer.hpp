//
//  lexer.hpp
//  Lily
//
//  Created by Filip Peterek on 24/02/2018.
//  Copyright © 2018 Filip Peterek. All rights reserved.
//

#ifndef lexer_hpp
#define lexer_hpp

#include <iostream>
#include <vector>

#include "lily.hpp"

#include "token.hpp"
#include "exceptions.hpp"
#include "contains.hpp"

namespace Lily {


    class Lexer {
        
      
    public:
        void lex(std::vector<Lily::token> & tokens);
        
    };
    
}

#endif /* lexer_hpp */

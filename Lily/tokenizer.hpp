//
//  tokenizer.hpp
//  Lily
//
//  Created by Filip Peterek on 17/02/2018.
//  Copyright © 2018 Filip Peterek. All rights reserved.
//

#ifndef tokenizer_hpp
#define tokenizer_hpp

#include <iostream>
#include <fstream>
#include <vector>

#include "lily.hpp"

#include "token.hpp"
#include "exceptions.hpp"

namespace Lily {
    
    class Tokenizer {
        
        std::ifstream stream;
        std::string line;
        std::string tok;
        
        uint32_t lineNumber, character;
        uint32_t file;
        
        size_t iter;
        
        void openFile(const std::string & filename);
        
        std::vector<token> tokenizeLine();
        
        std::vector<token> tokenize();
        
    public:
        
        std::vector<token> tokenize(const std::string & filename);
        
    };
    
}

#endif /* tokenizer_hpp */

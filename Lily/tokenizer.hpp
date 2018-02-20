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
#include "contains.hpp"

namespace Lily {
    
    class Tokenizer {
        
        std::ifstream stream;
        std::string line;
        std::string tok;
        
        uint32_t lineNumber = 0;
        uint32_t file;
        
        size_t iter = 0;
        
        bool isOperatorChar(char c);
        
        void openFile(const std::string & filename);
        
        token number();
        token identifier();
        token oper();
        token specialChar();
        token string();
        
        std::vector<token> tokenizeLine();
        
        std::vector<token> tokenize();
        
    public:
        
        std::vector<token> tokenize(const std::string & filename);
        
    };
    
}

#endif /* tokenizer_hpp */

//
//  tokenizer.cpp
//  Lily
//
//  Created by Filip Peterek on 17/02/2018.
//  Copyright © 2018 Filip Peterek. All rights reserved.
//

#include "tokenizer.hpp"

using namespace Lily;

void Tokenizer::openFile(const std::string & filename) {
    
    if (isImported(filename)) {
        throw lily_error("Error: File is already imported, this shouldn't happen, error should be detected"
                         " earlier.");
    }
    
    files().emplace_back(filename);
    
    file = (uint32_t)files().size() - 1;
    
    stream.open(filename);
    
    if (not stream) {
        throw error_opening_file(filename);
    }
    
}

std::vector<token> Tokenizer::tokenizeLine() {
    
    std::vector<token> tokens;
    
    const size_t lineLength = line.length();
    iter = 0;
    
    while (iter < lineLength) {
        
        
        
    }
    
    return tokens;
    
}

std::vector<token> Tokenizer::tokenize() {
    
    std::vector<token> tokens;
    
    while (not stream.eof()) {
        
        std::getline(stream, line);
        
        std::vector<token> tokLine = tokenizeLine();
        
        tokens.emplace(tokens.end(), tokLine.begin(), tokLine.end());
        
    }
    
    return tokens;
    
}

std::vector<token> Tokenizer::tokenize(const std::string & filename) {
    
    openFile(filename);
    
    return tokenize();
    
}

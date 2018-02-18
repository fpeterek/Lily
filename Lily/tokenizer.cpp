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

token Tokenizer::number() {
    
    token t;
    
    t.character = (uint32_t)iter + 1;
    t.line = lineNumber;
    
    const size_t lineLength = line.length();
    
    bool decimalPointFound = false;
    
    while (iter < lineLength) {
        
        if (isdigit(line[iter])) {
            
            t.value += std::string(1, line[iter]);
            
        } else if (line[iter] == '.' and not decimalPointFound) {
            
            decimalPointFound = true;
            t.value += ".";
            
        } else {
            
            break;
            
        }
        
        ++iter;
        
    }
    
    return t;
    
}

token Tokenizer::identifier() {
    
    token t;
    
    t.character = (uint32_t)iter + 1;
    t.line = lineNumber;
    
    const size_t lineLength = line.length();
    
    while (iter < lineLength) {
        
        if (isalnum(line[iter]) or line[iter] == '_' or line[iter] == '$' or line[iter] == '\'') {
            
            t.value += std::string(1, line[iter]);
            
        } else {
            
            break;
            
        }
        
        ++iter;
        
    }
    
    return t;
    
}

std::vector<token> Tokenizer::tokenizeLine() {
    
    std::vector<token> tokens;
    
    const size_t lineLength = line.length();
    iter = 0;
    ++lineNumber;
    
    while (iter < lineLength) {
        
        if (isspace(line[iter])) {
            ++iter;
            continue;
        }
        else if (isdigit(line[iter])) {
            tokens.emplace_back(number());
        }
        else if (isalpha(line[iter])) {
            tokens.emplace_back(identifier());
        }
        
        
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

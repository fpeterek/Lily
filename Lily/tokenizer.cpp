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

bool Tokenizer::isOperatorChar(char c) {
    
    return contains(operatorChars(), c);
    
}

token Tokenizer::initToken() {
    
    token t;
    
    t.character = (uint32_t)iter + 1;
    t.line = lineNumber;
    t.file = file;
    
    return t;
    
}

token Tokenizer::number() {
    
    token t(initToken());
    
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
    
    if (t.value.back() == '.') {
        t.value.pop_back();
        --iter;
    }
    
    return t;
    
}

token Tokenizer::identifier() {
    
    token t(initToken());
    
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

token Tokenizer::oper() {
    
    token t(initToken());
    
    const size_t lineLength = line.length();
    
    while (iter < lineLength) {
        
        if (isOperatorChar(line[iter])) {
            
            t.value += std::string(1, line[iter]);
            
        } else {
            
            break;
            
        }
        
        ++iter;
        
    }
    
    return t;
    
}

token Tokenizer::specialChar() {
    
    token t(initToken());
    
    t.value = std::string(1, line[iter]);
    
    ++iter;
    
    return t;
    
}

token Tokenizer::string() {
    
    token t(initToken());
    
    ++iter;
    
    t.value = "\"";
    
    const size_t lineLength = line.length();
    
    bool isEscape = false;
    
    
    while ( line[iter] != '"' or isEscape ) {
        
        if ( line[iter] == '\\' ) {
            
            isEscape = not isEscape;
            
            t.value += "\\";
            
        } else {
            
            isEscape = false;
            
            t.value += std::string(1, line[iter]); /* std::string constructor(repeat: int, character: char) */
            
        }
        
        ++iter;
        if (iter >= lineLength) {
            throw missing_token('"');
        }
        
    }
    
    ++iter; /* Last delimiter character */
    t.value += "\"";
    
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
        else if (isalpha(line[iter]) or line[iter] == '_' or line[iter] == '$') {
            tokens.emplace_back(identifier());
        }
        else if (isOperatorChar(line[iter])) {
            tokens.emplace_back(oper());
        }
        else if (contains(specialChars(), line[iter])) {
            tokens.emplace_back(specialChar());
        }
        else if (line[iter] == '"') {
            tokens.emplace_back(string());
        }
        else {
            throw invalid_token(line[iter]);
        }
        
    }
    
    return tokens;
    
}

std::vector<token> Tokenizer::tokenize() {
    
    std::vector<token> tokens;
    
    while (not stream.eof()) {
        
        std::getline(stream, line);
        
        std::vector<token> tokLine = tokenizeLine();
        
        tokens.insert(tokens.end(), tokLine.begin(), tokLine.end());
        
    }
    
    return tokens;
    
}

std::vector<token> Tokenizer::tokenize(const std::string & filename) {
    
    openFile(filename);
    
    return tokenize();
    
}

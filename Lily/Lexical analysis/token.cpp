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
    
    return os << t.value << " [type: " << t.type
              << ", line: " << t.line << ", character: " << t.character
              << ", file: " << t.file << "]";
    
}

std::string Lily::to_string(const TokenType t) {
    
    switch (t) {
    
        case TokenType::IntLiteral:
            return "IntLiteral";
        case TokenType::FloatLiteral:
            return "FloatLiteral";
        case TokenType::StringLiteral:
            return "StringLiteral";
        case TokenType::Operator:
            return "Operator";
        case TokenType::Identifier:
            return "Identifier";
        case TokenType::Keyword:
            return "Keyword";
        case TokenType::OpeningBracket:
            return "OpeningBracket";
        case TokenType::ClosingBracket:
            return "ClosingBracket";
        case TokenType::OpeningBrace:
            return "OpeningBrace";
        case TokenType::ClosingBrace:
            return "ClosingBrace";
        case TokenType::OpeningParen:
            return "OpeningParen";
        case TokenType::ClosingParen:
            return "ClosingParen";
        case TokenType::Colon:
            return "ClosingParen";
        case TokenType::Separator:
            return "Separator";
        default:
            return "None";
            
    }
    
}

std::ostream & Lily::operator<< (std::ostream & os, const TokenType type) {
    return os << to_string(type);
}

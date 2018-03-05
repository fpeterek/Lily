//
//  token.hpp
//  Lily
//
//  Created by Filip Peterek on 17/02/2018.
//  Copyright © 2018 Filip Peterek. All rights reserved.
//

#ifndef token_hpp
#define token_hpp

#include <string>
#include <ostream>

namespace Lily {
    
    enum class TokenType {
      
        IntLiteral,
        FloatLiteral,
        StringLiteral,
        Operator,
        Identifier,
        Keyword,
        
        OpeningBracket,
        ClosingBracket,
        OpeningBrace,
        ClosingBrace,
        OpeningParen,
        ClosingParen,
        Colon,
        Separator,
        
        None
        
    };
    
    std::string to_string(const TokenType t);
    
    struct token {
        
        std::string value;
        
        uint32_t file;
        uint32_t line, character;
        
        TokenType type;
        
        token & operator=(const token & t);
        
    };
    
    std::ostream & operator<< (std::ostream & os, const token & t);
    std::ostream & operator<< (std::ostream & os, const TokenType type);
}

#endif /* token_hpp */

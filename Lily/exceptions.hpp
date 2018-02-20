//
//  exceptions.hpp
//  Lily
//
//  Created by Filip Peterek on 17/02/2018.
//  Copyright © 2018 Filip Peterek. All rights reserved.
//

#ifndef exceptions_hpp
#define exceptions_hpp

#include <string>

namespace Lily {
    
    class lily_error : public std::runtime_error {
        
    public:
        lily_error(const std::string & message);
        
    };
    
    class lily_error_1param : public lily_error {
      
    public:
        lily_error_1param(const std::string & message, const std::string & param);
        
    };
    
    class error_opening_file : public lily_error_1param {
      
        static std::string message;
    public:
        error_opening_file(const std::string & filename);
        
    };
    
    class missing_token : public lily_error_1param {
        
        static std::string message;
    public:
        missing_token(const std::string & token);
        missing_token(char token);
    };
    
}

#endif /* exceptions_hpp */

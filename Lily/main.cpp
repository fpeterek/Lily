//
//  main.cpp
//  Lily
//
//  Created by Filip Peterek on 17/02/2018.
//  Copyright © 2018 Filip Peterek. All rights reserved.
//

#include <iostream>

#include "tokenizer.hpp"

int main(int argc, const char * argv[]) {
    
    std::cout << "Hello, Lily!\n";
    
    Lily::Tokenizer t;
    
    try {
        
        std::vector<Lily::token> tokens = t.tokenize("lily.ll");
        
        for (auto & i : tokens) {
            std::cout << i << std::endl;
        }
        
    } catch (const std::runtime_error & e) {
        
        std::cout << e.what() << std::endl;
        
    }
    
    
    
}

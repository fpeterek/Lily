//
//  exceptions.cpp
//  Lily
//
//  Created by Filip Peterek on 17/02/2018.
//  Copyright © 2018 Filip Peterek. All rights reserved.
//

#include "exceptions.hpp"

using namespace Lily;

lily_error::lily_error(const std::string & message) : std::runtime_error("Lily Error: " + message) { }

lily_error_1param::lily_error_1param(const std::string & message,
                                     const std::string & param) : lily_error(message + param) { }

std::string error_opening_file::message = "Error opening file ";
error_opening_file::error_opening_file(const std::string & filename) : lily_error_1param(message, filename) { }


std::string missing_token::message = "Missing token: ";
missing_token::missing_token(const std::string & token) : lily_error_1param(message, token) { }
missing_token::missing_token(char token) : lily_error_1param(message, std::string(1, token)) { }

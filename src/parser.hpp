#pragma once
#include <vector>
#include <memory>
#include <string>
#include "token.hpp" 
#include "ast.hpp"

class Parser {
    public:
        Parser(const std::vector<token::Token>& tokens);

        std::unique_ptr<Exp> parse();

    private:
        const std::vector<token::Token>& tokens;
        int current = 0; 

        std::unique_ptr<Exp> analisaExp();
        Operador analisaOperador();

        bool match(token::type type);      
        bool check(token::type type);      
        token::Token advance();           
        token::Token peek();               
        token::Token previous();          
        bool isAtEnd();                    
        
        [[noreturn]] void error(const std::string& message);
};
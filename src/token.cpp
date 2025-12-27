#include "token.hpp"

#include <sstream>


namespace token{

    std::vector<token::Token> parseInput(std::string str, int line){
        std::vector<token::Token> tokens;
        for (int position = 0; position < str.size(); position++){
            if (isdigit(str[position])){
                std::string numeroStr;
                int startPos = position;

                while (position < str.size() && isdigit(str[position])){
                    numeroStr += str[position];
                    position++;
                }

                position--;

                token::Token token(numeroStr, startPos, line);
                token.tipo = token::Numero;
                tokens.push_back(token);

                continue;
            }

            token::Token token(std::string(1, str[position]), position, line);


            switch(str[position]){
                case '#':{
                    token.tipo = token::Coment;
                    return tokens;
                }

                case '(':{
                    token.tipo = token::ParenEsq;
                    break;
                }

                case ')':{
                    token.tipo = token::ParenDir;
                    break;
                }

                case '+':{
                    token.tipo = token::Soma;
                    break;
                }

                case '-':{
                    token.tipo = token::Sub;
                    break;
                }

                case '*':{
                    token.tipo = token::Mult;
                    break;
                }

                case '/':{
                    token.tipo = token::Div;
                    break;
                }
                
                case '\n':
                case ' ':{
                    continue;
                }

                default:{
                    std::stringstream ss;
                    ss << "Coluna " << position + 1;
                    throw std::runtime_error(ss.str());
                }
            }

            tokens.push_back(token);
        }

        return tokens;
    }

    std::ostream& operator<<(std::ostream &os, const Token& str)
    { 
        os << "<" << typesString[str.tipo] << ", \"" << str.lexema << "\", " << "Linha: " << str.linha << " Coluna: " << str.coluna << ">";

        return os; 
    } 
}


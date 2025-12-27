#pragma once
#include <iostream>
#include <string>
#include <vector>

namespace token{
    enum type{
        ParenEsq,
        ParenDir,
        Numero,
        Soma,
        Sub,
        Mult,
        Div,
        Coment
    };

    const std::string_view typesString[] = {
        "ParenEsq",
        "ParenDir",
        "Numero",
        "Soma",
        "Sub",
        "Mult",
        "Div",
        "Coment"
    };


    class Token{
        public:
            type tipo;
            std::string lexema;
            int coluna;
            int linha;

            Token();
            Token(std::string lexema, int coluna, int linha){
                this->lexema = lexema;
                this->coluna = coluna;
                this->linha = linha;
            }

    };
    std::vector<token::Token> parseInput(std::string str, int line);

    std::ostream& operator<<(std::ostream &os, const Token& str);
}
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "token.hpp"
#include "parser.hpp"
#include "ast.hpp"

int main(int argc, char* argv[]){
    if (argc != 2){
        std::cout << "Uso: ./programa <arquivo_teste>" << std::endl;
        return -1;
    }

    std::string fileName = argv[1];
    std::ifstream readFile(fileName);

    if (!readFile.is_open()) {
        std::cout << "Nao foi possivel abrir o arquivo " << fileName << std::endl;
        return -1;
    }

    std::string myText;
    int line = 0;
    std::vector<token::Token> allTokens;

    while (std::getline(readFile, myText)){
        try{
            auto temp_tokens = token::parseInput(myText, line); // Pega todos os tokens na linha
            allTokens.insert(allTokens.end(), temp_tokens.begin(), temp_tokens.end()); //E dá o append no vetor de Tokens
        }
        catch (std::exception& e){
            std::cout << "Erro lexico na Linha " << line + 1 << ": " << e.what() << std::endl;
            return -1;
        }
        line += 1;
    }

    try {
        if (allTokens.empty()) {
            return 0;
        }

        Parser parser(allTokens);
        std::unique_ptr<Exp> tree = parser.parse(); //Parseia a expressão

        std::cout << "Expressao: ";
        tree->print(); // Printa
        std::cout << std::endl;

        std::cout << "Resultado: " << tree->eval() << std::endl;
    }
    catch (const std::exception& e) { // Se houve algum erro na Análise sintática, cairá nessa exceção
        std::cout << e.what() << std::endl;
        return -1;
    }

    return 0;
}
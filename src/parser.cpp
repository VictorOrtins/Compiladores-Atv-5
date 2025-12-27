#include "parser.hpp"
#include <stdexcept>
#include <sstream>

Parser::Parser(const std::vector<token::Token>& tokens) : tokens(tokens) {}

std::unique_ptr<Exp> Parser::parse() {
    auto result = analisaExp(); // Tenta analisar a expressão

    if (!isAtEnd()) { // Se não tem mais o que analisar mas a expressão não chegou ao fim, erro
        error("Tokens inesperados após o fim da expressão.");
    }
    return result;
}

std::unique_ptr<Exp> Parser::analisaExp() {
    if (match(token::Numero)) { // Se for um número, sempre retorna um número
        int valor = std::stoi(previous().lexema);
        return std::make_unique<Const>(valor);
    }

    if (match(token::ParenEsq)) {
        auto esq = analisaExp(); // Analisa a expressão à esquerda (recursivo)

        Operador op = analisaOperador(); // Analisa o operador

        auto dir = analisaExp(); // Analisa a expressão à direita (recursivo)

        if (!match(token::ParenDir)) {
            error("Esperado ')' após expressão.");
        }

        return std::make_unique<OpBin>(op, std::move(esq), std::move(dir));
    }

    error("Esperado número ou '(' no início da expressão.");
}

Operador Parser::analisaOperador() {
    if (match(token::Soma)) return SOMA;
    if (match(token::Sub))  return SUBTRACAO;
    if (match(token::Mult)) return MULTIPLICACAO;
    if (match(token::Div))  return DIVISAO;

    error("Operador esperado (+, -, *, /).");
}

bool Parser::match(token::type type) {
    if (check(type)) {
        advance();
        return true;
    }
    return false;
}

bool Parser::check(token::type type) {
    if (isAtEnd()) return false;
    return peek().tipo == type;
}

token::Token Parser::advance() {
    if (!isAtEnd()) current++;
    return previous();
}

token::Token Parser::peek() {
    return tokens[current];
}

token::Token Parser::previous() {
    return tokens[current - 1];
}

bool Parser::isAtEnd() {
    return current >= tokens.size();
}

void Parser::error(const std::string& message) { // Indica onde houve o erro
    int linha = 0, coluna = 0;
    if (current < tokens.size()) {
        linha = peek().linha;
        coluna = peek().coluna;
    } else if (!tokens.empty()) {
        linha = tokens.back().linha;
        coluna = tokens.back().coluna;
    }

    std::stringstream ss;
    ss << "Erro Sintático [Linha " << linha << ", Coluna " << coluna << "]: " << message;
    throw std::runtime_error(ss.str());
}
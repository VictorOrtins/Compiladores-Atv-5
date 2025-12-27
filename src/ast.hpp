#pragma once
#include <iostream>
#include <string>
#include <memory>

enum Operador {
    SOMA,
    SUBTRACAO,
    MULTIPLICACAO,
    DIVISAO
}; // Representação dos operadores para evitar strings

class Exp { // Classe que representa um nó da árvore
public:
    virtual ~Exp() = default;
    virtual void print() = 0;
    virtual int eval() = 0;
};

class Const : public Exp { // Um valor constante presente na árvore
public:
    int value;

    Const(int v);
    void print() override;
    int eval() override;
};

class OpBin : public Exp { // Um operador binário (+, -, *, /) presente na árvore
public:
    Operador op;
    std::unique_ptr<Exp> esq;
    std::unique_ptr<Exp> dir;

    OpBin(Operador o, std::unique_ptr<Exp> e, std::unique_ptr<Exp> d);
    void print() override;
    int eval() override;
};
#include "ast.hpp"
#include <iostream>

Const::Const(int v) : value(v) {}

void Const::print() {
    std::cout << value;
}

int Const::eval() { // A "avaliação" do seu valor é o próprio valor
    return value;
}

OpBin::OpBin(Operador o, std::unique_ptr<Exp> e, std::unique_ptr<Exp> d) 
    : op(o), esq(std::move(e)), dir(std::move(d)) {} // Recebe os operadores da direita e da esquerda deles
                                                     // e os move para os objetos da própria classe

void OpBin::print() {
    std::cout << "(";
    esq->print();
    
    switch (op) {
        case SOMA: std::cout << " + "; break;
        case SUBTRACAO: std::cout << " - "; break;
        case MULTIPLICACAO: std::cout << " * "; break;
        case DIVISAO: std::cout << " / "; break;
    } 

    dir->print();
    std::cout << ")";
}

int OpBin::eval() { // A "avaliação" do seu valor é o valor da operação entre os 2 valores à sua direita e esquerda
    int v1 = esq->eval();
    int v2 = dir->eval();

    switch (op) {
        case SOMA: return v1 + v2;
        case SUBTRACAO: return v1 - v2;
        case MULTIPLICACAO: return v1 * v2;
        case DIVISAO: 
            if (v2 != 0) return v1 / v2;
            else return 0; 
    }
    return 0;
}
# Interpretador da Linguagem EC1

Este projeto implementa um compilador completo (Frontend + Interpretador) para a linguagem EC1 (Expressões Constantes 1). O sistema realiza a análise léxica, análise sintática (gerando uma Árvore de Sintaxe Abstrata - AST) e a interpretação direta da árvore para calcular o resultado das expressões.

## Estrutura do Projeto

- **src/**: Contém todo o código-fonte C++ do projeto.
  - `main.cpp`: Ponto de entrada, orquestra a leitura, parsing e execução.
  - `token.*`: Implementação do Analisador Léxico.
  - `parser.*`: Implementação do Analisador Sintático (Descendente Recursivo).
  - `ast.*`: Definição e lógica da Árvore de Sintaxe Abstrata e Interpretador.
- **testes/**: Arquivos de texto com exemplos de expressões EC1.

## Requisitos

- Compilador C++ com suporte ao padrão C++14 ou superior (devido ao uso de `std::make_unique`).
  - Recomendado: `g++` ou `clang++`.

## Como Compilar

Navegue até a raiz do projeto (onde este README está localizado) e execute o comando abaixo para compilar todos os arquivos da pasta `src`:

```bash
g++ src/*.cpp -o compilador
```

## Integrantes

- **ÊMILLY EDUARDA CAROLINY SILVA** — 20220166942
- **LUIZ MANOEL BARBOSA RAMALHO** — 20220096614  
- **REUBEN LISBOA RAMALHO CLAUDINO** — 20210024602  
- **VICTOR PESSOA OLIVEIRA ORTINS** — 20210024667  

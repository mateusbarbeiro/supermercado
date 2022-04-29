#ifndef SUPERMERCADO_PRODUTO_H
#define SUPERMERCADO_PRODUTO_H

#include <string>

class Produto {
private:
    int id;
    std::string nome;
    double valor;
    int quantidade;
public:
    explicit Produto() {}

    std::string getNomeProduto();
    static char opcoesMenuProduto();
    static Produto cadastrarProduto();
    static void alterarProduto();
    static void deletarProduto();
    static void visualizarProduto();
    static Produto *getProdutoById();
    static Produto *getProdutoById(int id);
};


#endif //SUPERMERCADO_PRODUTO_H

#ifndef SUPERMERCADO_PRODUTO_H
#define SUPERMERCADO_PRODUTO_H

#include <string>
#include <cstring>


class Produto {
private:
    int id;
    char nome[50];
    float preco;
    int quantidade;
public:
    explicit Produto() {};

    inline bool operator==(const Produto &outro) const {
        return outro.id == this->id;
    }

    std::string getNomeProduto();

    int getIdProduto();

    static char opcoesMenuProduto();

    static void cadastrarProduto();

    static void alterarProduto();

    static void deletarProduto();

    static void visualizarProduto();

    static Produto getProdutoById();

    static Produto getProdutoById(int id);

    std::string toSting();

    static void recriaArquivo(Produto produtoIn, bool isAlteracao);

    float getPrecoProduto();

    void realizaSaida(int quantidade);
};


#endif //SUPERMERCADO_PRODUTO_H

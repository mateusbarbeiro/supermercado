#ifndef VIDEOLOCADORA_CLIENTE_H
#define VIDEOLOCADORA_CLIENTE_H

#include <iostream>
#include <list>

class Cliente {
private:
    int id;
    char nome[50];
    float valor = 0.0;

public:
    explicit Cliente() {

    };

    inline bool operator==(const Cliente &outro) const {
        return outro.id == this->id;
    }

    std::string getNomeCliente();

    int getIdCliente() const;

    static char opcoesMenuCliente();

    static void cadastrarCliente();

    static void alterarCliente();

    static void deletarCliente();

    static void visualizarCliente();

    static Cliente getClienteById();

    static Cliente getClienteById(int id);

    std::string toSting();

    static void recriaArquivo(Cliente clienteIn, bool isAlteracao);

    static void alterarCliente(int id);

    void realizaCompra(float valorGasto);
};

#endif //VIDEOLOCADORA_CLIENTE_H

#ifndef VIDEOLOCADORA_CLIENTE_H
#define VIDEOLOCADORA_CLIENTE_H

#include <iostream>
#include <list>

class Cliente {
private:
    int id;
    char nome[50];
    float valor;

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
};

#endif //VIDEOLOCADORA_CLIENTE_H

#ifndef VIDEOLOCADORA_CLIENTE_H
#define VIDEOLOCADORA_CLIENTE_H
#include <iostream>
#include <list>

class Cliente{
private:
    int id;
    std::string nome;
    std::string sexo;

public:
    explicit Cliente() {};

    inline bool operator==(const Cliente &outro) const
    {
        return outro.id == this->id;
    }

    std::string getNomeCliente();
    static char opcoesMenuCliente();
    static Cliente cadastrarCliente();
    static void alterarCliente();
    static void deletarCliente();
    static void visualizarCliente();
    static Cliente *getClienteById();
    static Cliente *getClienteById(int id);
};

#endif //VIDEOLOCADORA_CLIENTE_H

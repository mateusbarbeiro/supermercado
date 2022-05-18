#ifndef VIDEOLOCADORA_CLIENTE_H
#define VIDEOLOCADORA_CLIENTE_H
#include <iostream>
#include <list>

class Cliente{
private:
    int id;
    std::string nome;
    float valor;

public:
    explicit Cliente() {};

    inline bool operator==(const Cliente &outro) const
    {
        return outro.id == this->id;
    }

    std::string getNomeCliente();
    static char opcoesMenuCliente();
    static void cadastrarCliente();
    static void alterarCliente();
    static void deletarCliente();
    static void visualizarCliente();
    static Cliente *getClienteById();
    static Cliente *getClienteById(int id);
    std:: string toSting();
};

#endif //VIDEOLOCADORA_CLIENTE_H

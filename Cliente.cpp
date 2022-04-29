#include <iostream>
#include <windows.h>
#include <memory>
//#include <algorithm>
#include "Cliente.h"
#include "MenuOpcoes.h"

char Cliente::opcoesMenuCliente() {
    char opcao;
    while (true) {
        scanf(" %c", &opcao);
        fflush(stdin);
        switch (opcao) {
            case '1': {
                Cliente cli = cadastrarCliente();
//                listaClientes.push_back(cli);
                std::cout << "Cliente Cadastrado" << std::endl;
                system("cls");
                MenuDefault::menuGenericOpcoes("Clientes");
                break;
            }
            case '2': {
                alterarCliente();
                std::cout << "Cliente Alterado" << std::endl;
                system("cls");
                MenuDefault::menuGenericOpcoes("Clientes");
                break;
            }
            case '3': {
                deletarCliente();
                std::cout << "Cliente Apagado" << std::endl;
                system("cls");
                MenuDefault::menuGenericOpcoes("Clientes");
                break;
            }
            case '4': {
                visualizarCliente();
                system("cls");
                MenuDefault::menuGenericOpcoes("Clientes");
                break;
            }
            case '5': {
                std::cout << "Voltando ..." << std::endl;
                MenuDefault::menuPrincipal();
                return opcao;
            }
            default: {
                std::cout << "Opcao Invalida !!!! \n\n";
                MenuDefault::menuGenericOpcoes("Clientes");
            }
        }
    }
}

Cliente Cliente::cadastrarCliente() {
    SYSTEMTIME str_t;
    GetSystemTime(&str_t);
    Cliente cliente;
    do {
        std::cout << "Digite Nome do Cliente" << std::endl;
        std::getline(std::cin, cliente.nome);
    } while (sizeof(cliente.nome) <= 3);
//    do {
//        std::cout << "Digite o Sexo - F ou M" << std::endl;
//        std::cin >> cliente.sexo;
//    } while (cliente.sexo.length() >= 2);
//
//    idCount++;

//    return cliente;
    return Cliente();
}

void Cliente::visualizarCliente() {
    std::cout << "Lista de Clientes\n" << std::endl;
//    for (auto &itemLista: listaClientes) {
//        std::cout << "Id: " << itemLista.id << std::endl;
//        std::cout << "Nome: " << itemLista.nome << std::endl;
//        std::cout << "Sexo: " << itemLista.sexo << "\n" << std::endl;
//    }
}

void Cliente::deletarCliente() {
    visualizarCliente();
    int id;
    std::cout << "Informe o id do Cliente que deseja Apagar" << std::endl;
    std::cin >> id;
//    listaClientes.erase(std::remove(listaClientes.begin(), listaClientes.end(), Cliente(id)));
}

void Cliente::alterarCliente() {
    visualizarCliente();
    int id;

    std::cout << "Informe o Id do Cliente que deseja alterar" << std::endl;
    cin >> id;

//    for (auto &itemLista: listaClientes) {
//        if (itemLista.id == id) {
//            std::cout << "Digite Nome do Cliente" << std::endl;
//            std::cin >> itemLista.nome;
//            std::cout << "Digite o Sexo - F ou M" << std::endl;
//            std::cin >> itemLista.sexo;
//        }
//    }
}

Cliente *Cliente::getClienteById() {
    int id;
    std::cout << "Selecione o Id do Cliente: " << std::endl;
    std::cin >> id;

    return getClienteById(id);
}

Cliente *Cliente::getClienteById(int id) {
    std::list<Cliente>::iterator it;
//    it = std::find(listaClientes.begin(), listaClientes.end(), Cliente(id));
//    if (it != listaClientes.end())
//        return &*it;
//    else
//        throw std::invalid_argument( "Cliente não encontrado." );
}

std::string Cliente::getNomeCliente() {
    return nome;
}


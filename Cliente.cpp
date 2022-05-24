#include <iostream>
#include <memory>
#include <fstream>
#include <cstdio>
#include "Cliente.h"
#include "MenuOpcoes.h"

char Cliente::opcoesMenuCliente() {
    char opcao;
    while (true) {
        scanf(" %c", &opcao);
        fflush(stdin);
        switch (opcao) {
            case '1': {
                cadastrarCliente();
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

void Cliente::cadastrarCliente() {
    FILE *fio;
    fio = fopen("clientes.bin","ab");
    Cliente cliente;
    do {
        std::string id;
        std::cout << "Id do Cliente" << std::endl;
        std::getline(std::cin, id);
        cliente.id = std::stoi(id);

        std::cout << "Digite Nome do Cliente" << std::endl;
        std::getline(std::cin, cliente.nome);
    } while (sizeof(cliente.nome) <= 3);

    fwrite(&cliente, sizeof(Cliente), 1, fio);
    fclose(fio);
}

void Cliente::visualizarCliente() {
    std::cout << "Lista de Clientes\n" << std::endl;
    FILE *fio;
    fio = fopen("clientes.bin","rb");
    Cliente cliente;
    while (true) {
        fread(&cliente, sizeof(Cliente), 1, fio);

        if(feof(fio)){
            break;
        }

        std::cout << "Id: " << cliente.id << std::endl;
        std::cout << "Nome: " << cliente.nome << std::endl;

    }
    fclose(fio);
}

void Cliente::deletarCliente() {
    visualizarCliente();
    int id;
    std::cout << "Informe o id do Cliente que deseja Apagar" << std::endl;
    std::cin >> id;
    Cliente cli = getClienteById(id);

    recriaArquivo(cli, false);
}

void Cliente::alterarCliente() {
    visualizarCliente();
    int id;

    std::cout << "Informe o Id do Cliente que deseja alterar" << std::endl;
    cin >> id;
    Cliente cli = getClienteById(id);
    std::cout << "Digite Nome do Cliente" << std::endl;
    std::cin >> cli.nome;

    recriaArquivo(cli, true);
}

Cliente Cliente::getClienteById() {
    int id;
    std::cout << "Selecione o Id do Cliente: " << std::endl;
    std::cin >> id;

    return getClienteById(id);
}

Cliente Cliente::getClienteById(int id) {
    fstream fio;
    Cliente cliente;
    fio.open("a:clientes.bin", ios::ate | ios::out | ios::in);
    fio.seekg(0);
    while (fio.read((char *)&cliente, sizeof(Cliente))) {
        return cliente;
    }
    fio.close();
    return cliente;
}

std::string Cliente::getNomeCliente() {
    return nome;
}

std::string Cliente::toSting() {
    return to_string(this->id) + "," + this->nome + ',' + to_string(this->valor);
}

int Cliente::getIdCliente() {
    return this->id;
}

void Cliente::recriaArquivo(Cliente clienteIn, bool isAlteracao) {
    FILE *fio;
    fio = fopen("clientes.bin","r+b");

    FILE *fioTemp;
    fioTemp = fopen("temp.bin","wb");

    fopen("clientes.bin", "r+b");
    fopen("temp.bin", "r+b");

    Cliente clienteArq;
    while (true) {

        fread(&clienteArq, sizeof(Cliente), 1, fio);
        if (clienteArq.getIdCliente() == clienteIn.getIdCliente()) {
            if (isAlteracao) {
                fwrite(&clienteIn, sizeof(Cliente), 1, fioTemp);
            }
        } else {
            fwrite(&clienteArq, sizeof(Cliente), 1, fioTemp);
        }
        if(feof(fio)){
            break;
        }
    }

    fclose(fioTemp);
    fclose(fio);
    rename("temp.bin", "clientes.bin");
}


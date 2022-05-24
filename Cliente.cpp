#include <iostream>
#include <memory>
#include <stdio.h>
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

    std::string id;
    std::cout << "Id do Cliente" << std::endl;
    std::getline(std::cin, id);
    cliente.id = std::stoi(id);
    std::cout << "Digite Nome do Cliente" << std::endl;
    scanf("%s", &cliente.nome);

    fwrite(&cliente, sizeof(cliente), 1, fio);
    fclose(fio);
}

void Cliente::visualizarCliente() {
    std::cout << "Lista de Clientes\n" << std::endl;
    FILE *fio;
    fio = fopen("clientes.bin","rb");
    Cliente cliente;

    fseek(fio, 0, SEEK_SET);

    while (true) {
        fread(&cliente, sizeof(cliente), 1, fio);

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
    Cliente cli = getClienteById();

    recriaArquivo(cli, false);
}

void Cliente::alterarCliente() {
    visualizarCliente();
    Cliente updatedCli;
    Cliente cli = getClienteById();

    updatedCli.id = cli.id;
    std::cout << "Digite Nome do Cliente" << std::endl;
    scanf("%s", &updatedCli.nome);

    recriaArquivo(updatedCli, true);
}

Cliente Cliente::getClienteById() {
    int id;
    std::cout << "Selecione o Id do Cliente: " << std::endl;
    std::cin >> id;

    return getClienteById(id);
}

Cliente Cliente::getClienteById(int id) {
    FILE *fio;
    Cliente cliente;

    fio = fopen("clientes.bin","rb");
    fseek(fio, 0, SEEK_SET);

    while (true){
        fread(&cliente, sizeof(cliente), 1, fio);
        if (feof(fio)){
            break;
        }
        if (cliente.getIdCliente() == id){
            fclose(fio);
            return cliente;
        }
    }

    fclose(fio);
    return cliente;
}

std::string Cliente::getNomeCliente() {
    return nome;
}

std::string Cliente::toSting() {
    return to_string(this->id) + "," + this->nome + ',' + to_string(this->valor);
}

int Cliente::getIdCliente() const {
    return this->id;
}

void Cliente::recriaArquivo(Cliente clienteIn, bool isAlteracao) {
    FILE *fio;
    FILE *fioTemp;

    fio = fopen("clientes.bin","rb");
    fioTemp = fopen("temp.bin","ab");

    Cliente clienteArq;
    while (true) {
        fread(&clienteArq, sizeof(Cliente), 1, fio);

        if(feof(fio)){
            break;
        }

        if (clienteArq.getIdCliente() == clienteIn.getIdCliente()) {
            if (isAlteracao) {
                fwrite(&clienteIn, sizeof(clienteIn), 1, fioTemp);
            }
        } else {
            fwrite(&clienteArq, sizeof(clienteArq), 1, fioTemp);
        }
    }

    fclose(fioTemp);
    fclose(fio);
    remove("clientes.bin");
    rename("temp.bin", "clientes.bin");
}


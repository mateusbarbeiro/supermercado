#include <iostream>
#include <memory>
#include <stdio.h>
#include "Produto.h"
#include "MenuOpcoes.h"

char Produto::opcoesMenuProduto() {
    char opcao;
    while (true) {
        scanf(" %c", &opcao);
        fflush(stdin);
        switch (opcao) {
            case '1': {
                cadastrarProduto();
                std::cout << "Produto Cadastrado" << std::endl;
                system("cls");
                MenuDefault::menuGenericOpcoes("Produtos");
                break;
            }
            case '2': {
                alterarProduto();
                std::cout << "Produto Alterado" << std::endl;
                system("cls");
                MenuDefault::menuGenericOpcoes("Produtos");
                break;
            }
            case '3': {
                deletarProduto();
                std::cout << "Produto Apagado" << std::endl;
                system("cls");
                MenuDefault::menuGenericOpcoes("Produtos");
                break;
            }
            case '4': {
                visualizarProduto();
                system("cls");
                MenuDefault::menuGenericOpcoes("Produtos");
                break;
            }
            case '5': {
                std::cout << "Voltando ..." << std::endl;
                MenuDefault::menuPrincipal();
                return opcao;
            }
            default: {
                std::cout << "Opcao Invalida !!!! \n\n";
                MenuDefault::menuGenericOpcoes("Produtos");
            }
        }
    }
}

void Produto::cadastrarProduto() {
    FILE *fio;
    fio = fopen("produtos.bin", "ab");
    Produto produto;
    do {
        std::string id;
        std::cout << "Id do Produto" << std::endl;
        std::getline(std::cin, id);
        produto.id = std::stoi(id);

        std::cout << "Digite Nome do Produto" << std::endl;
        scanf("%s", &produto.nome);

    } while (sizeof(produto.nome) <= 3);

    do {
        std::cout << "Digite Preco do Produto" << std::endl;
        std::cin >> produto.preco;
    } while (produto.preco <= 0);

    fwrite(&produto, sizeof(Produto), 1, fio);
    fclose(fio);
}

void Produto::visualizarProduto() {
    std::cout << "Lista de Produtos\n" << std::endl;
    FILE *fio;
    fio = fopen("produtos.bin", "rb");
    Produto produto;
    while (true) {
        fread(&produto, sizeof(Produto), 1, fio);

        if (feof(fio)) {
            break;
        }

        std::cout << "Id: " << produto.id << std::endl;
        std::cout << "Nome: " << produto.nome << std::endl;
        std::cout << "Preco: " << produto.preco << std::endl;
    }
    fclose(fio);
}

void Produto::deletarProduto() {
    visualizarProduto();
    int id;
    std::cout << "Informe o id do Produto que deseja Apagar" << std::endl;
    std::cin >> id;
    Produto prod = getProdutoById(id);

    recriaArquivo(prod, false);
}

void Produto::alterarProduto() {
    visualizarProduto();
    Produto updatedProd;
    Produto prod = getProdutoById();

    updatedProd.id = prod.id;
    std::cout << "Digite Nome do Produto" << std::endl;
    scanf("%s", &updatedProd.nome);
    std::cout << "Digite Preco do Produto" << std::endl;
    std::cin >> updatedProd.preco;
    recriaArquivo(updatedProd, true);
}

Produto Produto::getProdutoById() {
    int id;
    std::cout << "Selecione o Id do Produto: " << std::endl;
    std::cin >> id;

    return getProdutoById(id);
}

Produto Produto::getProdutoById(int id) {
    FILE *fio;
    Produto produto;

    fio = fopen("produtos.bin", "rb");
    fseek(fio, 0, SEEK_SET);

    while (true) {
        fread(&produto, sizeof(produto), 1, fio);
        if (feof(fio)) {
            break;
        }
        if (produto.getIdProduto() == id) {
            fclose(fio);
            return produto;
        }
    }

    fclose(fio);
    return produto;
}

std::string Produto::getNomeProduto() {
    return nome;
}

std::string Produto::toSting() {
    return to_string(this->id) + "," + this->nome + ',' + to_string(this->preco);
}

int Produto::getIdProduto() {
    return this->id;
}

void Produto::recriaArquivo(Produto produtoIn, bool isAlteracao) {
    FILE *fio;
    FILE *fioTemp;

    fio = fopen("produtos.bin", "rb");
    fioTemp = fopen("temp.bin", "ab");

    Produto produtoArq;
    while (true) {
        fread(&produtoArq, sizeof(Produto), 1, fio);

        if (feof(fio)) {
            break;
        }

        if (produtoArq.getIdProduto() == produtoIn.getIdProduto()) {
            if (isAlteracao) {
                fwrite(&produtoIn, sizeof(produtoIn), 1, fioTemp);
            }
        } else {
            fwrite(&produtoArq, sizeof(produtoArq), 1, fioTemp);
        }
    }

    fclose(fioTemp);
    fclose(fio);
    remove("produtos.bin");
    rename("temp.bin", "produtos.bin");
}


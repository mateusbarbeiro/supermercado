#include <fstream>
#include "FileManager.h"
#include "MenuOpcoes.h"
#include "MenuPrincipal.h"
#include "Cliente.h"
#include "Produto.h"

using namespace std;

list<Cliente> clientes;
list<Produto> produtos;

void carregaArquivoProduto() {
    fstream fio;
    Produto produto;
    fio.open("a:produtos.dat", ios::ate | ios::out | ios::in);
    fio.seekg(0);
    while (fio.read((char *)&produto, sizeof(Produto)))
        produtos.push_back(produto);
    fio.close();
    return;
}

void carregaArquivoCliente() {
    fstream fio;
    Cliente cliente;
    fio.open("a:clientes.dat", ios::ate | ios::out | ios::in);
    fio.seekg(0);
    while (fio.read((char *)&cliente, sizeof(Cliente)))
        clientes.push_back(cliente);
    fio.close();
    return;
}

void carregaArquivos() {
    carregaArquivoCliente();
    carregaArquivoProduto();
}

int main() {

    carregaArquivos();
    char op;
    MenuDefault::menuPrincipal();
    op = MenuPrincipal::opcoes();
    cout <<"Você selecionou Opção de FIM DO SISTEMA : " << op;

    return 0;
}
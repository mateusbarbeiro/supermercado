#include "MenuPrincipal.h"
#include <iostream>
#include "MenuOpcoes.h"
#include "Cliente.h"
#include "Produto.h"
#include "Venda.h"

char MenuPrincipal::opcoes() {
    char opcao;
    while (true){
        scanf(" %c", &opcao);
        fflush(stdin);
        switch (opcao) {
            case '1':
                system("cls");
                MenuDefault::menuGenericOpcoes("Clientes");
                opcao = Cliente::opcoesMenuCliente();
                break;
            case '2':
                system("cls");
                MenuDefault::menuGenericOpcoes("Produtos");
                opcao = Produto::opcoesMenuProduto();;
                break;
            case '3':
                system("cls");
                MenuDefault::menuVenda();
                opcao = Venda::opcoesMenuVenda();
                break;
            case '4':
                return opcao;
            default:
                cout << "Opcao Invalida !!!! \n\n";
                MenuDefault::menuPrincipal();
        }
    }
}
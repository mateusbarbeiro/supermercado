#include <iostream>
#include "MenuOpcoes.h"
#include "MenuPrincipal.h"
#include "FileManager.h"
#include <list>

FileManager* cli = FileManager("clientes.txt").carregaArquivoNaMemoria();
int main() {

    char op;
    MenuDefault::menuPrincipal();
    op = MenuPrincipal::opcoes();
    cout <<"Você selecionou Opção de FIM DO SISTEMA : " << op;
    return 0;
}

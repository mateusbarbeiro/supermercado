#include "MenuOpcoes.h"
#include "MenuPrincipal.h"

using namespace std;

int main() {

    char op;
    MenuDefault::menuPrincipal();
    op = MenuPrincipal::opcoes();
    cout <<"Você selecionou Opção de FIM DO SISTEMA : " << op;

    return 0;
}
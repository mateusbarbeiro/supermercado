#include "MenuOpcoes.h"

void MenuDefault::menuPrincipal() {
    cout <<"\n\t************************************** \n";
    cout <<"\t***  Selecionar uma Opcao do Menu: ***\n";
    cout <<"\t--------------------------------------\n";
    cout <<"\t*********    1 - Clientes     ********\n";
    cout <<"\t*********    2 - Produtos     ********\n";
    cout <<"\t*********    3 - Vendas        ********\n";
    cout <<"\t*********    4 - Sair         ********\n";
    cout <<"\t--------------------------------------\n";
    cout <<"\t**************************************\n"<< std::endl;
}

void MenuDefault::menuGenericOpcoes(const string& nomeTipoMenu) {
    cout <<"\n\t************************************** \n ";
    cout <<"\t*********    Menu "+nomeTipoMenu+":  *********\n";
    cout <<"\t--------------------------------------\n";
    cout <<"\t*********    1 - Cadastrar "+nomeTipoMenu+" ******\n";
    cout <<"\t*********    2 - Alterar "+nomeTipoMenu+"   ******\n";
    cout <<"\t*********    3 - Deletar  "+nomeTipoMenu+"  ******\n";
    cout <<"\t*********    4 - Visualizar "+nomeTipoMenu+" *****\n";
    cout <<"\t*********    5 - Voltar             ******\n";
    cout <<"\t--------------------------------------\n";
    cout <<"\t**************************************\n "<< std::endl;
}

void MenuDefault::menuVenda() {
    cout <<"\n\t********************************************\n";
    cout <<"\t*********     Menu Venda:           *********\n";
    cout <<"\t----------------------------------------------\n";
    cout <<"\t*********    1 - Nova venda             ******\n";
    cout <<"\t*********    2 - Voltar                 ******\n";
    cout <<"\t----------------------------------------------\n";
    cout <<"\t**********************************************\n "<< std::endl;
}

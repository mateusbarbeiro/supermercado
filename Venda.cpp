#include "Venda.h"
#include "MenuOpcoes.h"

char Venda::opcoesMenuVenda() {
    char opcao;
    while (true) {
        scanf(" %c", &opcao);
        fflush(stdin);
        switch (opcao) {
            case '1': {
                realizaVenda();
                std::cout << "Venda Cadastrada" << std::endl;
                system("cls");
                MenuDefault::menuVenda();
                break;
            }
            case '2': {
                std::cout << "Voltando ..." << std::endl;
                MenuDefault::menuPrincipal();
                return opcao;
            }
            default: {
                std::cout << "Opcao Invalida !!!! \n\n";
                MenuDefault::menuVenda();
            }
        }
    }
}

void Venda::realizaVenda() {
    float total = 0.0;
    int quantidade = 0;
    std::string respostaConfirma;

    Cliente cli = Cliente::getClienteById();
    Produto prod = Produto::getProdutoById();

    std::cout << "Produto selecionado" << std::endl;
    std::cout << prod.toSting() << std::endl;

    std::cout << "Quantidade vendida: " << std::endl;
    std::cin >> quantidade;

    total += prod.getPrecoProduto() * quantidade;

    cli.realizaCompra(total);
    prod.realizaSaida(quantidade);
}

#include "FileManager.h"

void FileManager::carregarDados() {
    FILE *arq;
    char Linha[100];
    char *result;

    arq = fopen(nomeArquivo, "r+t");

    if (arq == nullptr)
    {
        printf("Problemas na abertura do arquivo\n");
        return;
    }

    while (!feof(arq))
    {
        result = fgets(Linha, 100, arq);
        // if (result)
            // listaLinhas->push_back(result);
    }
    fclose(arq);
}

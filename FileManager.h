#ifndef SUPERMERCADO_FILEMANAGER_H
#define SUPERMERCADO_FILEMANAGER_H

#include <string>
#include <stdio.h>
#include <conio.h>
#include <list>
#include <string.h>

class FileManager {
private:
    char* nomeArquivo;
    std::list<char[100]>* listaLinhas;

    void carregarDados();


public:
    FileManager(char* nome) {
        this->nomeArquivo = nome;
        carregarDados();
    };
};

#endif //SUPERMERCADO_FILEMANAGER_H

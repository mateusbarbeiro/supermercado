#ifndef SUPERMERCADO_FILEMANAGER_H
#define SUPERMERCADO_FILEMANAGER_H
#include <iostream>
#include <fstream>
#include <list>

class FileManager {
private:
    char* fileName;
    std::list<std::string>* listaLinhas;

public:
    FileManager(char* fileName) {
        this->fileName = fileName;
    };

    FileManager * carregaArquivoNaMemoria();
    FileManager * atualizaArquivo();
    FileManager * escreveLinha(std::string linha);

};


#endif //SUPERMERCADO_FILEMANAGER_H

#include <iostream>
#include "FileManager.h"

FileManager *FileManager::carregaArquivoNaMemoria() {
    std::ifstream ifs(fileName);
    std::string line;

    while(std::getline(ifs, line))
    {
        this->listaLinhas->push_back(line);
    }
    ifs.close();
    return this;
}

FileManager *FileManager::atualizaArquivo() {
    std::ofstream out(fileName);
    for (std::string linha : *listaLinhas) {
        out << linha;
    }
    out.close();
    return this;
}

FileManager *FileManager::escreveLinha(std::string linha) {
    this->listaLinhas->push_back(linha);
    this->atualizaArquivo();
    return this;
}



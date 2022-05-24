cmake_minimum_required(VERSION 3.21)
project(supermercado)

set(CMAKE_CXX_STANDARD 14)

add_executable(supermercado main.cpp Cliente.cpp MenuOpcoes.cpp MenuPrincipal.cpp Produto.cpp Venda.cpp)

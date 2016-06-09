/*!
 *  @mainpage GREMLINS (Gerenciador de Memória com Lista Encadeada Simples)
 *  @author Adelino Afonso Fernandes Avelino
 *  @author Irene Ginani Costa Pinheiro
 *  @date Junho, 2016
 *  @version 1.0
 *
 *  @file driver_generico.cpp
 *  @brief Arquivo Main
 *
 *  Arquivo com o método Main
 */

#include <iostream>
#include <ctime>
#include <queue>
#include "mempool_common.h"
#include "Event.h"
#include "SLPool.h"
 
/**
 * @brief Main 
 *
 * Teste genérico para utilizar de maneira básica as funções de alocação e liberação de memória 
 */
//Teste utilizado no exemplo da descrição do projeto gremlins (Allocate e Allocate best)
int main(int argc, char const *argv[]) {

#ifdef TIPO1
    std::cout << ">>> Teste Allocate..." << std::endl;
    
    SLPool blocos(220);
    void *Pool[5];

    std::cout << ">>> Vazio: " << std::endl;
    blocos.MemoryMap();

    for (int i = 0; i < 5; i++) {
    try{   
        Pool[i] = blocos.Allocate(40);
        std::cout << ">>> Alocou..." << std::endl;
    }catch(std::bad_alloc){
        std::cout << ">>> Não alocou..." << std::endl;
    }
        blocos.MemoryMap();
    }

    for (int i = 0; i < 4; i++) {
    try{
        blocos.Free(Pool[i]);
        std::cout << ">>> Deletou..." << std::endl;
    }catch(std::bad_alloc){
        std::cout<<">>> Não deletou..."<<std::endl;
    }
        blocos.MemoryMap();
    }

#endif    

#ifdef TIPO2
    std::cout << ">>> Teste Allocate best..." << std::endl;

    SLPool blocos(220);
    void *Pool[5];

    std::cout << ">>> Vazio: " << std::endl;
    blocos.MemoryMap();

    for (int i = 0; i < 5; i++) {
    try{   
        Pool[i] = blocos.Allocate_best(40);
        std::cout << ">>> Alocou..." << std::endl;
    }catch(std::bad_alloc){
        std::cout << ">>> Não alocou..." << std::endl;
    }
        blocos.MemoryMap();
    }

    for (int i = 0; i < 3; i++) {
    try{
        blocos.Free(Pool[i]);
        std::cout << ">>> Deletou..." << std::endl;
    }catch(std::bad_alloc){
        std::cout<<">>> Não deletou..."<<std::endl;
    }
        blocos.MemoryMap();
    }
    
    try{
        blocos.Allocate_best(40);
        blocos.Allocate_best(20);
        std::cout << ">>> Alocou..." << std::endl;
    }catch(std::bad_alloc){
        std::cout<<">>> Não alocou..."<<std::endl;
    }
        blocos.MemoryMap();

    try{       
        blocos.Free(Pool[3]);
        std::cout << ">>> Deletou..." << std::endl;
    }catch(std::bad_alloc){
        std::cout<<">>> Não deletou..."<<std::endl;
    }
        blocos.MemoryMap();
#endif

    std::cout << ">>> EXIT SUCCESS..." << std::endl;

    return EXIT_SUCCESS;
}
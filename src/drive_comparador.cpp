/*!
 *  @mainpage GREMLINS (Gerenciador de Memória com Lista Encadeada Simples)
 *  @author Adelino Afonso Fernandes Avelino
 *  @author Irene Ginani Costa Pinheiro
 *  @date Junho, 2016
 *  @version 1.0
 *
 *  @file drive_comparador.cpp
 *  @brief Arquivo Main
 *
 *  Arquivo com o método Main
 */

#include <iostream>
#include <ctime>
#include <queue>
#include <chrono>
#include "mempool_common.h"
#include "Event.h"
#include "SLPool.h"
#include "mempool_common.h"
		
using namespace std;
/**
 * @brief Analise_GM 
 *
 * Utilização das sobrecargas dos operadores new e delete 
 */
void analise_gm()
{
	SLPool test(220);
	int *slave = new (test) int[9];
	
	int *slave1 = new (test) int [3];
	
	delete[] slave;
	delete[] slave1;
	
	int *slave2 = new (test) int[1];
	
	int *slave3 = new (test) int [4];
	
	delete[] slave2;
	delete[] slave3;
	
	int *slave4 = new (test) int[2];
	
	int *slave5 = new (test) int [3];

	delete[] slave4;
	delete[] slave5;
	
	int *slave6 = new (test) int[6];
	
	int *slave7 = new (test) int [8];
	
	delete[] slave6;
	delete[] slave7;
	
	int *slave8 = new (test) int[1];
	
	int *slave9 = new (test) int [1];


	delete[] slave8;
	delete[] slave9;
	
}
/**
 * @brief Analise_SO
 *
 * Utilização dos operadores new e delete do sistema
 */
void analise_so()
{
	
	int *slave = new int[9];
	
	int *slave1 = new int [3];
	
	delete[] slave;
	delete[] slave1;
	
	int *slave2 = new int[1];
	
	int *slave3 = new int [4];
	
	delete[] slave2;
	delete[] slave3;
	
	int *slave4 = new int[2];
	
	int *slave5 = new int [3];
	
	delete[] slave4;
	delete[] slave5;
	
	int *slave6 = new int[6];
	
	int *slave7 = new int [8];
	
	delete[] slave6;
	delete[] slave7;
	
	int *slave8 = new int[1];
	
	int *slave9 = new int [1];
	
	delete[] slave8;
	delete[] slave9;
	
}
/**
 * @brief Main 
 *
 * Drive do programa que compara o gerenciador desenvolvido com o do SO
 */
int main(int argc, char const *argv[])
{
    
	std::chrono::time_point<std::chrono::system_clock> inicio, fim;
	unsigned long long int nanosegundos_decorridos;
	//Média GM
		for (int i = 0; i<10000; i++){
		inicio = std::chrono::system_clock::now();

		analise_gm();
				
		fim = std::chrono::system_clock::now();

		nanosegundos_decorridos = nanosegundos_decorridos + std::chrono::duration_cast<std::chrono::nanoseconds> (fim-inicio).count();

	}
	std::cout << "Média de Tempo do GM: " << (nanosegundos_decorridos/10000) << "ns" << std::endl;
	nanosegundos_decorridos = 0;
	unsigned long long int nanosegundos_decorridos_so;
	//Média SO
		for (int i = 0; i<10000; i++){
		inicio = std::chrono::system_clock::now();

		analise_so();
				
		fim = std::chrono::system_clock::now();

		nanosegundos_decorridos_so = nanosegundos_decorridos_so + std::chrono::duration_cast<std::chrono::nanoseconds> (fim-inicio).count();

	}
	std::cout << "Média de Tempo do SO: " << (nanosegundos_decorridos_so/10000) << "ns" << std::endl;

	if (nanosegundos_decorridos < nanosegundos_decorridos_so)
	{
		std::cout << ">> O teste do GM é mais rápido!" << std::endl;
	}
	else
	{
		std::cout << ">> O teste do SO é mais rápido!" << std::endl;
	}
    
    std::cout << ">>> EXIT SUCCESS..." << std::endl;

    return EXIT_SUCCESS;
}
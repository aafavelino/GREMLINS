/**
 * @file SLPool.h
 * @brief Assinatura da classe SLPool
 */
#ifndef _SLPOOL_H_
#define _SLPOOL_H_
#include <iostream>     
#include <ctime>       
#include <cmath>  
#include <cstddef>      
#include <cstdlib>
#include "StoragePool.h"
#include "mempool_common.h"
/**
 * @brief Classe SLPool
 *
 * Assinaturas das funções e definição da classe SLPool
 */
class SLPool:public StoragePool{
	public:
/**
 * @brief struct Header com atributo do bloco
 *
 */		
		struct Header{
			unsigned int mui_Length ;   
			Header () : mui_Length(0u) { /* Empty */ };
		};
/**
 * @brief struct Block que define o tamanho em bytes do bloco de memória e ainda possui um ponteiro para o próximo e bloco.
 *
 */
		struct Block:public Header{
			enum { BlockSize = 16 }; //Each block has 16 bytes .
			union{
				Block* mp_Next;
				char mc_RawArea [BlockSize-sizeof(Header)];
			};
			Block () : Header () , mp_Next(nullptr) { /* Empty */ };
		};
	private:
		unsigned int mui_NumberOfBlocks;    //!<Numero de blocos alocados de memória
		Block* mp_Pool ; //!< Head of list.
		Block mr_Sentinel; //!< End of the list.
	public:
/**
 * @brief construtor da classe SLPool
 * @param size_t que constrói o primeiro bloco de memória do tamanho passado pelo parâmetro 
 */
		explicit SLPool (size_t _bytes);
/**
 * @brief destrutor da classe SLPool
 *
 */
		virtual ~SLPool();
/**
 * @brief método que aloca o valor passado por parâmetros no bloco inicial de memória seguinte o padrão first_it
 * @param bytes em size_t valor passado que se deseja alocar
 * @return void
 */
		void* Allocate(size_t bytes);
/**
 * @brief método que aloca o valor passado por parâmetros no bloco inicial de memória seguindo o padrão best_it
 * @param bytes em size_t valor passado que se deseja alocar
 * @return void
 */
		void* Allocate_best(size_t bytes);
/**
 * @brief método que libera o ponteiro passado como parâmetro
 * @param ptr void que é o ponteiro o qual desejo liberar
 * @return void
 */
		void Free(void* ptr);
/**
 * @brief método que constrói um mapa da memória no momento atual
 * @return void
 */
		void MemoryMap(void);
};
#include "SLPool.inl"
#endif
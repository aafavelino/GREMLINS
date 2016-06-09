/*!
 *  @file StoragePool.h
 *  @brief Lista de métodos da classe abstrata StoragePool
 *
 */


#ifndef _SORAGEPOOL_H_
#define _SORAGEPOOL_H_

class StoragePool{
	public:

/*!
 *  @brief destrutor da classe 
 */
		virtual ~StoragePool(){};
/**
 * @brief método que aloca o valor passado por parâmetros no bloco inicial de memória seguinte o padrão first_it
 * @param bytes em size_t valor passado que se deseja alocar
 * @return void
 */
		virtual void* Allocate(size_t bytes) = 0;

/**
 * @brief método que aloca o valor passado por parâmetros no bloco inicial de memória seguindo o padrão best_it
 * @param bytes em size_t valor passado que se deseja alocar
 * @return void
 */

		virtual void* Allocate_best(size_t bytes) = 0;
/**
 * @brief método que libera o ponteiro passado como parâmetro
 * @param ptr void que é o ponteiro o qual desejo liberar
 * @return void
 */

		virtual void Free (void * ptr) = 0;

/**
 * @brief método que constrói um mapa da memória no momento atual
 * @return void
 */

		virtual void MemoryMap(void) = 0;
		
};
#endif
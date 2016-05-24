/**
 * @file SLPoolBF.hpp
 * @brief Assinatura da classe SLPoolBF
 */
#ifndef _SLPOOL_H_
#define _SLPOOL_H_
#include "StoragePool.h"
#include <iostream>     
#include <ctime>        
#include <cstddef>      
#include <cstdlib>

class SLPool:public StoragePool{
	public:
		struct Header{
			unsigned int mui_Length ; 
			SLPool *p;                  
			Header () : mui_Length(0u) { /* Empty */ };
		};
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

		explicit SLPool (size_t _bytes = 1024);

		virtual ~SLPool();

		void* Allocate(size_t bytes);

		void Free(void* ptr);


};
#include "SLPool.inl"
#endif
#ifndef _SORAGEPOOL_H_
#define _SORAGEPOOL_H_
#include <iostream>

class StoragePool{
	public:

		virtual ~StoragePool(){};

		virtual void* Allocate(size_t bytes)=0;

		virtual void Free (void * ptr) = 0;

		
};
#endif
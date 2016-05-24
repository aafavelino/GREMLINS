#ifndef _MEMPOOL_COMMON_H_
#define _MEMPOOL_COMMON_H_

#include <iostream>
#include "StoragePool.h"

using namespace std;

struct Tag { StoragePool * pool; };

void * operator new ( size_t bytes, StoragePool & p );
	
void * operator new ( size_t bytes );

void operator delete ( void * arg ) noexcept;

#include "mempool_common.inl"
 
#endif
#include "SLPool.h"
#include <new>

SLPool::SLPool(size_t _bytes){
  							
}


SLPool::~SLPool(){
    delete(mp_Pool);
}

void* SLPool::Allocate(size_t _bytes){

}

void SLPool::Free(void* _ptr){
}

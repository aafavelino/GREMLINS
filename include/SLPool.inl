#include "SLPool.h"
#include <new>

SLPool::SLPool(size_t bytes){
    this->mui_NumberOfBlocks = (bytes/sizeof(Block)) + (bytes%sizeof(Block)!=0) +1;
    mp_Pool = new Block[mui_NumberOfBlocks];
    mp_Pool->mui_Length = mui_NumberOfBlocks - 1;
    mp_Pool->mp_Next = nullptr;
    mr_Sentinel = mp_Pool[mp_Pool->mui_Length];
    mr_Sentinel.mp_Next = mp_Pool;   							
}


SLPool::~SLPool(){
    delete mp_Pool;
}

void* SLPool::Allocate(size_t bytes){

}

void SLPool::Free(void* _ptr){
    
}

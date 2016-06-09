/*!
 *  @file SLPool.inl
 *  @brief Implementação da Classe SLPool
 *
 *  Arquivo com a construção das funções da classe SLPool
 */
#include "SLPool.h"
//Construtor
SLPool::SLPool(size_t bytes)
{
    mui_NumberOfBlocks = std::ceil((static_cast<float>(bytes)/Block::BlockSize) + 1);
    mp_Pool = new Block[mui_NumberOfBlocks];
    mp_Pool->mui_Length = mui_NumberOfBlocks - 1;
    mp_Pool->mp_Next = nullptr;
    mr_Sentinel = mp_Pool[mui_NumberOfBlocks - 1];
    mr_Sentinel.mp_Next = mp_Pool;   							
}

//Destrutor
SLPool::~SLPool()
{
    delete[] mp_Pool;
}

//Método para alocação de maneira first_fit
void* SLPool::Allocate(size_t bytes)
{
    unsigned int Nblocks = std::ceil(static_cast<float>(bytes)/Block::BlockSize);
    Block *ptReserved = mr_Sentinel.mp_Next;
    Block *ptPrevReserved = &mr_Sentinel;
    
    for (;ptReserved != nullptr; ptPrevReserved = ptReserved,
         ptReserved = ptReserved->mp_Next)
    {

        if (ptReserved->mui_Length >= Nblocks)
        {
            if (ptReserved->mui_Length == Nblocks)
            {
                ptPrevReserved->mp_Next = ptReserved->mp_Next;
            } 
            else
            {
                ptPrevReserved->mp_Next = ptReserved + Nblocks;
                ptPrevReserved->mp_Next->mp_Next = ptReserved->mp_Next;
                ptPrevReserved->mp_Next->mui_Length = ptReserved->mui_Length - Nblocks;
                ptReserved->mui_Length = Nblocks;
            }
            
            if (mr_Sentinel.mp_Next == ptReserved)
            {
                mr_Sentinel.mp_Next = ptReserved->mp_Next;
            }
            return reinterpret_cast<void*>(reinterpret_cast<int*>(ptReserved)+1U);
        }   
    }

    throw(std::bad_alloc());    

}


//Método para alocação de maneira best_fit
void* SLPool::Allocate_best(size_t bytes)
{
    unsigned int Nblocks = std::ceil(static_cast<float>(bytes)/Block::BlockSize);
    Block *ptReserved = (&mr_Sentinel)->mp_Next;
    Block *ptPrevReserved = &mr_Sentinel;
    Block *ptReservedbest = nullptr;
    Block *ptPrevReservedbest = nullptr;
    
    for (;ptReserved != nullptr; ptPrevReserved = ptReserved,
         ptReserved = ptReserved->mp_Next)
    {
        if (ptReserved->mui_Length >= Nblocks)
        {
            if (ptReserved->mui_Length == Nblocks)
            {
                ptPrevReserved->mp_Next = ptReserved->mp_Next;
                return reinterpret_cast<void*>(reinterpret_cast<int*>(ptReserved)+1U);
            } 
            if (ptReservedbest == nullptr or ptReservedbest->mui_Length > ptReserved->mui_Length) 
            {
                ptReservedbest = ptReserved;
                ptPrevReservedbest = ptPrevReserved;
            }      
        }
    }

        if(ptReservedbest != nullptr)
        {
            ptPrevReservedbest->mp_Next = ptReservedbest + Nblocks;
            ptPrevReservedbest->mp_Next->mp_Next = ptReservedbest->mp_Next;
            ptPrevReservedbest->mp_Next->mui_Length = ptReservedbest->mui_Length - Nblocks;
            ptReservedbest->mui_Length = Nblocks;
            return reinterpret_cast<void*>(reinterpret_cast<int*>(ptReservedbest)+1U);
        }


    throw(std::bad_alloc());    

}

//Liberação de memória
void SLPool::Free(void* ptReserved)
{
    Block *Reserved = reinterpret_cast<Block*>(reinterpret_cast<int*>(ptReserved)-1U);
    Block *ptPostReserved = (&mr_Sentinel)->mp_Next;
    Block *ptPrevReserved = &mr_Sentinel;
    
    while (ptPostReserved!=nullptr)
    {
        if (!(ptPostReserved < Reserved))
        {

        if ((ptPrevReserved + ptPrevReserved->mui_Length == Reserved) and (Reserved + Reserved->mui_Length == ptPostReserved))
        {
            ptPrevReserved->mui_Length = ptPrevReserved->mui_Length + ptPostReserved->mui_Length + Reserved->mui_Length;
            ptPostReserved->mui_Length = 0;
            Reserved->mui_Length = 0;
            ptPrevReserved->mp_Next = ptPostReserved->mp_Next;
        } 
        else if (Reserved + Reserved->mui_Length == ptPostReserved)
        {
            Reserved->mui_Length = Reserved->mui_Length + ptPostReserved->mui_Length;
            ptPostReserved->mui_Length = 0;
            Reserved->mp_Next = ptPostReserved->mp_Next;
        }
        else if (ptPrevReserved+ptPrevReserved->mui_Length == Reserved)
        {
            ptPrevReserved->mui_Length = ptPrevReserved->mui_Length + Reserved->mui_Length;
            Reserved->mui_Length = 0;
        } 
        else
        {
            ptPrevReserved->mp_Next = Reserved;
            Reserved->mp_Next = ptPostReserved;
            
        }
    }
    else
    {
        ptPrevReserved = ptPrevReserved->mp_Next;
    }
        ptPostReserved=ptPostReserved->mp_Next;
    
    }
    if (ptPostReserved == nullptr)
    {
        if (ptPrevReserved+ptPrevReserved->mui_Length == Reserved)
        {
            ptPrevReserved->mui_Length = ptPrevReserved->mui_Length + Reserved->mui_Length;
            ptPrevReserved->mp_Next = Reserved->mp_Next;
            Reserved->mui_Length = 0;
        }
    }
}


//Mapa da memória
void SLPool::MemoryMap(void)
{
    int i=0;
    int j=0;
    Block* slave = (&mr_Sentinel)->mp_Next;

    while(i < mui_NumberOfBlocks-1)
    {       
            if((mp_Pool+i) == slave)
            {

                j = (mp_Pool+i)->mui_Length;

                while(j > 0 and i < mui_NumberOfBlocks)
                {
                    std::cout<<"| |";
                    j--;
                    i++;
                }

                slave = slave->mp_Next;

            }
            else
            {
                j = (mp_Pool+i)->mui_Length;

                while(j > 0 and i < mui_NumberOfBlocks)
                {
                    std::cout <<"||";
                    j--;
                    i++;
                } 
            }
        j = 0;
    }
    std::cout << "\n\n";
}
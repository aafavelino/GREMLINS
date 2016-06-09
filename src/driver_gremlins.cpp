/*!
 *  @mainpage GREMLINS (Gerenciador de Memória com Lista Encadeada Simples)
 *  @author Adelino Afonso Fernandes Avelino
 *  @author Irene Ginani Costa Pinheiro
 *  @date Junho, 2016
 *  @version 1.0
 *
 *  @file driver_gremlins.cpp
 *  @brief Arquivo Main
 *
 *  Arquivo com o método Main
 */

#include <iostream>
#include <ctime>
#include <chrono>
#include <queue>
#include <vector>
#include "mempool_common.h"
#include "Event.h"
#include "SLPool.h"


using namespace std;


 
void StoragePoolTest(StoragePool *pool, size_t _timeLimit)
{
	//[1] Setup random numbers generator for memory size, say [100,2000] bytes.
	//[2] Setup random numbers generator for time intervals, say [1,100] units. 
	//[3] Create the pirority queue std::priority_queue ‘pq’ and
	//	  insert some events comprising the simulation.
	//Assuming there is a class Event that creates a pair address/time-stamp.
    //Colaboração de Selan
	auto cmp = [ ](const Event & e1, const Event & e2)
    {
        return e1.get_time() < e2.get_time();
    };

	std::priority_queue<Event, std::vector<Event>, decltype(cmp)> pq(cmp);
    
	Event ev;
	auto test(false);

	//Run simulation fot the time set by the client.
	for (size_t t(0); t < _timeLimit; ++t)
	{
 		while(!pq.empty()) 
 		{ // Run while we have events pending or time to run.
            ev=pq.top(); // Access the event with the smallest time-stamp.
            if(ev.get_time() > t) break; // Still some time left....
            pq.pop(); // Remove event from priority queue.
            delete ((bool*)(ev.get_slave())); // Calling free operator.
        }

        auto memSize = rand() % 2000 + 100;

        bool* add;
        
        try
        {
            if(pool == nullptr)
            {
                add = new bool[memSize];
            }
            else
            {
                add = new (*pool) bool[memSize];
                test = true;
            }
        }
        catch(std::bad_alloc)
        {
        	std::cout << ">>> Not enough memory..." << std::endl;
        }

        if(test)
        {
            auto elapsedTime = rand() % 100 + 1;
            std::time_t releaseTime = t + elapsedTime ; // Set time stamp some time from now .
            //std::cout << ">>> releaseTime: " << releaseTime << std::endl;
            //std::cout << ">>> memSize: " << memSize << std::endl;
            pq.push(Event(reinterpret_cast<void*>(add), releaseTime)); // Creating a new simulation event .
        }
    }
    while(!pq.empty()) 
    {
        ev = pq.top();
        pq.pop();
        delete ((bool*)ev.get_slave());
    }
}

/**
 * @brief Main 
 *
 * Teste sugerido para comprovar eficiencia do GM desenvolvido
 */
int main(int argc, char const *argv[])
{

	std::chrono::time_point<std::chrono::system_clock> inicio, fim;
	unsigned long long int nanosegundos_decorridos = 0;
    
    StoragePool *slave = new SLPool(8*1024*1024);

    inicio = std::chrono::system_clock::now();
   		StoragePoolTest(slave, 1000);
	fim = std::chrono::system_clock::now();
    

	nanosegundos_decorridos = nanosegundos_decorridos + std::chrono::duration_cast<std::chrono::nanoseconds> (fim-inicio).count();

	std::cout << ">>> Test of time: " << nanosegundos_decorridos << "ns" << std::endl;
	delete slave;
    std::cout << ">>> EXIT SUCCESS..." << std::endl;

    return EXIT_SUCCESS;
}

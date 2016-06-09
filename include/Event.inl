/*!
 *  @file Event.inl
 *  @brief Implementação da Classe Event
 *
 *  Arquivo com a construção das funções da classe Event
 */
#include "Event.h"
//Construtor
Event::Event(void *_slave, std::time_t _time):slave(_slave), time(_time) {/*Empty*/}
//Recupera o ponteiro void
void *Event::get_slave()const
{
	return slave;
}

//Recupera o tempo time
std::time_t Event::get_time()const
{
	return time;
}

//Redefine o operador <
bool Event::operator < (Event slave)const
{
	return (time < slave.get_time());
}
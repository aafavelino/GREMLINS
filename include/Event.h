/*!
 *  @file Event.h
 *  @brief Corpo da Classe Event
 *
 *  Arquivo com a classe Event
 */
#ifndef _EVENT_H_
#define _EVENT_H_
#include <ctime> 
/**
 * @brief Classe Event
 *
 * Assinaturas das funções e definição da classe Event
 */
class Event
{
public:
	/**
     * @brief Construtor da classe Event
     * Cria os Event
     */
	Event(void *_slave, std::time_t _time);
     /**
     * @brief Construtor vazio da classe Event
     * Cria um evento vazio
     */
	Event(){}
     /**
     * @brief recupera o valor do ponteiro void da classe Event
     * @return ponteiro void
     */
	void *get_slave() const;
    /**
     * @brief recupera o valor da variável time da classe Event
     * @return time_t 
     */
	std::time_t get_time() const;
    /**
     * @brief redefine o operador < 
     * @param salve parâmetro do tipo Event utilizado pra comparação
     * @return true ou false 
     */
	bool operator < (Event slave)const;

private:
	void *slave; //!<Ponteiro void
	std::time_t time; //!<Variável time do tipo time_t
};

#include "Event.inl"
#endif
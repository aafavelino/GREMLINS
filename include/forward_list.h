/*!
 *  @file forward_list.h 
 *  @brief Corpo da Classe Forward_list
 *
 *  Arquivo com a classe Forward_list
 */
 
#ifndef _FORWARD_LIST_H_
#define _FORWARD_LIST_H_

/**
 * @brief Classe Forward_list
 *
 * Assinaturas das funções e definição da classe Forward_list
 */
template <typename T>
class Forward_list{
public:

/**
 * @brief Classe const_iterator
 *
 * Assinatura da classe const_iterator
 */
class const_iterator;
/**
 * @brief Classe iterator
 *
 * Assinatura da classe iterator
 */
class iterator;
/**
 * @brief Construtor padrão da classe Forward_list
 * Seta os valores alocando novos nós
 */
 Forward_list(){
 	m_size = 0;
	m_head = new Node;
	m_tail = new Node;
 }
/**
 * @brief Destrutor da classe Forward_list
 * Destroi o m_head e o m_tail
 */
 ~Forward_list(){
 	delete m_head;
 	delete m_tail;
 }
 /**
 * @brief Construtor cópia da classe Forward_list
 * Faz uma cópia de todos os valores do objeto no qual se quer copiar
 */
 Forward_list (const Forward_list &list);
 /**
 * @brief Construtor move da classe Forward_list
 * Move todos os elementos de um objeto de uma classe para outro objeto
 */
 Forward_list (Forward_list && list);
 /**
  * @brief Sobrecarga do operador cópia
  * @ Param list O elemento a ser copiado
  * @return O this do elemento copiado
  */
 Forward_list &operator = (const Forward_list & list){
 	delete m_head;
 	delete m_tail;
 	m_head = new Node (list.m_head->data,list.m_head->next);
 	m_tail = new Node (list.m_tail->data,list.m_tail->next);
 	this->m_size = list.m_size;
 	return (*this);
 }
 /**
  * @brief Sobrecarga do operador move
  * @ Param list O elemento a ser movido
  * @return O this do elemento movido
  */
 Forward_list &operator = (Forward_list && list){

 	delete m_head;
 	delete m_tail;
 	m_head = new Node (list.m_head->data,list.m_head->next);
 	m_tail = new Node (list.m_tail->data,list.m_tail->next);
 	m_size = list.m_size;
 	list.m_head = nullptr;
 	list.m_tail = nullptr;
 	list.m_size = 0;
 	return (*this);
 }

/**
  * @brief Pega um iterador apontando para o inicio da lista
  * @return Um iterador para o inicio da lista
  */
 iterator before_begin();

 /**
  * @brief Pega um iterador apontando para o primeiro elemento da lista
  * @return Um iterador apontando para o primeiro elemento da lista
  */
 iterator begin();

 /**
  * @brief Pega um iterador apontando para o ultimo elemento da lista
  * @return Um iterador apontando para o ultimo elemento da lista
  */
 iterator end();

/**
  * @brief Pega um iterador apontando para o inicio da lista
  * @return Um iterador para o inicio da lista
  */
 const_iterator cbefore_begin()const;

  /**
  * @brief Pega um iterador const apontando para o primeiro elemento da lista
  * @return Um iterador apontando para o primeiro elemento da lista
  */
 const_iterator cbegin()const;


 /**
  * @brief Pega um iterador const apontando para o ultimo elemento da lista
  * @return Um iterador apontando para o ultimo elemento da lista
  */
 const_iterator cend()const;

/**
 * @brief Colhe o tamanho da lista 
 * @return O tamanho da Forward list
 */
 int size ()const;

/**
 * @brief Verifica se a lista está vazia 
 * @return True se estiver vazia, ou False se não estiver vazia
 */
 bool empty ()const;

/**
 * @brief Deleta todos os elementos da lista 
 * @return void
 */
 void clear ();

/**
 * @brief Pega o elemento da frente da lista
 * @return A referência para o primeiro elemento
 */ 
 T &front ();

/**
 * @brief Pega o elemento da frente da lista
 * @return A referência const para o primeiro elemento
 */ 
 const T &front()const;

/**
 * @brief Pega o elemento do final da lista
 * @return A referência para o ultimo elemento
 */ 
 T &back();

/**
 * @brief Pega o elemento do final da lista
 * @return A referência const para o ultimo elemento
 */ 
 const T &back()const;

/**
 * @brief Insere Elementos na frente da lista
 * @param x O elemento a ser inserido 
 * @return void
 */ 
 void push_front(const T &x);

/**
 * @brief Insere Elementos no final da lista
 * @param x O elemento a ser inserido 
 * @return void
 */ 
 void push_back(const T &x);

/**
 * @brief Deleta Elementos na frente da lista
 * @return void
 */  
 void pop_front();

/**
 * @brief Deleta Elementos no final da lista 
 * @return void
 */ 
 void pop_back();

 /**
 * @brief Insere o elemento em todas as posicoes da lista
 * @param value Elemento a ser inserido 
 * @return void
 */ 
 void assign(const T &value);

 /**
 * @brief Insere o elemento do tipo initializer_list 
 * @param ilist Lista a ser inserida 
 * @return void
 */ 
 void assign(std::initializer_list <T> ilist);

 /**
  * @brief Insere um elemento em uma posicao passada por parametro
  * @param itr O iterador para posicao a ser inserido o elemento
  * @param x O elemento a ser inserido
  * @return O iterador para o elemento inserido
  */
 iterator insert_after(const_iterator itr , const T &x );

 /**
  * @brief Insere uma lista na lista iterador passada por parametro
  * @param pos O iterador para posicao a ser inserido o elemento
  * @param ilist A lista a ser inserida
  * @return O iterador para o ultimo elemento adicionado
  */
 iterator insert_after(const_iterator pos , std::initializer_list <T> ilist);
 

 /**
  * @brief Apaga um elemento em uma posicao passada por parametro
  * @param itr O iterador para posicao a ser apagada
  * @return A posicao do elemento apagado
  */
 iterator erase_after (const_iterator itr);

 /**
  * @brief Apaga os elementos em um intervalo passado por parametro
  * @param first O iterador para primeira posicao a ser apagada
  * @param last O iterador para ultima posicao a ser apagada
  * @return A posicao do ultimo elemento apagado
  */
 iterator erase_after (const_iterator first , const_iterator last);

 /**
  * @brief Procura um elemento na lista
  * @param x O elemento a ser procurado
  * @return Um Iterador const para o elemento encontrado
  */
 const_iterator find (const T & x)const;

 private:

 struct Node{
 T data; // <! Campo Data
 Node *next; // <! Ponteiro para o elemento sucessor
 Node (const T &d = T() , Node *p = nullptr , Node *n = nullptr): data (d), next (n) { /* Empty */ }// <! Construtor Básico
 };


 int m_size ; // <! Tamanho da lista
 Node *m_head; // <! Cabeça da lista
 Node *m_tail; // <! Final da lista
 };


/**
 * @brief Classe const_iterator
 */
template <typename T>
class Forward_list<T>::const_iterator {
public:

 /**
  * @brief Construtor padrao
  */
const_iterator ()
{
    current = new Node;
}


 /**
  * @brief Sobrecarga para o operador *
  */
 const T & operator * ( ) const
 {
     return current->data;
 }


 /**
  * @brief Sobrecarga para o operador ++ (Infixo)
  */
 const_iterator & operator ++ ( )
 {
 	current = current -> next;
    return (*this);
 } // ++ it;

 /**
  * @brief Sobrecarga para o operador ++ (Posfixo)
  */
const_iterator operator ++ (int) {
        Forward_list<T>::const_iterator slave = current;
        current = current->next;
        return slave;
 }
 // it ++;

 /**
  * @brief Sobrecarga para o operador ==
  */
 bool operator == ( const const_iterator & rhs ) const{
    return (current == rhs.current);

 }

 /**
  * @brief Sobrecarga para o operador !=
  */
 bool operator != ( const const_iterator & rhs ) const {
    return !(*this==rhs);

}

protected:
 Node *current; // <! Ponteiro para Forward list
 const_iterator (Node * p):current (p){} // <! Construtor padrao
 friend class Forward_list <T>; // <! Classe amiga da Forward_list
 };


/**
 * @brief Classe iterator
 */
template <typename T>
class Forward_list<T>::iterator : public Forward_list<T>::const_iterator {
 public:

 /**
  * @brief Construtor padrao
  */
 iterator ():const_iterator(){ /* Empty */ }

 /**
  * @brief Sobrecarga para o operador *
  */
 const T & operator * ( )const 
 {
 	return const_iterator::current->data;
 }
 
 /**
  * @brief Sobrecarga para o operador *
  */
 T & operator * ( )
 {
 	return const_iterator::current->data;
 }
 


 /**
  * @brief Sobrecarga para o operador ++ (Infixo)
  */
 iterator & operator ++ ( )
 {

 	const_iterator::current = const_iterator::current->next;
 	return const_iterator::current;
 }
 
 /**
  * @brief Sobrecarga para o operador ++ (Posfixo)
  */
 iterator operator ++ ( int )
 {
 	iterator slave(const_iterator::current);
 	const_iterator::current = const_iterator::current->next;
    return slave;
 }

 protected:
 iterator (Node *p):const_iterator (p){} // <! Construtor padrao
 friend class Forward_list <T>; // <! Classe amiga da Forward_list
 };



#include "forward_list.inl"

#endif
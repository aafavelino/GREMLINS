/*!
 *  @file vector.h 
 *  @brief Corpo da Classe Vector
 *
 *  Arquivo com a classe Vector
 */

#ifndef _VECTOR_H_
#define _VECTOR_H_
#include <iostream>
#include <algorithm>


/**
 * @brief Classe Vector
 *
 * Assinaturas das funções e definição da classe Vector
 */
template <typename Obj>
class Vector {
public:


/**
  * @brief Construtor Vector
  * @ Param x O tamanho do vetor
  */
    Vector(size_t x = 10  ); //ok
/**
  * @brief Destrutor Vector
  */
    ~Vector(){}

/**
  * @brief Pega tamanho Vector
  * @return O tamanho Vector
  */
    size_t size()const;//ok
/**
  * @brief Remove todos os elementos do vetor
  */
    void clear();//ok
/**
  * @brief Verifica se o vetor está vazio
  * @return True se estiver vazio e False se não estiver vazio
  */
    bool empty();
/**
  * @brief Adicionar um elemento no final do vector
  * @ Param x Elemento a ser colocado atrás
  */
    void push_back(const Obj &x);//ok
/**
  * @brief Remove o ultimo elemento do vetor
  */
    void pop_back();//ok
/**
  * @brief Retorna o Obj no inicio do Vector
  * @return O primeiro elemento do vector
  */
    const Obj &front()const; //ok
/**
  * @brief Retorna o Obj no fim do Vector
  * @return O último elemento do vector
  */
    const Obj &back()const;//ok
/**
  * @brief Substitui o conteúdo do vetor
  * @ Param x Atribui novos conteúdos ao vector, substituindo seu conteúdo atual, e modificando seu tamanho em conformidade. 
  */
    void assign(const Obj &x);//ok
/**
  * @brief Retorna a capacidade Vector
  * @return A capacidade Vector
  */
    size_t capacity()const;//ok
/**
  * @brief Define a nova capacidade Vector
  * @ Param new_capacidade O novo tamanho da capacidade
  */
    void reserve(size_t new_capacidade);//ok
/**
  * @brief Retorna o elemento em alguma posição
  * @ Param x A posição a ser devolvido
  * @return O elemento em posição
  */
    Obj &at(size_t x);//ok
/**
  * @brief Sobrecarrega o operador []
  * @ Param x posição a ser acessada
  * @return Elemento na posição informada
  */
    Obj &operator[](size_t x);//ok
/**
 * @brief Declaração da classe const_iterator
 */
    class const_iterator;
/**
 * @brief Declaração da classe iterator
 */

    class iterator;

 /**
  * @brief Pega um iterador const apontando para o primeiro elemento da lista
  * @return Retorna um iterador para o primeiro elemento do vector. (cppreference)
  */    
    const_iterator cbegin() const;

 /**
  * @brief Pega um iterador apontando para o primeiro elemento da lista
  * @return Retorna um iterador para o primeiro elemento do vector. (cppreference)
  */    
    iterator begin();

 /**
  * @brief Pega um iterador const apontando para o ultimo elemento da lista
  * @return Retorna um iterador para o elemento seguinte ao último elemento do vector. 
  */
    const_iterator cend() const;

 /**
  * @brief Pega um iterador apontando para o ultimo elemento da lista
  * @return Retorna um iterador para o elemento seguinte ao último elemento do vector. 
  */
    iterator end();




private:
    size_t tamanho = 0; // <! Tamanho      
    size_t x_capacidade = 0;// <! Capacidade     
    std::unique_ptr<Obj[]> vetor; // <! Unique ptr Vetor 
};



template <typename Obj>
class Vector<Obj>::const_iterator {

friend class Vector<Obj>; 

public:

 /**
  * @brief Construtor padrao
  */
const_iterator ()
{
   
}


 /**
  * @brief Sobrecarga para o operador *
  */
 const Obj & operator * ( ) const
 {
     return *current;
 }


 /**
  * @brief Sobrecarga para o operador ++ (Infixo)
  */
 const_iterator & operator ++ ( )
 {
    current++;
    return *this;
 } 

 /**
  * @brief Sobrecarga para o operador ++ (Posfixo)
  */
const_iterator operator ++ (int) {
        const_iterator slave = current;
        current++;
        return slave;
 }
 

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
 const_iterator (Obj * x):current (x){} // <! Construtor padrao
 Obj *current; // <! Ponteiro para Forward list
 friend class Vector <Obj>; // <! Classe amiga da Vector
};



template <typename Obj>
class Vector<Obj>::iterator : public Vector<Obj>::const_iterator {
 public:

 /**
  * @brief Construtor padrao
  */
 iterator ():const_iterator(){ /* Empty */ }

 /**
  * @brief Sobrecarga para o operador *
  */
 const Obj & operator * ( )const 
 {
    return *const_iterator::current;
 }
 
 /**
  * @brief Sobrecarga para o operador *
  */
 Obj & operator * ( )
 {
    return *const_iterator::current;
 }
 
  /**
  * @brief Sobrecarga para o operador ++ (Infixo)
  */
 iterator & operator -- ( )
 {
     const_iterator::current--;
     return *this;
 }
 
 /**
  * @brief Sobrecarga para o operador ++ (Posfixo)
  */
 iterator operator -- ( int )
 {
    iterator slave(const_iterator::current);
    const_iterator::current--;
    return slave;
 }




 /**
  * @brief Sobrecarga para o operador ++ (Infixo)
  */
 iterator & operator ++ ( )
 {
    const_iterator::current++;
    return *this;
 }
 
 /**
  * @brief Sobrecarga para o operador ++ (Posfixo)
  */
 iterator operator ++ ( int )
 {
    iterator slave(const_iterator::current);
    const_iterator::current++;
    return slave;
 }

 protected:

 iterator(Obj *x):const_iterator (x){} // <! Construtor padrao
 friend class Vector <Obj>; // <! Classe amiga da Vector
};


#include "vector.inl"

#endif

//http://codereview.stackexchange.com/questions/60484/stl-vector-implementation
//http://pt.cppreference.com/w/cpp/container/vector/end
//http://pt.cppreference.com/w/cpp/container/vector/begin
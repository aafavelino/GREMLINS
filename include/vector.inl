/*!
 *  @file vector.inl 
 *  @brief Implementacao das funcoes da classe
 *
 *  Arquivo com a implementacao das funcoes
 */

#include "vector.h"

template <typename Obj>
Vector<Obj>::Vector(size_t x): x_capacidade(x), vetor(new Obj[x])
{}

template <typename Obj>
size_t Vector<Obj>::size()const
{
return tamanho;
}

template <typename Obj>
size_t Vector<Obj>::capacity()const
{
return x_capacidade;
}

template <typename Obj>
Obj &Vector<Obj>::at(size_t x)
{
	if (x < 0 or x > tamanho)
	{
		std::cout << "Fora de faixa" << std::endl;
	}
	return vetor[x];
}

template <typename Obj>
void Vector<Obj>::assign(const Obj &x)
{
	for (int i = 0; i < tamanho; ++i)
	{
		vetor[i] = x;
	}
}


template <typename Obj>
const Obj &Vector<Obj>::front()const
{
	return vetor[0];
}

template <typename Obj>
const Obj &Vector<Obj>::back()const
{
	return vetor[tamanho-1];
}

template <typename Obj>
void Vector<Obj>::reserve(size_t new_capacidade)
{
	if (new_capacidade > x_capacidade)
	{
		std::unique_ptr<Obj[]> slave(new Obj[new_capacidade]);
		for (int i = 0; i < tamanho; ++i)
		{
			slave[i] = vetor[i];
			(&vetor[i]) -> ~Obj();
		}

		vetor = std::move(slave);
	
		

		x_capacidade = new_capacidade;
	}
}

template <typename Obj>
void Vector<Obj>::push_back(const Obj &x){
	if (tamanho >= x_capacidade)
	{
		if (x_capacidade == 0)
			reserve(1);
		else
			reserve(x_capacidade*2);
		
	}
	vetor[tamanho++] = x;
}

template <typename Obj>
void Vector<Obj>::pop_back(){
	(&vetor[tamanho = tamanho-1]) -> ~Obj();
}

template <typename Obj>
void Vector<Obj>::clear(){
   	for (int i = tamanho; i > 0; --i)
   	{
   		tamanho--;
   		(&vetor[tamanho]) -> ~Obj();
    }
}

template <typename Obj>
Obj &Vector<Obj>::operator[](size_t x)
{
	return vetor[x];
}
template <typename Obj>
bool Vector<Obj>::empty()
{
	return (tamanho == 0)? true : false;
}

template <typename Obj>
typename Vector<Obj>::const_iterator Vector<Obj>::cbegin() const{
	return typename Vector<Obj>::const_iterator(vetor.get());
}

template <typename Obj>
typename Vector<Obj>::const_iterator Vector<Obj>::cend() const{
	return typename Vector<Obj>::const_iterator(vetor.get()+tamanho);
}

template <typename Obj>
typename Vector<Obj>::iterator Vector<Obj>::begin(){
	return typename Vector<Obj>::iterator(vetor.get());
}

template <typename Obj>
typename Vector<Obj>::iterator Vector<Obj>::end(){
	return typename Vector<Obj>::iterator(vetor.get()+tamanho);
}

//http://www.cplusplus.com/reference/memory/unique_ptr/get/
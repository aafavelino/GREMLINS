/*!
 *  @file forward_list.inl 
 *  @brief Implementacao das funcoes da classe
 *
 *  Arquivo com a implementacao das funcoes
 */

#include "forward_list.h"

 template <typename T>
 Forward_list<T>::Forward_list ( const Forward_list <T> &list )
 {
 	m_head = new Node (list.m_head->data,list.m_head->next);
 	m_tail = new Node (list.m_tail->data,list.m_tail->next);
 	m_head->next = m_tail;
 	for (auto i = list.cbegin(); i != list.cend(); i++)
 	{
 		push_back(*i);
 	}
 	 	m_size = 0;
 }

 template <typename T>
 Forward_list<T>::Forward_list ( Forward_list <T> &&list )
 {
 	m_head = new Node (list.m_head->data,list.m_head->next);
 	m_tail = list.m_tail;
 	m_size = list.m_size;
 	list.m_tail = new Node;
 	list.m_head = list.m_tail;
 	list.m_size = 0;
 }
 


template <typename T>
const T &Forward_list<T>::front()const
{
	if (m_head == NULL)
	{
    	return 0;
	}
	else
	{
		return m_head-> next -> data;
		
	}
}


template <typename T>
T &Forward_list<T>::front()
{
	if (m_head != NULL)
    	return m_head->next->data;
}

template <typename T>
int Forward_list<T>::size()const
{
	
	if (m_head == m_tail)
    	return 0;
    else
     	return m_size;				
}

template <typename T>
void Forward_list<T>::clear()
{
	Node *slave = m_head->next;
	while (slave != NULL)
	{
		Node *slave2 = slave;
		slave = slave->next;
		delete slave2;
	}
	
	
	m_head->next = m_tail;
	m_size = 0;
}

template <typename T>
bool Forward_list<T>::empty() const
{
	if (m_head == NULL)
    	return true;
    else
    	return false;
}

template <typename T>
T &Forward_list<T>::back()
{

    Node *slave = m_head;
    while (slave->next != NULL) {
    	
        slave = slave->next;

    }

   return slave->data;
}

template <typename T>
const T &Forward_list<T>::back()const
{
    Node *slave = m_head;
    while (slave->next != NULL) {
    	
        slave = slave->next;

    }

    return slave->data;
}

template <typename T>
void Forward_list<T>::push_front(const T &x)
{
	Node *slave = new Node;
	slave->data = x;
	slave->next = m_head->next;
	m_head->next = slave;
	m_size++;
	
    	
}

template <typename T>
void Forward_list<T>::push_back(const T &x)
{
	if (m_head->next != NULL)
	{	
		Node *slave = new Node;
        Node *slave2 = new Node;
        slave2->data = x;
        slave = m_head->next;
        while (slave->next != NULL)
           slave = slave->next;

           slave->next = slave2;

    		m_tail = slave2;
    		m_size++;
		
	}else{
		push_front(x);
		m_size++;
    }
}

template <typename T>
void Forward_list<T>::pop_front()
{
	if (m_head != NULL)
	{
		Node *slave = m_head;
		delete m_head;
		m_head = slave->next;
	}

	m_size--;
    	
}

template <typename T>
void Forward_list<T>::pop_back()
{
	if (m_head->next != m_tail)
	{
		Node *slave = m_head;
		Node *slave2 = NULL;
		while(slave->next!= NULL)
		{
			slave2 = slave;
			slave = slave->next;
		}
			delete slave;
			slave2 -> next = NULL;

			m_tail = slave2;
	}
	m_size--;
}



template <typename T>
void Forward_list<T>::assign( const T &value)
{
	 if (m_head == NULL)
    {
        push_front(value);
    }
    else
    {
    Node *slave = m_head;
    while (slave->next != NULL) {
        slave->data = value;
        slave = slave->next;	
       }
       slave->data = value;
    }
}


template <typename T>
typename Forward_list<T>::const_iterator Forward_list<T>::cbegin() const{
	return typename Forward_list<T>::const_iterator(m_head->next);
}

template <typename T>
typename Forward_list<T>::const_iterator Forward_list<T>::cend() const{
	return typename Forward_list<T>::const_iterator(m_tail);
}

template <typename T>
typename Forward_list<T>::const_iterator Forward_list<T>::cbefore_begin() const{
	return typename Forward_list<T>::const_iterator(m_head);
}

template <typename T>
typename Forward_list<T>::iterator Forward_list<T>::end(){
	return typename Forward_list<T>::iterator(m_tail);
}


template <typename T>
typename Forward_list<T>::iterator Forward_list<T>::begin(){
	return typename Forward_list<T>::iterator(m_head->next);
}


template <typename T>
typename Forward_list<T>::iterator Forward_list<T>::before_begin(){
	return typename Forward_list<T>::iterator(m_head);
}


template <typename T>
typename Forward_list<T>::const_iterator Forward_list<T>::find(const T & x)const
{	Node *slave = m_head->next;
	while(slave != NULL and slave->next != NULL){
		if(slave->data == x)
			return slave;
		slave = slave->next;
	}
    return NULL;
}

template <typename T>
void Forward_list<T>::assign(std::initializer_list <T> ilist){
	for (auto i = ilist.begin(); i != ilist.end(); i++)
	{
		push_back(*i);
	}
}

template <typename T>
typename Forward_list<T>::iterator Forward_list<T>::insert_after(const_iterator itr , const T &x ){
	Node *slave = new Node;
	slave->data = x;
	slave->next = itr.current->next;
	itr.current->next = slave;

	m_size++;
	return itr.current->next;

}

template <typename T>
typename Forward_list<T>::iterator Forward_list<T>::insert_after(const_iterator pos , std::initializer_list <T> ilist){
	
	for (auto i = ilist.begin(); i != ilist.end(); i++)
	{
		Node *slave = new Node;
		slave->data = *i;
		slave->next = pos.current->next;
		pos.current->next = slave;
		m_size++;
	}

	
	return pos.current->next;
}

template <typename T>
typename Forward_list<T>::iterator Forward_list<T>::erase_after (const_iterator itr){
	
	if (itr.current->next != NULL && itr.current->next->next != NULL)
	{
		Node *slave	= itr.current->next;
		itr.current->next = slave->next;
		m_size--;
		delete slave;
					
		
		return Forward_list<T>::iterator(itr.current->next);
	}
	return Forward_list<T>::iterator(itr.current);

}

template <typename T>
typename Forward_list<T>::iterator Forward_list<T>::erase_after (const_iterator first , const_iterator last){
	if (first.current != last.current)
	{
		Node *slave	= new Node;
		Node *slave2 = new Node;
		slave = first.current->next;
		first.current->next = last.current;
		while(slave != NULL){
			slave2 = slave;
			slave = slave->next;
			delete slave2;
			m_size--;
		}
		return last.current;
	}
	return first.current;
}
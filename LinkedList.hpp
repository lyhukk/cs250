#ifndef _LINKED_LIST_HPP
#define _LINKED_LIST_HPP

#include <iostream>
#include <string>
using namespace std;

template <typename T>
struct Node
{
    Node()
    {
        ptrNext = nullptr;
        ptrPrev = nullptr;
    }

    Node<T>* ptrNext;
    Node<T>* ptrPrev;

    T data;
};

template <typename T>
class LinkedList
{
    public:
    LinkedList() // done
    {
        m_ptrFirst = nullptr;
        m_ptrLast = nullptr;
        m_itemCount = 0;
    }

    ~LinkedList() // done
    {
        Free();
    }

    void Push( const T& newItem )
    {
		Node<T>* temp = new Node<T>;
		temp->data = newItem;
		if (m_itemCount == 0) 
		{
			m_ptrFirst = temp;
			m_ptrLast = temp;
			m_itemCount++;
			return;
		}		
		temp->ptrPrev = m_ptrLast;
		m_ptrLast->ptrNext = temp;
		m_ptrLast = temp;
		m_itemCount++;
		return;
    }

    bool Insert( int index, const T& newItem )
    {
		if (index < 0 || index > m_itemCount)
			return false;
		if (index == m_itemCount) 
		{
			Push(newItem);
			return true;
		}
		Node<T>* temp = new Node<T>;
		temp->data = newItem;
		if (index == 0) 
		{
			temp->ptrNext = m_ptrFirst;
			m_ptrFirst->ptrPrev = temp;
			m_ptrFirst = temp;
			m_itemCount++;
			return true;
		}
		Node<T>* curr = m_ptrFirst;
		int count = 0;
		while (count < index) 
		{
			count++;
			curr = curr->ptrNext;
		}
		Node<T>* bef = curr->ptrPrev;
		bef->ptrNext = temp;
		temp->ptrPrev = bef;
		temp->ptrNext = curr;
		curr->ptrPrev = temp;
		m_itemCount++;
		return true;
    }

    void Extend( const LinkedList& other )
    {
		for (int i = 0; i < other.Size(); i++)
		{
			Push(other.Get(i));
		}
    }

    bool Pop()
    {
		if (m_itemCount == 0)
			return false;
		if (m_itemCount == 1)
		{
			Node<T>* curr = m_ptrLast;
			m_ptrFirst = nullptr;
			m_ptrLast = nullptr;
			delete curr;
			m_itemCount--;
			return true;
		}
		Node<T>* curr = m_ptrLast;
		Node<T>* bef = curr->ptrPrev;
		bef->ptrNext = nullptr;
		curr->ptrPrev = nullptr;
		m_ptrLast = bef;
		delete curr;
		m_itemCount--;
		return true;
    }

    bool Remove( int index )
    {
		if (index < 0 || index >= m_itemCount)
			return false;
		if (index == m_itemCount - 1)
		{
			Pop();
			return true;
		}
		if (index == 0)
		{
			Node<T>* curr = m_ptrFirst;
			Node<T>* next = curr->ptrNext;
			next->ptrPrev = nullptr;
			curr->ptrNext = nullptr;
			m_ptrFirst = next;
			delete curr;
			m_itemCount--;
			return true;
		}
		Node<T>* curr = m_ptrFirst;
		int count = 0;
		while (count < index)
		{
			count++;
			curr = curr->ptrNext;
		}
		Node<T>* bef = curr->ptrPrev;
		Node<T>* next = curr->ptrNext;
		bef->ptrNext = next;
		next->ptrPrev = bef;
		curr->ptrNext = nullptr;
		curr->ptrPrev = nullptr;
		delete curr;
		m_itemCount--;
		return true;
    }

    T Get( int index ) const
    {
		if (m_itemCount == 0 || index < 0 || index >= m_itemCount)
			return T();
		if (index == m_itemCount - 1)
			return m_ptrLast->data;
		if (index == 0)
			return m_ptrFirst->data;
		Node<T>* curr = m_ptrFirst;
		int count = 0;
		while (count < index)
		{
			count++;
			curr = curr->ptrNext;
		}
		return curr->data;
    }

    int Size() const // done
    {
        return m_itemCount;
    }

    bool IsEmpty() const // done
    {
        return ( m_ptrFirst == nullptr );
    }

    T operator[]( int index ) // done
    {
        return Get( index );
    }

    LinkedList& operator=( const LinkedList& other )
    {
		Free();
		for (int i = 0; i < other.Size(); i++)
		{
			Push(other.Get(i));
		}
        return (*this); 
    }

    bool operator==( const LinkedList& other )
    {
		if (IsEmpty() && other.IsEmpty())
			return true;
		if (Size() != other.Size())
			return false;
		if (this == &other)
			return true;
		for (int i = 0; i < m_itemCount; i++)
		{
			if (Get(i) != other.Get(i))
				return false;
		}
		return true;
    }

    bool operator!=( const LinkedList& other )
    {
        return !( (*this) == other );
    }

    private:
    void Free() // done
    {
        while ( !IsEmpty() )
        {
            Pop();
        }
    }

    Node<T>* m_ptrFirst;
    Node<T>* m_ptrLast;
    int m_itemCount;
};

#endif

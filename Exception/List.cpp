
#include "stdafx.h"
#include "List.hpp"

List::List()
{
	m_itemCount = 0;
	m_arraySize = 3;
}

void List::Insert(string newItem, int position)
{
	if (position < 0 || position >= m_arraySize)
		throw out_of_range("Out of bounds in insert()");
	m_data[position] = newItem;
}

void List::Delete(int position)
{
	if (position < 0 || position >= m_arraySize)
		throw out_of_range("Out of bounds in delete()");
	m_data[position] = "";
}

string List::GetItem(int position)
{
	if (position < 0 || position >= m_arraySize)
		throw out_of_range("Out of bounds in getItem()");
	return m_data[position];
}
#pragma once
#include <iostream>
#include "clsDblLinkedList.h"


template <class T>
class clsMyQueue
{
protected:
	clsDblLinkedList <T> _MyList;
	
public:

	void push(T value)
	{
		_MyList.InsertAtEnd(value);
	}

	void pop()
	{
		_MyList.DeleteFirstNode();
	}

	int Size()
	{
		return _MyList.Size();
	}

	T front()
	{
		return _MyList.GetItem(0);
	}

	T back()
	{
		return _MyList.GetItem(_MyList.Size() - 1);
	}

	bool IsEmpty()
	{
		_MyList.IsEmpty();
	}

	void Print()
	{
		_MyList.PrintList();
	}

	T GetItem(int Index)
	{
		return _MyList.GetItem(Index);
	}

	void Reverse()
	{
		_MyList.Reverse();
	}

	void UpdateItem(int Index, T value)
	{
		_MyList.UpdateItem(Index, value);
	}

	void InsertAfter(int Index, T value)
	{
		_MyList.InsertAfter(Index, value);
	}

	void InsertAtFront(T value)
	{
		_MyList.InsertAtBeginning(value);
	}

	void InsertAtBack(T value)
	{
		_MyList.InsertAtEnd(value);
	}

	void Clear()
	{
		_MyList.Clear();
	}
};


#pragma once
#include <iostream>
using namespace std;


template <class T> 
class clsDblLinkedList
{
protected:

	int _Size = 0;
	
public:

	class Node
	{
	public:
		T value;
		Node* next;
		Node* prev;
	};
	Node* Head = NULL;


	void PrintList()
	{
		Node* temp = Head;
		while (temp != NULL)
		{
			cout << temp->value << " ";
			temp = temp->next;
		}
	}

	Node* Find(T value)
	{
		Node* temp = Head;
		while (temp != NULL)
		{
			if (temp->value == value)
				return temp;
				
			temp = temp->next;
		}
		return NULL;
	}

	void InsertAtBeginning(T Input)
	{
		Node* newNode = new Node();
		newNode->value = Input;
		newNode->next  = Head;
		newNode->prev  = NULL;

		if (Head != NULL)
		{
			Head->prev = newNode;
		}
		Head = newNode;
		_Size++;
	}

	void InsertAfter(Node* After, T value)
	{
		Node* newNode  = new Node();
		newNode->value = value;
		newNode->next  = After->next; 
		newNode->prev  = After;

		if (After->next != NULL)
			After->next->prev = newNode;
		After->next = newNode;
		_Size++;
	}

	void InsertAtEnd(T value)
	{
		Node* newNode = new Node;
		newNode->value = value;
		newNode->next = NULL;
		if (Head == NULL)
		{
			newNode->prev = NULL;
			Head = newNode;
			_Size++;
			return;
		}
		else
		{
			Node* Last = Head;
			while (Last->next != NULL)
			{
				Last = Last->next;
			}
			Last->next = newNode;
			newNode->prev = Last;
			_Size++;
		}
	}

	void DeleteNode(Node* Delete)
	{
		if (Head == NULL || Delete == NULL)
			return;

		if (Head == Delete)
			Head = Delete->next;

		if(Delete->next != NULL)
			Delete->prev->next = Delete->next;

		if(Delete->prev != NULL)
			Delete->next->prev = Delete->prev;

		delete Delete;
		_Size--;
	}

	void DeleteFirstNode()
	{
		if (Head == NULL)
			return;
		Node* temp = Head;
		Head = Head->next;

		if(Head != NULL)
			Head->prev = NULL;

		delete temp;
		_Size--;
	}

	void DeleteLastNode()
	{
		if (Head == NULL)
			return;
		if (Head->next == NULL)
		{
			delete Head;
			Head = NULL;
			_Size--;
			return;
		}
		Node* temp = Head;
		while (temp->next->next != NULL)
		{
			temp = temp->next;
		}
		Node* Delete = temp->next;
		temp->next = NULL;
		_Size--;
		delete Delete;
	}

	int Size()
	{
		return _Size;
	}

	bool IsEmpty()
	{
		return _Size == 0;
	}

	void Clear()
	{
		while (_Size > 0)
		{
			DeleteFirstNode();
		}
	}

	void Reverse()
	{
		Node* current = Head;
		Node* temp = nullptr;
		while (current != nullptr)
		{
			temp = current->prev;
			current->prev = current->next;
			current->next = temp;
			current = current->prev;
		}
		if (temp != nullptr)
			Head = temp->prev;
	}

	Node* GetNode(int Index)
	{
		if (Index > _Size - 1 || Index < 0)
			return NULL;

		Node* Return = Head;
		int Ind = 0;
		while (Return != NULL && Ind < Index)
		{
			Return = Return->next;
			Ind++;
		}
		return Return;
	}

	T GetItem(int Index)
	{
		Node* temp = GetNode(Index);
		if (temp == NULL)
			return NULL;
		else
			return temp->value;
	}

	bool UpdateItem(int Index, T update)
	{
		Node* U = GetNode(Index);
		if (U != NULL)
		{
			U->value = update;
			return true;
		}
		else
			return false;
	}

	bool InsertAfter(int Index, T Insert)
	{
		Node* After = GetNode(Index);
		
		if (After != NULL)
		{
			InsertAfter(After, Insert);
			return true;
		}
		return false;
	}
};


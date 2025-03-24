//============================================================================
// Name        : LinkedQueue.cpp
// Date        : June 16, 2024
// Author      : Alsayed A. Aldkhakhni
// Copyright   : Feel free to use.
// Description : Construct our Queue data structure using linked list.
//============================================================================

// preprocessor directive: a file contians some predefined entities.
#include <iostream>  // for using 'cin' and 'cout' objects.
using namespace std; // contains the definition of how those object operate.

// template class that handles primitive data type.
template <class T>
class LinkedQueue// class specifier.
{
	// #HINT: I used  a class instead of struct,
	//        to use the ctor to avoid much typing.
	class Node
	{
	public:
		T data;
		Node* next;
		Node(T dt, Node* nxt = NULL) : data(dt), next(nxt) {}
	};

private:
	Node* Head; // list's front.
	Node* Tail; // list's back.

public:
	// inner class exception handler.
	class Exception
	{
	public:
		Exception(const char* msg) { cout << "\n" << msg << "\n"; }
	};

	// no-argument constructor to initialize the data members.
	LinkedQueue() : Head(NULL), Tail(NULL) {}

	// inserting an item to the queue.
	void enQueue(T val)
	{
		Node* newNode = new Node(val);

		// check if there are elements or not.
		if(isEmpty())
			Head = Tail = newNode;
		else
		{
			Tail->next = newNode;
			Tail = newNode;
		}
	}

	// removing an item from the queue.
	void deQueue()
	{
		// check if the queue is empty.
		if(isEmpty())
			throw Exception("Underflow.");
		else
		{
			Node* temp = Head;
			Head = Head->next;

			temp->next = NULL; // isolate the node.

			delete temp;
		}
	}

	// is the queue empty or not?
	bool isEmpty() { return Head == NULL; }

	// retrieve the queue's head.
	T peek() { return Head->data; }

	// display the items in the queue.
	void display()
	{
		if(! isEmpty())
		{
			Node* temp = Head;

			cout << "\n\n   Head\n"
				 << "    |\n"
				 << "    v\n";

			cout << "-------------------------------"\
					"----------------------------------------\n";

			while(temp != NULL)
			{
				cout << "|   " << temp->data << "   ";
				temp = temp->next;
			}

			cout << "|\n-------------------------------"\
					"----------------------------------------\n";
		}
		else
			throw Exception("List's empty.");
	}

	// release the memory occupied for this queue.
	~LinkedQueue() { while(!isEmpty()) deQueue(); } 
};




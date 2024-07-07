//============================================================================
// Name        : LinkedStack.cpp
// Date        : June 16, 2024
// Author      : Alsayed-Aldkhakhni
// Version     : V1.1
// Copyright   : Nothing to be mentioned.
// Description : Simulate stack data structure based on linked list.
//============================================================================

// preprocessor directive, instructs the preprocessor, a part of the compiler,
//  to pre-fetch the content of this header file, iostream,
//  to the current source file since we need it for using 'cin' and 'cout' objects.
#include <iostream>
using namespace std; // contains the definition of how those object operate.

// template class to handle any primitive data type.
template <class T>
class LinkedStack
{
	class Node
	{
	public:
		T data;
		Node* next;
		Node(T dt, Node* nxt = NULL) : data(dt), next(nxt) {}
	};

private:
	Node* TOP; // list's head.

public:

	// inner class exception handler.
	class Exception
	{
	public:
		Exception(const char* msg) { cout << "\n" << msg << "\n"; }
	};

	// initialize the head to point to nothing.
	LinkedStack() : TOP(NULL) {}

	// pushing or adding a new item on the stack.
	void push(T val)
	{
		Node* newNode = new Node(val);

		if(TOP == NULL) // also as [TOP == 0]
			TOP = newNode;
		else
		{
			newNode->next = TOP;
			TOP = newNode;
		}
	}

	// popping or removing an item exists already on the stack.
	T pop()
	{
		if(isEmpty())
			throw Exception("Underflow.");

		cout << peek() << " is popped.\n";

		Node* temp = TOP;
		TOP = TOP->next;
		T data = temp->data;

		// isolate the node and delete it.
		temp->next = NULL;
		delete temp;

		return data;
	}

	// check the if there is no element on the stack yet.
	bool isEmpty() { return TOP == NULL; }

	// return the data at the top of the stack.
	T peek() { return isEmpty() ? throw Exception("Stack is empty."): TOP->data; }

	// traverse on the stack's elements.
	void display()
	{
		if(isEmpty())
			throw Exception("Stack is empty.");

		Node* temp = TOP;

		while(temp != NULL)
		{
			cout << "\n---------\n";
			cout << "|   " << temp->data << "   |";

			if(temp == TOP)
				cout << "   <---- TOP.";

			temp = temp->next();
		}

		cout << "\n---------\n\n";
	}

	// delete the whole stack after we finished.
	~LinkedStack()
	{
		while(! isEmpty()) pop();
		cout << "\n'released memory space.'\n";
	}
};

int main()
{
	try
	{
		// instantiate an object of that class of characters.
		LinkedStack<char> charStack;

		// pushing some items.
		charStack.push('A');
		charStack.push('B');
		charStack.push('C');
		charStack.push('D');
		charStack.push('E');

		// display them.
		charStack.display();
	}
	catch(LinkedStack<char>::Exception)
	{}

	// indicates successful execution.
	return 0;

}  // once we get here the destructor will destroy the whole stack automatically from memory.


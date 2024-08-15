//============================================================================
// Name        : LinkedStack.cpp
// Date        : June 16, 2024
// Author      : Alsayed_Ali_Aldkhakhni
// Copyright   : Nothing to be mentioned.
// Description : Construct stack data structure based on linked list.
//============================================================================

// preprocessor directive, instructs the preprocessor
//  to pre-fetch the content of this header file, iostream,
//  to the current source file since we need it for using 'cin' and 'cout' objects.
#include <iostream> // contains the declaration of those objects, cin and cout.
using namespace std;// contains the definition of how those objects operate.

// template class to handle any primitive data type.
template <class T>
class LinkedStack // class definition.
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

		if(TOP == NULL) // or if(TOP == 0)
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

			temp = temp->next;
		}

		cout << "\n---------\n\n";
	}

	// released memory space that was dedicated to the list.
	~LinkedStack() { while(! isEmpty()) pop(); }
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
		
		// display the data just pushed.
		charStack.display();
		
		charStack.pop(); // E
		charStack.pop(); // D
		charStack.pop(); // C
		charStack.pop(); // B
		charStack.pop(); // A
		charStack.pop(); // will thorw an exception.
	}
	catch(const LinkedStack<char>::Exception&)
	{}

	// indicates successful execution.
	// that means that the system will pop
	// the function main off the system stack.
	return 0;

}  // once we get here the destructor will destroy the whole stack automatically from memory.










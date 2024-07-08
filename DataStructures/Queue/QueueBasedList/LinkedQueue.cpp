//============================================================================
// Name        : LinkedQueue.cpp
// Date        : June 16, 2024
// Author      : Alsayed-Aldkhakhni
// Version     : V1.0
// Copyright   : Nothing to be mentioned.
// Description : Simulate Queue data structure using linked list.
//============================================================================

// preprocessor directive, instructs the preprocessor, a part of the compiler,
// to pre-fetch the content of this header file, io-stream,
// to the current source file since we need it for using 'c in' and 'c out' objects.
#include <iostream>
using namespace std; // contains the definition of how those object operate.

// template class that handles primitive data type.
template <class T>
class LinkedQueue// class specifier.
{
	// #HINT: i used class instead of struct,
	//        just to use the ctor to avoid much typing.
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

		cout << Tail->data << " entered the queue.\n";
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

			cout << temp->data << " is dequeued.\n";
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

			cout << "-------------------------------"
					"----------------------------------------\n";

			while(temp != NULL)
			{
				cout << "|   " << temp->data << "   ";
				temp = temp->next;
			}

			cout << "|\n-------------------------------"
					"----------------------------------------\n\n\n";
		}
		else
			throw Exception("List's empty.");
	}

	// release the memory occupied for this queue.
	~LinkedQueue() { while(!isEmpty()) deQueue(); cout << "\n---> memory is released.\n"; }
};

int main()
{
	try{
		// instantiate an object of 'LinkedQueue' class.
		LinkedQueue<char> charQueue1;

		// inserting some items.
		charQueue1.enQueue('A');
		charQueue1.enQueue('B');
		charQueue1.enQueue('C');
		charQueue1.enQueue('D');
		charQueue1.enQueue('E');

		// display them.
		charQueue1.display();

		// removing the current 1st item.
		charQueue1.deQueue();
		charQueue1.display();

		// remove the the 2nd.
		charQueue1.deQueue();
		charQueue1.display();

		// the 3rd.
		charQueue1.deQueue();
		charQueue1.display();

		// adding some more items.
		charQueue1.enQueue('F');
		charQueue1.enQueue('G');
		charQueue1.enQueue('H');
		charQueue1.enQueue('I');
		charQueue1.enQueue('J');

		// display them.
		charQueue1.display();

	}catch(LinkedQueue<char>::Exception&)
	{}

	// indicates a successful execution.
	return 0;
}

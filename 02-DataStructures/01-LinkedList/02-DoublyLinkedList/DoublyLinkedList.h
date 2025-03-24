//============================================================================
// Name        : DoublyLinkedList.h
// Date        : June 18, 2024
// Author      : Alsayed A. Aldkhakhni
// Copyright   : Feel free to use.
// Description : Doubly linked list data structure implementation.
//============================================================================


// Those 1st 2 lines are called preprocessor directives.
// Those contains predefinied objects and methods which
// we use in this source file as [cout and cin] those 
// are objects that helps us to read and write data to
// the screen or read it from the user at the keyboard.
#include <iostream> // for the declaration.
using namespace std;// for the  definition.

// generic class that handles any data type from the primitives.
template <class T>
class DoublyLinkedList // class specifier.
{
	class Node     // class tag.
	{
	public:
		T data;
		Node* next;
		Node* prev;
		Node(T dt, Node* nxt = NULL, Node* prv = NULL) : data(dt), next(nxt), prev(prv) {}
	};

private: // data members.
	Node* Head;
	Node* Tail;

public:
	// inner class exception handler.
	class Exception
	{
	public:
		Exception(const char* msg) { cout << "\n" << msg << "\n"; }
	};

	// no-argument constructor to initialize the data members.
	DoublyLinkedList() : Head(NULL), Tail(NULL) {}

	// by default add at the end of the list.
	void insert(T data) { insertAtTail(data); }

	// add a node at the front of the list.
	void insertAtHead(T data)
	{
		Node* newNode = new Node(data);

		if(isEmpty())
			Head = Tail = newNode;
		else
		{
			Head->prev = newNode;
			newNode->next = Head;
			Head = newNode;
		}
	}

	// append a node at the end of the list.
	void insertAtTail(T data)
	{
		Node* newNode = new Node(data);

		if(isEmpty())
			Head = Tail = newNode;
		else
		{
			// connect the node with the list.
			Tail->next = newNode;
			newNode->prev = Tail;
			Tail = newNode;
		}
	}

	// delete the head without traversing.
	void deleteHead()
	{
		// avoid crashing.
		if(isEmpty())
			throw Exception("List's empty.");

		Node* temp = Head;
		Head = Head->next;

		// isolate the node.
		Head->prev = NULL;
		temp->next = NULL;

		// delete it.
		delete temp;
	}

	// delete tail without traversing.
	void deleteTail()
	{
		// avoid crashing.
		if(isEmpty())
			throw Exception("List's empty.");

		// change the connections.
		Node* temp = Tail;
		Tail = Tail->prev;

		// isolate the node.
		Tail->next = NULL;
		temp->prev = NULL;

		// delete the list't back.
		delete temp;
	}

	// delete a specified node.
	void deleteAt(T data)
	{
		// avoid crashing.
		if(isEmpty())
			throw Exception("List's empty.");
		else if(data == Head->data)// if we need the head.
			deleteHead();
		else if(data == Tail->data)// or it is the tail.
			deleteTail();
		else		           // otherwise.
		{
			// using to traverse.
			Node* temp = Head->next;
			while(temp != NULL)
			{
				// if you got it.
				if(temp->data == data)
				{
					// take a reference.
					Node* delNode = temp;

					// handling the connections.
					temp->next->prev = temp->prev;
					temp->prev->next = temp->next;

					// isolate the node from the list.
					delNode->next = NULL;
					delNode->prev = NULL;

					// delete the node.
					delete delNode;
					return;
				}

				// if not, move to the next node.
				temp = temp->next;
			}

			// it not exist in the list.
			if(temp == NULL) cout << data << " doesn't exist.\n";
		}
	}

	// display the list's content from the head up to the tail.
	void displayFromHead()
	{
		// avoid unnecessary execution.
		if(isEmpty())
			throw Exception("List's empty.");

		Node* temp = Head;

		cout << "   Head\n    |\n    V\n";
		while(temp != NULL)
		{
			cout << "|   " << temp->data << "   ";
			temp = temp->next;
		}

		cout << "|\n\n";
	}

	// display the list's content from the tail up to the head.
	void displayFromTail()
	{
		if(isEmpty())
			throw Exception("List's empty.");

		Node* temp = Tail;

		cout << "   Tail\n    |\n    V\n";
		while(temp != NULL)
		{
			cout << "|   " << temp->data << "   ";
			temp = temp->prev;
		}

		cout << "|\n\n";
	}

	// useful function.
	bool isEmpty() { return Head == NULL; } 

	// release the dedicated memory space for this list.
	~DoublyLinkedList() 
	{
		Node* temp = Head;
		while(temp != NULL)
		{
			Head = Head->next;
			delete temp;
			temp = Head;
		}
	}
};



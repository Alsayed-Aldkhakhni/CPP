//============================================================================
// Name        : DoublyLinkedList.cpp
// Date        : June 18, 2024
// Author      : Alsayed_Ali_Aldkhakhni
// Copyright   : Nothing to be mentioned.
// Description : Doubly linked list implementation.
//============================================================================

#include <iostream> // the declaration of objects 'cin' and 'cout'.
using namespace std;// their definition.

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
	int nodesCount;

	// this method releases the memory occupied by list's nodes.
	//  it's private since the user has no permissions to call it, the destructor does.
	void releaseMemory()
	{
		Node* temp = Head;

		while(temp != NULL)
		{
			Head = Head->next;
			cout << temp->data << " is destroyed.\n";
			delete temp;
			temp = Head;
		}
	}

public:

	// inner class exception handler.
	class Exception
	{
	public:
		Exception(const char* msg) { cout << "\n" << msg << "\n"; }
	};

	// no-argument constructor to initialize the data members.
	DoublyLinkedList() : Head(NULL), Tail(NULL), nodesCount(0) {}

	// by default add at the end of the list.
	void insert(T data)	{ insertAtTail(data); }

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

		cout << data << " is inserted.\n";
		nodesCount++;
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

		cout << data << " is inserted.\n";
		nodesCount++;
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
		cout << "Head " << temp->data << " is deleted.\n";
		delete temp;
		nodesCount--;
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
		cout << "Tail " << temp->data << " is deleted.\n";
		delete temp;
		nodesCount--;
	}

	// delete a specified node.
	void deleteAt(T data)
	{
		// avoid crashing.
		if(isEmpty())
			throw Exception("List's empty.");

		if(data == Head->data)     // if we need the head.
			deleteHead();
		else if(data == Tail->data)// or it is the tail.
			deleteTail();
		else		               // otherwise.
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
					cout << delNode->data << " is deleted.\n";
					delete delNode;
					nodesCount--;
					return;
				}

				// if not, move to the next node.
				temp = temp->next;
			}

			// it not exist in the list.
			if(temp == NULL) cout << data << " doesn't exist.\n";
		}
	}

	// display how many nodes there are.
	void displayMains() { cout << "\nThere is/are " << getNodesCount() << " node(s) in the list.\n"; }

	// display the list's content from the head up to the tail.
	void displayFromHead()
	{
		// avoid unnecessary execution.
		if(isEmpty())
			throw Exception("List's empty.");

		displayMains();
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

		displayMains();
		Node* temp = Tail;

		cout << "   Tail\n    |\n    V\n";
		while(temp != NULL)
		{
			cout << "|   " << temp->data << "   ";
			temp = temp->prev;
		}

		cout << "|\n\n";
	}

	// useful functions.
	bool isEmpty()      { return Head == NULL;} // or tail == NULL or nodesCount == 0.
	int getNodesCount() { return nodesCount; }

	// release the dedicated memory space to this list.
	~DoublyLinkedList() { releaseMemory(); }
};



int main()
{
	try{
		// instantiate an object of this list.
		DoublyLinkedList<int> intDoubList;

		// insert some data.
		intDoubList.insert(10);
		intDoubList.insert(20);
		intDoubList.insert(30);
		intDoubList.insert(40);
		intDoubList.insert(50);
		intDoubList.insert(60);
		intDoubList.insert(70);
		intDoubList.insert(80);
		intDoubList.insert(90);
		intDoubList.insert(100);

		// display the list in a normal order.
		intDoubList.displayFromHead();

		// delete node that stores data 20.
		intDoubList.deleteAt(30);

		// display in the reversed order.
		intDoubList.displayFromHead();

		// delete both nodes, head & tail.
		intDoubList.deleteHead();
		intDoubList.deleteTail();

		// display the rest.
		intDoubList.displayFromHead();

		// reinsert the nodes at head and tail.
		intDoubList.insertAtHead(10);
		intDoubList.insertAtTail(100);

		// display the list.
		intDoubList.displayFromHead();

	}
	catch(const DoublyLinkedList<int>::Exception&)
	{}

	// indicates a successful execution.
	return 0;
}








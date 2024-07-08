//============================================================================
// Name        : SinglyLinkedList.cpp
// Date        : June 18, 2024
// Author      : Alsayed-Aldkhakhni
// Version     : V1.0
// Copyright   : Nothing to be mentioned.
// Description : Singly linked list implementation.
//============================================================================

// preprocessor directive instructs the preprocessor, a part of the compiler,
//  to substitute those header files by their content which we need to specify
//  the behavior of some predefined objects as 'cin' and 'cout' we used here.
#include <iostream> // the declaration.
using namespace std;// the definition.

// generic type to handle any primitive.
template <class T>
class LinkedList // class specifier.
{
	class Node
	{
	public:
		T data;
		Node* next;
		Node(T dt, Node* nxt = NULL) : data(dt), next(nxt) {}
	};

private:
	Node* Head; // to point to the list's head;
	Node* Tail; // to append a node at O(1) instead of looping up to the end.
	int nodesCount; // trace how many nodes does the list have.

	// * remove the list totally from the memory.
	// * this function is private since the user has no permission to access it.
	void releaseMemory()
	{
		Node* temp = Head;

		while(temp != NULL)
		{
			Head = Head->next;
			temp->next = NULL;

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

	// no-argument constructor, initialize the data members.
	LinkedList() : Head(NULL), Tail(NULL), nodesCount(0) {}

	// insert a new node at the end.
	void insert(T data)
	{
		Node* newNode = new Node(data);

		if(isEmpty())
			Head = Tail = newNode;
		else
		{
			Tail->next = newNode;
			Tail = newNode;
		}

		cout << data << " is inserted.\n";
		nodesCount++; // a node is added  successfully.
	}

	// insert a node before the head one.
	void insertAtHead(T data)
	{
		Node* newNode = new Node(data);

		if(isEmpty())
			Head = Tail = newNode;
		else
		{
			newNode->next = Head;
			Head = newNode;
		}

		nodesCount++;
	}

	// insert before another specific node.
	void insertBefore(T beforeWhat, T insertWhat) // 30,25
	{
		// if we have no data yet.
		if(isEmpty())
		{
			insertAtHead(insertWhat);
			return;
		}

		// if that node we want to insert before is the head.
		if(beforeWhat == Head->data)
			insertAtHead(insertWhat);
		else
		{
			// create the new node to store the data.
			Node* newNode = new Node(insertWhat); // 25

			// to search for the target.
			Node* temp = Head;
			int count = getNodesCount();

			// to avoid dereferencing the 'NULL' at the end of the list.
			while(count > 1) // temp->next != NULL
			{
				// check the nodes' data.
				if(temp->next->data == beforeWhat)
				{
					// connect the node with the list.
					newNode->next = temp->next;
					temp->next = newNode;

					// inform the insertion is done.
					cout << insertWhat << " is inserted.\n\n";
					nodesCount++;
					return; // break;
				}

				temp = temp->next;
				count--;
			}
		}
	}

	// delete a node by its stored data.
	void deleteAt(T deleteWhat)
	{
		// avoid crashing.
		if(isEmpty())
			throw Exception("List's empty.");

		// take a reference to the node.
		Node* temp = Head;

		// if it is the head.
		if(deleteWhat == Head->data)
		{
			// move list's head to the next node.
			Head = Head->next;

			// isolate and delete node.
			temp->next = NULL;
			delete temp;
			nodesCount--;
		}
		else
		{
			// if the node is not the head, search for it.
			while(temp->next != NULL)
			{
				// if we got it.
				if(temp->next->data == deleteWhat)
				{
					// take a reference to delete from memory.
					Node* delNode = temp->next;
					temp->next = delNode->next;

					// without this you won't be able to insert an item after a deletion.
					if(Tail == delNode) Tail = temp;

					delNode->next = NULL;
					cout << delNode->data << " is deleted.\n";

					delete delNode;
					nodesCount--;
					return; // break;
				}

				temp = temp->next;
			}
		}
	}

	// reverse the list by making its Head to be its Tail and its Tail to be its Head.
	void reverseOrder()
	{
		// traversal pointers.
		Node* pre  = NULL;
		Node* temp = NULL;

		while(Head != NULL)
		{
			temp = Head->next;
			Head->next = pre;
			pre = Head;
			Head = temp;
		}

		// this step is essential since we use the 'Head' to handle the list not 'pre',
		//   but at the end of this process the Head's content will be 'NULL',
		//   and you won't be able to operate on the list any more since you have not the list's head.
		Head = pre;
		cout << "The list's order is reversed.\n";
	}

	// display the nodes stored in the list.
	void display()
	{
		if(isEmpty())
			throw Exception("List's empty.");

		// inform the current status briefly.
		cout << "\nThere is/are " << getNodesCount() << " node(s) in the list.\n\n";
		cout << "   Head\n    |\n    V\n";

		Node* temp = Head;
		while(temp != NULL)
		{
			cout << "|   " << temp->data << "   ";
			temp = temp->next;
		}

		cout << "|\n\n";
	}

	// useful functions.
	bool isEmpty() { return Head == NULL; }
	int getNodesCount() { return nodesCount; }

	// clear the memory.
	~LinkedList() { releaseMemory(); }
};


int main()
{
	try{
		// instantiate an object of that list class.
		LinkedList<int> intList;

		// insert some data in it.
		intList.insert(10);
		intList.insert(20);
		intList.insert(30);
		intList.insertBefore(30, 25);

		// show the changes.
		intList.display(); // 10 20 25 30

		// delete some of them.
		intList.deleteAt(20); // 20 is gone.
		intList.deleteAt(30); // 30 is gone.

		// insert at end after deleting the Tail.
		intList.insert(50);

		// display the changes.
		intList.display(); // 10 25 50

		// reverse the list's order and display the new order.
		intList.reverseOrder();
		intList.display();    // 50 25 10
	}
	catch (LinkedList<int>::Exception&)
	{}

	// indicates a successful execution.
	return 0;
}

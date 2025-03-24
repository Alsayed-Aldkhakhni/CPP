//============================================================================
// Name        : SinglyLinkedList.h
// Author      : Alsayed A. Aldkhakhni
// Date        : September 5, 2024
// Copyright   : Feel free to use.
// Description : Construct the data structure Linked list.
//============================================================================


// preprocessor directive:
// It is a file that includes predefined objects
// and methods we use directly without rewriting them.
#include <iostream> // for the declaration of objects cin, cout.
using namespace std;// for their definition.

template <class T>  // generic type, to be suitable for any primitive.
class LinkedList
{
	// the linked list building blocks.
	struct Node {
		T data;
		Node* next = NULL;
	};

private:
	Node* head; // to point to the list's head;
	Node* Tail; // to append a node at O(1) instead of looping up to the end.

public:
	// inner class exception handler.
	class Exception
	{
	public:
		Exception(const char* msg) { cout << "\n" << msg << "\n"; }
	};

	// no-argument constructor, initialize the data members.
	LinkedList() : head(NULL), Tail(NULL) {}

	// insert a new node at the end.
	void insert(T data)
	{
		Node* newNode = new Node();
		newNode->data = data;

		if(isEmpty())
			head = Tail = newNode;
		else
		{
			Tail->next = newNode;
			Tail = newNode;
		}
	}

	// insert before another specific node.
	void insert(T val, T pos)
	{
		// if we have no data yet.
		if(isEmpty())
		{
			insert(val);
			return;
		}
		
		// create the new node to store the data.
		Node* newNode = new Node();
		newNode->data = val;
		
		// if that node we want to insert before is the head.
		if(pos == head->data)
		{
			newNode->next = head;
			head = newNode;
		}
		else
		{
			// to search for the target.
			Node* temp = head;

			// to avoid dereferencing the 'NULL' at the end of the list.
			while(temp->next != NULL)
			{
				// check the nodes' data.
				if(temp->next->data == pos)
				{
					// connect the node with the list.
					newNode->next = temp->next;
					temp->next = newNode;
					return; // break;
				}

				temp = temp->next;
			}
		}
	}

	// delete a node by its stored data.
	void remove(T val)
	{
		// avoid crashing.
		if(isEmpty())
			throw Exception("List's empty.");

		// take a reference to the node.
		Node* temp = head;

		// if it is the head.
		if(val == head->data)
		{
			head = head->next; // move list's head to the next node.
			temp->next = NULL; // isolate and delete node.
			delete temp;       // remove the node.
		}
		else
		{
			// if the node is not the head, search for it.
			while(temp->next != NULL)
			{
				// if we got it.
				if(temp->next->data == val)
				{
					// take a reference to delete from memory.
					Node* delNode = temp->next;
					temp->next = delNode->next;

					// without this you won't be able to insert an item after a deletion.
					if(Tail == delNode)
						Tail = temp;

					delNode->next = NULL;

					delete delNode;
					return; // break;
				}

				temp = temp->next;
			}
		}
	}

	// reverse the list by making its head to be its Tail and its Tail to be its head.
	void reverse()
	{
		// traversal pointers.
		Node* pre  = NULL;
		Node* temp = NULL;

		while(head != NULL)
		{
			temp = head->next;
			head->next = pre;
			pre = head;
			head = temp;
		}

		// this step is essential since we use the 'head' to handle the list not 'pre'
		// but at the end of this process the head's content will be 'NULL'
		// and you won't be able to operate on the list any more since you have not the list's head.
		head = pre;
	}

	// display the nodes stored in the list.
	void display()
	{
		if(isEmpty())
			throw Exception("List's empty.");

		cout << "   head\n    |\n    V\n";

		Node* temp = head;
		while(temp != NULL)
		{
			cout << "|   " << temp->data << "   ";
			temp = temp->next;
		}

		cout << "|\n\n";
	}

	// modify existing node's value.
	void mod(T oldVal, T newVal)
	{
		// no items to modify.
		if(isEmpty())
			return;
		// if the target is the head or the tail.
		else if(oldVal == head->data)
			head->data = newVal;
		else if(oldVal == tail->data)
			tail->data = newVal;
		else
		{
			Node* temp = head->next;
			while(temp != NULL)
			{
				if(temp->data == oldVal)
				{
					temp->data = newVal;
					break;
				}

				temp = temp->next;
			}
		}
	}

	// useful function.
	bool isEmpty() { return head == NULL; }

	// release the memory dedicated to the list's nodes.
	~LinkedList()
	{
		Node* temp = head;

		while(temp != NULL)
		{
			head = head->next;
			delete temp;
			temp = head;
		}
	}
};



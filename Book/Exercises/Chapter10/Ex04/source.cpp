/*
 * Subject: Linked list implementation.
 *
 * Date: July 22, 2024
 *
 * Author: Alsayed-Aldkhakhni
 *
 * Last modification: July 22, 2024
 *
 * */

#include <iostream> // for the declaration of cin, cout objects.
using namespace std;// for their definition.

//########################################################//
struct Link
{
	int data;
	Link* next;
};

class LinkedList
{
private:
	Link* first;
public:
	LinkedList(): first(NULL) {}
	void addItem(int d);
	void display();
	~LinkedList();
};

// add new items.
void LinkedList::addItem(int d)
{
	Link* newLink = new Link;
	newLink->data = d;
	newLink->next = first;
	first = newLink;
}

// display the list's content.
void LinkedList::display()
{
	Link* current = first;
	while( current != NULL )
	{
		cout << current->data << endl;
		current = current->next;
	}
}

// destroy the list.
LinkedList::~LinkedList()
{
	Link* temp = first;

	while(first != NULL)
	{
		first = first->next;

		temp->next = NULL;
		//cout << temp->data << " is destroyed.\n";
		delete temp;

		temp = first;
	}
}
//########################################################//

int main()
{
	LinkedList lst1;

	// add some items.
	lst1.addItem(12);
	lst1.addItem(13);
	lst1.addItem(14);
	lst1.addItem(15);
	lst1.addItem(16);
	lst1.addItem(17);
	lst1.addItem(18);
	lst1.addItem(19);
	lst1.addItem(20);
	lst1.addItem(21);

	// display the items.
	lst1.display();

	// indicates a successful execution, popping the function off the stack.
	return 0;
}



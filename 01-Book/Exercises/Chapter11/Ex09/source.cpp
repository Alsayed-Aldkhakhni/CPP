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
	Link* last;
	Link* stop;
public:
	LinkedList(): first(NULL), last(NULL), stop(NULL) {}
	LinkedList(const LinkedList& list1);
	void operator=(const LinkedList& list1);
	void addItem(int d);
	void display();
	~LinkedList();
};

// assingment operator.
void LinkedList::operator=(const LinkedList& list1)
{
	Link* inTemp = list1.first;

	// 12
	// 100 200
	if(inTemp == NULL)return;// list1 is empty.
	if(this == &list1)return;// lists are the same.

	Link* currentTemp = first;

	while(currentTemp != NULL && inTemp != NULL)
	{
		currentTemp->data = inTemp->data;
		currentTemp = currentTemp->next;
		inTemp      = inTemp->next;
	}
	
	if(currentTemp != NULL)
	{
		stop = currentTemp;
		return;
	}

	while(inTemp != NULL)
	{
		addItem(inTemp->data);
		inTemp = inTemp->next;
	}
}

// unfinished.

// one-arg ctor.
// X(X&)
LinkedList::LinkedList(const LinkedList& list1)
{
	if(this == &list1) return;
	if(list1.first == NULL) return;

	Link* inTemp = list1.first;
	
	// is important.
	first =	last = stop = NULL;

	while(inTemp != NULL)
	{
		addItem(inTemp->data);
		inTemp = inTemp->next;
	}
}


// add new items.
void LinkedList::addItem(int d)
{
	Link* newLink = new Link;
	newLink->data = d;
	newLink->next = NULL;

	if(first == NULL)
		last = first = newLink;
	else
	{
		if(stop != NULL)
		{
			stop->data = d;
			stop = stop->next;
			return;
		}

		last->next = newLink;
		newLink->next = NULL;
		last = newLink;
	}
}

// display the list's content.
void LinkedList::display()
{
	Link* current = first;
	cout << "\n====================================================\n";
	while( current != stop )
	{
		cout << current->data << ",  ";
		current = current->next;
	}
	cout << "\n====================================================\n";
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
	LinkedList lst1, lst2;

	// add some items.
	lst1.addItem(10);
	lst1.addItem(11);
	lst1.addItem(12);
	lst1.addItem(13);
	lst1.addItem(14);
	lst1.addItem(15);
	lst1.addItem(16);
	lst1.addItem(17);
	lst1.addItem(18);
	lst1.addItem(19);
	lst1.addItem(20);

	cout << "List1: ";
	lst1.display();
	cout << '\n';

	lst2.addItem(100);
	lst2.addItem(200);

	cout << "List2: ";
	lst2.display();
	
	//lst1 = lst1;// self-assignment won't work.
	lst2 = lst1;

	cout << '\n';

	cout << "\n----------------------------\n\n";

	// display the items.
	cout << "List1: ";
	lst1.display();

	cout << '\n';

	cout << "List2: ";
	lst2.display();

	cout << "\n----------------------------\n";

	//LinkedList lst3 = lst3;// self-assignment.
	LinkedList lst3 =  lst1;

	cout << "\nList3: ";
	lst3.display();

	// indicates a successful execution, popping the function off the stack.
	return 0;
}


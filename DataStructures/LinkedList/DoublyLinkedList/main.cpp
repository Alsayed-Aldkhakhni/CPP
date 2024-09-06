//============================================================================
// Name        : main.cpp 
// Date        : June 18, 2024
// Author      : Alsayed A. Aldkhakhni
// Copyright   : Feel free to use.
// Description : Test the new class.
//============================================================================{

// the reference of our homemade data structure.
#include "DoublyLinkedList.h"
int main()
{

	try{
		// instantiate a list of ints.
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

		// display from the other edge of the list.
		intDoubList.displayFromTail();

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

	// Indicates a successful execution, which means
	// that the method is popped off the stack.
	return 0;
}



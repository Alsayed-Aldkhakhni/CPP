//============================================================================
// Name        : main.cpp 
// Author      : Alsayed A. Aldkhakhni
// Date        : September 5, 2024
// Copyright   : Feel free to use.
// Description : Test our homemade data structure Linked list.
//============================================================================

#include "SinglyLinkedList.h"

int main()
{
	try{
		// instantiate an object of that list class.
		LinkedList<int> intList;

		// insert some data in it.
		intList.insert(10);
		intList.insert(20);
		intList.insert(30);
		intList.insert(25, 30);

		// show the changes.
		intList.display(); // 10 20 25 30

		// delete some of them.
		intList.remove(20); // 20 is gone.
		intList.remove(30); // 30 is gone.

		intList.display(); // 50 25 10

		// insert at end after deleting the Tail.
		intList.insert(50);

		// display the changes.
		intList.display(); // 10 25 50

		// reverse the list's order and display the new order.
		intList.reverse();
		intList.display(); // 50 25 10
	}
	catch (const LinkedList<int>::Exception&)
	{}

	// indicates a successful execution.
	// popping the method of the stack.
	return 0;
}



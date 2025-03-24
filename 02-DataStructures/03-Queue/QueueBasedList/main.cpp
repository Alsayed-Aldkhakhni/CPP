//============================================================================
// Name        : main.cpp
// Date        : June 16, 2024
// Author      : Alsayed A. Aldkhakhni
// Copyright   : Feel free to use.
// Description : Test our Queue data structure.
//============================================================================

// the reference of our queue class.
#include "LinkedQueue.h"

int main()
{
	try{
		// instantiate an queue chars.
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

	}catch(const LinkedQueue<char>::Exception&)
	{}

	// indicates a successful execution.
	return 0;
}




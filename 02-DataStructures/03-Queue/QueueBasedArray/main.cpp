//============================================================================
// Name        : main.cpp
// Date        : June 18, 2024
// Author      : Alsayed A. Aldkhakhni
// Copyright   : Feel free to use.
// Description : Test our homemade queue.
//============================================================================

// the reference of our
// homemade data structure.
#include "Queue.h"

int main()
{
	try{
		// instantiate a Queue to
		// store data of type int.
		Queue<int> queue1(5);

		// adding some data.
		queue1.enQueue(11);
		queue1.enQueue(12);
		queue1.enQueue(13);
		queue1.enQueue(14);
		queue1.enQueue(15);

		// display the queue's content.
		queue1.display(); // 11 12 13 14 15

		// remove the first item.
		queue1.deQueue(); // 11 is gone.

		// display again.
		queue1.display(); // 12 13 14 15

		//rear  front
		// |     |
		// V     V
		// 16    12 13 14 15   <----- data.
		// 0     1  2  3  4    <----- indexes.
		queue1.enQueue(16);
		//queue1.enQueue(17); // overflow.

		// display the queue's content.
		queue1.display(); // 12 13 14 15 16

		queue1.deQueue(); // 12 is gone.
		queue1.deQueue(); // 13 is gone.

		queue1.display(); // 14 15 16 
	}
	catch(const Queue<int>::Exception&)
	{}

	// indicates a successful execution, which means 
	// popping the method 'main()' of the stack.
	return 0;
}




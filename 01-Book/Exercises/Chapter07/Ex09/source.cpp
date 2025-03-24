//============================================================================
// Name        : source.cpp
// Date        : July 12, 2024
// Author      : Alsayed-Aldkhakhni
// Version     : V1.0
// Copyright   : Nothing to be mentioned.
// Description : Queue data storage device implementation.
//============================================================================
#include <iostream> // for cin, cout objects declaration.
using namespace std;// for their definition.

//###########################################################################//
class Queue
{
private:
	int head;
	int tail;
	int length;
	enum{LIM = 10};
	int items[LIM];
	
public:
	Queue() : head(-1), tail(-1), length(0) {}
	
	// add an item.
	void enQueue(int val)
	{
		if(isEmpty())     // no items yet.
		{
			head++; tail++;
			items[tail] = val;
			length++;
		}
		else if(isFull()) // no space.
			cout << "Overflow.\n";
		else              // there is a room.
		{
			tail = (tail+1) % LIM;
			items[tail] = val;
			length++;
		}
	}
	
	
	// remove an item.
	int deQueue()
	{
		if(isEmpty())
			cout << "Underflow. ";
		else
		{
			int i = head;
			head = (head+1)%LIM;
			
			length--;
			// reset the indexes.
			if(length == 0) head = tail = -1;
			
			return items[i];
		}
		
		return -1;
	}
	
	// the array state.
	bool isEmpty() const { return length == 0; }
	bool isFull()  const { return length == LIM;}
	
	// display the array's content.
	void display() const
	{
		int i = head;
		int rounds = length;
		
		while(rounds--)
		{
			cout << items[i] << ", ";
			i = (i+1)%LIM;
		}
		
		cout << "\n";
	}
};
//###########################################################################//

int main()
{
	Queue qu1;
	char ans;
	bool keep = true;
	
	while(keep)
	{
		cout << "Enter:\n   1.add\n   2.remove\n   3.display: ";
		cin >> ans;
		
		switch(ans)
		{
		case '1':
			int x;
			cout << "\n   Enter the value: ";
			cin >> x;
			qu1.enQueue(x);
			break;
			
		case '2':
			cout << qu1.deQueue() << "\n";
			break;
			
		case '3':
			cout << "\n\n";
			qu1.display();
			break;
			
		default:
			cout << "Ivalid operation.\n";
			keep = false;			
		}
		
		cout << "\n\n";
	}
	
	// indicates a successful execution.
	return 0;	
}



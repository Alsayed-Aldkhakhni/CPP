//============================================================================
// Name        : Queue.cpp
// Date        : June 18, 2024
// Author      : Alsayed_Ali_Aldkhakhni
// Copyright   : Nothing to be mentioned.
// Description : Simulate queue data structure based on dynamic array.
//============================================================================

// preprocessor directive, instructs the preprocessor, a part of the compiler,
//  to substitute the content of this header file, iostream,
//  to the current source file.
#include <iostream> // for using 'cin' and 'cout' objects.
using namespace std;// contains the definition of how those object operate.

// generic class handles any primitive type.
template <class T>
class Queue // class specifier.
{
private:    // data members.
	int front;
	int rear;
	T* arr;
	int size;
	int length;

public: // member functions.

	// inner class exception handler.
	class Exception
	{
	public:
		Exception(const char* msg) { cout << "\n" << msg << "\n"; }
	};

	// 1-argument ctor.
	Queue(int sz) : front(-1), rear(-1), length(0)
	{
		if(sz <= 0)
			throw Exception("Invalid size.");

		size = sz;
		arr = new T[size];
	}

	// inserting an item.
	void enQueue(T val)
	{
		if(isFull())
			throw Exception("Overflow");
		else
		{
			length++;

			if(isEmpty())
			{
				front++; rear++;
				arr[front] = val;
			}
			else
			{
				rear = (rear + 1) % size;
				arr[rear] = val;
			}
		}
	}

	// removing an item.
	void deQueue()
	{

		if(isEmpty()) { throw Exception("Underflow."); }

		cout << arr[front] << " is dequeued.\n\n";
		front = (front + 1) % size;

		length--;
		if(length == 0) front = rear = -1;
	}

	// display the queue's data.
	void display()
	{
		// check first.
		if(isEmpty()) { throw Exception("Queue's empty."); }

		int i = front;
		int rounds = length;

		cout <<	"----------------------------------------------\n";
		while(rounds > 0)
		{
			cout << "|   " << arr[i] << "   ";
			i = (i+1) % size;
			rounds--;
		}
		cout << "|\n----------------------------------------------\n\n";
	}

	// some accessors to retrieve the data indirectly to keep its privacy.
	T getFront()   { return arr[front];}
	T getRear()    { return arr[rear];}
	int getLength(){ return length; }

	// the indexes of the front and rear.
	int frontAt() { return front;}
	int rearAt()  { return rear;}

	// the queue's state.
	bool isFull() {	return length == size;}
	bool isEmpty(){ return front == -1; }

	// return a copy of the front.
	T peek() { return getFront(); }

	// release the memory dedicated for this class.
	~Queue() { delete[] arr; }
};




int main()
{
	try{
		// instantiate an object of Queue class.
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
		// 0     1  2  3  4    <---- indexes.
		queue1.enQueue(16);
		//queue1.enQueue(17); // overflow.

		// display the queue's content.
		queue1.display(); // 12 13 14 15 16

		queue1.deQueue(); // 12 is gone.
		queue1.deQueue(); // 13 is gone.

		queue1.display(); // 14 15 16 17
	}
	catch(const Queue<int>::Exception&)
	{}


	// indicates a successful execution.
	return 0;
}














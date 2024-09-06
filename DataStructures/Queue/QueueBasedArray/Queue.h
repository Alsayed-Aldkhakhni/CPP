//============================================================================
// Name        : Queue.cpp
// Date        : June 18, 2024
// Author      : Alsayed A. Aldkhakhni
// Copyright   : Feel free to use.
// Description : Construct our homemade queue data structure based on array.
//============================================================================

// preprocessor directive:
// contains some predefined objects and operators to be used easily.
#include <iostream> // contains the declaration of cin, cout objects.
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






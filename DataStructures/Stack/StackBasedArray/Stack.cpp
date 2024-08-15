//============================================================================
// Name        : Stack.cpp
// Date        : June 16, 2024
// Author      : Alsayed_Ali_Aldkhakhni
// Copyright   : Nothing to be mentioned yet. 
// Description : Construct stack data structure based on array.
//============================================================================

#include <iostream>  // the declaration of 'cin' and 'cout'.
using namespace std; // their definition.

// template class that handles any data type.
template <class T>
class Stack // class specifier.
{
private:    // data members.
	int TOP;
	int size; // the capacity of the stack.
	T *list;  // stack body.

public: // function members.

	// inner class exception handler.
	class Exception
	{
	public:
		Exception(const char* msg) { cout << "\n" << msg << "\n"; }
	};

	// 1-argument constructor.
	Stack(int sz) : TOP(-1), size(0), list(NULL)
	{
		// validate the size.
		if(sz <= 0)
			throw Exception("Invalid size for Stack.");

		size = sz;
		list = new T[size];
	}

	// add an item to the stack.
	void push(T val)
	{
		// validate the index.
		if(TOP == size - 1)
			throw Exception("Overflow.");

		list[++TOP] = val;
	}

	// remove an item from the stack.
	T pop()
	{
		if(isEmpty())
			throw Exception("Underflow.");

		return list[TOP--];
	}

	// check whether the stack has data.
	bool isEmpty() { return TOP == -1;}

	// return the element on the top.
	T peek() { return isEmpty() ? throw Exception("Stack is empty") : list[TOP]; }

	// return the index of the first element.
	int getTOP() { return TOP; }

	// display the data on the stack.
	void display()
	{
		for(int i = TOP; i >= 0; i--)
		{
			cout << "\n---------\n";
			cout << "|   " << list[i] << "   |";

			if(i == TOP)
				cout << "   <---- TOP.";
		}

		cout << "\n---------\n\n";
	}

	// release the memory dedicated to the stack.
	~Stack() { delete[] list; }
};

int main()
{
	int size;

	try{
		cout << "Enter stack size: ";
		cin >> size;

		// instantiate an object that handles characters.
		Stack<char>charStack(size);

		// pushing some items.
		charStack.push('A');
		charStack.push('B');
		charStack.push('C');
		charStack.push('D');
		charStack.push('E');

		charStack.push('F');
		charStack.push('G');
		charStack.push('H');
		charStack.push('I');
		charStack.push('J');

		// display them.
		charStack.display();

		// popping some of them.
		charStack.pop(); // J
		charStack.pop(); // I
		charStack.pop(); // H

		charStack.pop(); // G
		charStack.pop(); // F
		charStack.pop(); // E

		// display the rest.
		charStack.display();
	}
	catch(const Stack<char>::Exception&)
	{}

	// indicates a successful execution
	// that function main has been popped off 
	// the the system stack.
	return 0;
}









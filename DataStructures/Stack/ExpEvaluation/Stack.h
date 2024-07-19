//============================================================================
// Name        : Stack.h 
// Date        : June 17, 2024
// Author      : Alsayed-Aldkhakhni
// Version     : V1.0
// Copyright   : Nothing to be mentioned.
// Description : Stack data structure implementation.
//============================================================================

#include <iostream> // for objects 'cin' and 'cout' declaration.
using namespace std;// for their definition.
//#########################################################################################//
template <class T>
class Stack  // class specifier.
{
private:
	int TOP;
	int size;// the capacity of the stack.
	T *list; // stack body.

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

	// check whether the stack has data or not.
	bool isEmpty() { return TOP == -1;}

	// return the element on the top.
	T peek() { return isEmpty() ? throw Exception("Stack is empty") : list[TOP];}

	// return the index of the first element.
	int getTOP() { return TOP; }

	// release the memory dedicated to the stack.
	~Stack() { delete[] list;}
};
//#########################################################################################//

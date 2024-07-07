//============================================================================
// Name        : BalancedParentheses.cpp
// Date        : June 17, 2024
// Author      : Alsayed-Aldkhakhni
// Version     : V1.0
// Copyright   : Nothing to be mentioned.
// Description : Check whether an entered expression is balanced.
//============================================================================

// preprocessor directive, instructs the preprocessor, a part of the compiler,
// to pre-fetch the content of this header file, io-stream,
// to the current source file since we need it for using 'c in' and 'c out' objects.
#include <iostream>
using namespace std; // contains the definition of how those object operate.

//**************************************************************************
// template class that handles any data type.
template <class T>
class Stack // class specifier.
{
private: // data members.
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

	// check whether the stack has data or not.
	bool isEmpty() { return TOP == -1;}

	// return the element on the top.
	T peek() { return isEmpty() ? throw Exception("Stack is empty") : list[TOP]; }

	// return the index of the first element.
	int getTOP() { return TOP; }

	// release the memory dedicated to the stack.
	~Stack() { delete[] list; }
};
//**************************************************************************

// function's prototype.
bool isBalanced(string);

int main()
{
	// declare the variable to hold the expression.
	string exp;

	// read it.
	cout << "Enter an expression: "; cin >> exp;

	// call the method 'isBalanced()' to determine whether it is balanced.
	cout << (isBalanced(exp) ? "It's balanced." : "It's not balanced.") << "\n";

	// indicate successful execution.
	return 0;
}

// check the entered expression.
bool isBalanced(string exp)
{
	// stack to hold the parentheses.
	Stack<char> stack1(exp.length() / 2);

	// private function to check parentheses' compatibility.
	bool arePaired(char open, char close);

	// traverse on the whole expression searching for the parentheses.
	for(int i = 0; i < int(exp.length()); i++)
	{
		// if the current character is an open brace, push it.
		if(exp.at(i) == '[' || exp.at(i) == '{' || exp.at(i) == '(')
			stack1.push(exp.at(i));
		else if(exp.at(i) == ']' || exp.at(i) == '}' || exp.at(i) == ')')
		{
			// if there are extra parentheses which have no opening ones.
			if(stack1.isEmpty() || !arePaired(stack1.peek(), exp.at(i)))
				return false;

			else // if so far so good.
				stack1.pop();
		}
	}

	// the answer of the question.
	return stack1.isEmpty();
}

// check if the compared parentheses are compatible.
bool arePaired(char open, char close)
{
	return (open == '[' && close == ']') || (open == '{' && close == '}') || (open == '(' && close == ')');
}

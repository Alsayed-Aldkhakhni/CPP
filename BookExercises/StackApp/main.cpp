/*
 * Subject: A program that simulates the stack in computer memory.
 *
 * Date: December 30, 2023
 *
 * Author: Alsayed Aldkhakhni
 */


#include <iostream>							// for the declaration of cin, cout.
#include <iomanip>							// for the declaration of setw.
using namespace std;						// the definition of cin, cout and setw.

class Stack									// class definition, tag.
{
											// 3 functions friends to the class.
friend void PUSH(Stack &, int);				// to push, add, a value on the stack.
friend void POP(Stack &);					// to pop, remove, a value from the stack.
friend void print(Stack &);					// to print the stack.

private:									// data members. 'private' to save it from accident modification.
	static const int SIZE = 10; 			// size of the stack.
	int list[SIZE];							// the stack.
	int TOS;								// "Top Of Stack" used to operate on the stack.
	
public:										// 'public' to allow the user to act with the stack and its data members.
	Stack()									// default constructor to initialize the stack with zeros.
	{
		for(int ite = 0; ite <= 9; ite++) list[ite] = 0;
		TOS = SIZE; 						// out of the stack.
	}
};

//***************************************************************

void PUSH(Stack &st, int val)				// the definition of the friend functions.
{
	if(st.TOS >= 0 && st.TOS <= 10)			// check the range of the stack.
	{
		st.TOS -= 1;
		st.list[st.TOS] = val;

		cout << "added to 'TOS'.\n";
	}
	else
	{
		cout << "Stack out of range.\n";
	}
}

void POP(Stack &st)
{
	if(st.TOS >= 0 && st.TOS <= 9)
	{
		st.list[st.TOS++] = 0;
		cout << "removed 'TOS'.\n";
	}
	else
	{
		cout << "Stack is empty.\n";
	}
}

void print(Stack & st)
{
	for(int ite = 0; ite <= 9; ite++)
	{
		cout << ite << "    |" << setw(6) << st.list[ite] << setw(6) << "|\n"
					 << "     ----------\n";
	}
}

//***************************************************************

int main()
{											// declare needed variables.
	Stack s1;								// take an object of type 'Stack'.				
	char ans, action;
	int val;
	
	do
	{										// prompt message tells the user what's going on.
		cout << "Press '+' to add an item,\n'-' to remove it,\n'#' to print the stack: ";
		cin >> action;						// take his action.
		
		switch(action)						// acting depending on his input.
		{
			case '+':						// in case he wants to push a value on the stack.
				cout << "Enter the values: ";
				cin >> val;					// get the value from him.
				PUSH(s1,val);				// add it to the 's1'
				break;
				
			case '-':						// in case he wants to remove.
				POP(s1);					// remove the value at 'TOS'.
				break;
				
			case '#':						// show the content of the stack, 's1'.
				cout << "\n\n";
				print(s1);					// call the responsable function to print.
				break;
			
			default:						// unknown input.
				cout << "Invalid input.\n";
				break;
		}
		
		cout << "One more time? (y, n): ";	// another action?
		cin >> ans;							// get the answer.
		
	} while(ans == 'y');					// loop if he wants.						
	
	
	return 0;								// flag the 'OS' that the program executed successfully.
}
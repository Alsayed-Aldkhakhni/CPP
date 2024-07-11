//============================================================================
// Name        : source.cpp
// Date        : July 11, 2024
// Author      : Alsayed-Aldkhakhni
// Version     : V1.0
// Copyright   : Nothing to be mentioned.
// Description : Reverse a C-string.
//============================================================================

#include <iostream> // for cin, cout objects declaration.
#include <cstring>  // for strlen.
using namespace std;// for cin, cout definition.

// function's prototype.
void reverse(char str[]);

int main()
{
	// define the array.
	char str[100];
	
	// prompt the user to enter a c-string.
	cout << "Enter a string: ";
	cin.get(str, 100);
	
	// print before and after reversing.
	cout << "Before: " << str << "\n";
	reverse(str);
	cout << "After:  " << str << "\n";
	
	// indicates a successful execution.
	return 0;
}

// function's body.
void reverse(char str[])
{
	short len = strlen(str);
	char swap;
	
	for(int i = 0, j = len - 1; i < len/2; i++, j--)
	{
		swap   = str[i];
		str[i] = str[j];
		str[j] = swap;
	}
}
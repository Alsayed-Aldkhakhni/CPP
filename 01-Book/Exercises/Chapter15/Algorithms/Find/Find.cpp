//============================================================================
// Name        : Find.cpp
// Date        : July 15, 2024
// Author      : Alsayed-Aldkhakhni
// Copyright   : Nothing to be mentioned.
// Description : Test 'find()' algorithm.
//============================================================================
#include <iostream>  // for cin, cout objects declaration.
#include <algorithm> // for find().
using namespace std; // the definition of cin, cout.

template <class T>
void display(T*, int);

int main()
{
	// 1st array.
	int intArr[] = {11, 15, 10, 55, 60, 19, 60, 17, 12};
	int intSZ = sizeof(intArr) / sizeof(intArr[1]);

	display(intArr, intSZ);

	// read the target from the user.
	int iTarget;
	cout << "Enter a number to search for: ";
	cin >> iTarget;
	int* iPos = find(intArr, intArr+intSZ, iTarget);

	// check the target existence.
	if(iPos == intArr+intSZ)
		cout << iTarget << " doesn't exist in this array of items.\n";
	else
		cout << iTarget << " found at offset: " << iPos - intArr << "\n";

	cout << "\n\n**************************************************\n\n";

	// 2nd array.
	char charArr[] = {'A', 'G', 'F', 'm', 'H', 'B', 'E', 'x', 'R'};
	int charSZ = sizeof(charArr) / sizeof(charArr[1]);

	display(charArr, charSZ);

	// read the target from the user.
	char cTarget;
	cout << "Enter a character to search for: ";
	cin >> cTarget;
	char* cPos = find(charArr, charArr+charSZ, cTarget);

	// check the target existence.
	if(cPos == charArr+charSZ)
		cout << cTarget << " doesn't exist in this array of items.\n";
	else
		cout << cTarget << " found at offset: " << cPos - charArr << "\n";

	// indicates a successful execution.
	return 0;
}

// function's body.
template <class T>
void display(T* arr, int size)
{
	cout << "\n=================================================================================\n";
	for(int i = 0; i < size; i++)
		cout << "   " << arr[i] << "   |";
	cout << "\n=================================================================================\n";
}


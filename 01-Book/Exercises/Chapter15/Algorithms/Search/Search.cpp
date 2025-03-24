//============================================================================
// Name        : Search.cpp
// Date        : July 15, 2024
// Author      : Alsayed-Aldkhakhni
// Copyright   : Nothing to be mentioned.
// Description : Test 'search()' algorithm.
//============================================================================
#include <iostream>  // for cin, cout objects declaration.
#include <algorithm> // for count().
using namespace std; // the definition of cin, cout.

// template function, to display any array of items.
template <class T>
void display(T*, int);

int main()
{
	// 1st array.
	int iArr[] = {10, 15, 10, 55, 10, 19, 10, 17, 10};
	int iPattern[] = {10, 19, 10};

	int iSZ = sizeof(iArr) / sizeof(iArr[1]);
	int ipSZ = sizeof(iPattern) / sizeof(iPattern[1]);

	cout << "Source: ";
	display(iArr,  iSZ); // display the bigger one.

	cout << "\nPattern: ";
	display(iPattern, ipSZ); // display the pattern.

	int* iStartMatch = search(iArr, iArr+iSZ, iPattern, iPattern+ipSZ);

	// index of matching.
	if(iStartMatch == iArr+iSZ)
		cout << "The pattern doesn't match any sequence of numbers.\n";
	else
		cout << "Matching starts at offset: " << iStartMatch - iArr << ".\n";

	cout << "\n\n**************************************************\n\n";

	// 2nd array.
	char cArr[] = {'h', 'G', 'H', 'A', 'L', 'I', 'E', 'H', 'R'};
	char cPattern[] = {'A', 'L', 'I'};

	int cSZ = sizeof(cArr) / sizeof(cArr[1]);
	int cpSZ = sizeof(cPattern) / sizeof(cPattern[0]);

	cout << "Source: ";
	display(cArr, cSZ);

	cout << "\nPattern: ";
	display(cPattern, cpSZ);

	char* cStartMatch = search(cArr, cArr+cSZ, cPattern, cPattern+cpSZ);

	// index of matching.
	if(cStartMatch == cArr+cSZ)
		cout << "The pattern doesn't match any sequence of characters.\n";
	else
		cout << "Matching starts at offset: " << cStartMatch - cArr << ".\n";

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

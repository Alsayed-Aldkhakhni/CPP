//============================================================================
// Name        : Count.cpp
// Date        : July 15, 2024
// Author      : Alsayed-Aldkhakhni
// Copyright   : Nothing to be mentioned.
// Description : Test 'count()' algorithm.
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
	int intArr[] = {10, 15, 10, 55, 10, 19, 10, 17, 10};
	int intSZ = sizeof(intArr) / sizeof(intArr[1]);

	display(intArr, intSZ);

	// read the target from the user.
	int iTarget;
	cout << "Enter a number to count # of appearance: ";
	cin >> iTarget;
	int iCount = count(intArr, intArr+intSZ, iTarget);

	// number of appearance.
	cout << iTarget << " found " << iCount << " time(s).\n";

	cout << "\n\n**************************************************\n\n";

	// 2nd array.
	char charArr[] = {'h', 'G', 'H', 'm', 'H', 'B', 'E', 'H', 'R'};
	int charSZ = sizeof(charArr) / sizeof(charArr[1]);

	display(charArr, charSZ);

	// read the target from the user.
	char cTarget;
	cout << "Enter a character to search for: ";
	cin >> cTarget;
	int cCount = count(charArr, charArr+charSZ, cTarget);

	// number of appearance.
	cout << cTarget << " found " << cCount << " time(s).\n";

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


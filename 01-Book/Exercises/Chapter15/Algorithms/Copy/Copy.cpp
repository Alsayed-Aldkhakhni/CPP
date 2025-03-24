//============================================================================
// Name        : Copy.cpp
// Date        : July 15, 2024
// Author      : Alsayed-Aldkhakhni
// Copyright   : Nothing to be mentioned.
// Description : Test 'copy()' algorithm.
//============================================================================

#include <iostream> // for objects cin, cout declaration.
#include <algorithm>// for algorithm 'copy()'.
using namespace std;// the definition of cin, cout.

// template function's prototype.
template <class T>
void display(T*, int);

int main()
{
	int iSrc[] = {15, 17, 5, 8, 99, 16, 12, 7, 31};
	int iSZ = sizeof(iSrc) / sizeof(iSrc[1]);

	int iDest[iSZ/2];

	cout << "source: ";
	display(iSrc, iSZ);

	// copy the half of items in iSrc to iDest.
	copy(iSrc, iSrc+(iSZ/2), iDest) ;

	cout << "\n"
			"destination: ";
	display(iDest, iSZ/2);

	return 0;
}

// function's body.
template <class T>
void display(T* arr, int size)
{
	cout << "\n==============================================================================\n";
	for(int i = 0; i < size; i++)
		cout << "   " << arr[i] << "   |";
	cout << "\n==============================================================================\n";
}

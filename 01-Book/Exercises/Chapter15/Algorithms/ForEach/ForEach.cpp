//============================================================================
// Name        : ForEach.cpp
// Date        : July 15, 2024
// Author      : Alsayed-Aldkhakhni
// Copyright   : Nothing to be mentioned.
// Description : Test 'for_each()' algorithm.
//============================================================================

#include <iostream> // for objects cin, cout declaration.
#include <algorithm>// for algorithm 'for_each()'.
using namespace std;// the definition of cin, cout.

// template function's prototype.
template <class T>
void display(T*, int);

void centimize(float);
int main()
{
	float fInches[] = {7.5, 3.25, 8.36, 2.88, 9.66, 4.12, 8.19};
	int fSZ = sizeof(fInches) / sizeof(fInches[1]);

	cout << "Inches: ";
	display(fInches, fSZ);

	cout << "\nCentimeters: \n\n";

	// convert each value of these inches to centimeters.
	// hint: for_each() algorithm just takes a copy, it doesn't modify the value itself.
	for_each(fInches, fInches+fSZ, centimize);

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

void centimize(float in)
{
	cout << "  " << in*2.54 << "  |";
}

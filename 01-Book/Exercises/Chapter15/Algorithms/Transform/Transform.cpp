//============================================================================
// Name        : Transform.cpp
// Date        : July 15, 2024
// Author      : Alsayed-Aldkhakhni
// Copyright   : Nothing to be mentioned.
// Description : Test 'transform()' algorithm.
//============================================================================

#include <iostream> // for objects cin, cout declaration.
#include <algorithm>// for algorithm 'for_each()'.
using namespace std;// the definition of cin, cout.

// template function's prototype.
template <class T>
void display(T*, int);
int mod2(int);
char capitalize(char);

int main()
{
	int iNums[] = {15, 17, 5, 8, 99, 16, 12, 7, 31};
	int iSZ = sizeof(iNums) / sizeof(iNums[1]);

	cout << "Numbers: ";
	display(iNums, iSZ);

	// set each number with it reminder on 2.
	// hint: transform() algorithm takes a copy of the value and changes the old one with the new.
	transform(iNums, iNums+iSZ, iNums, mod2);

	cout << "Converted: ";
	display(iNums, iSZ);

	cout << "\n\n***************************************************\n\n";

	char cLetters[] = {'A', 'X', 'Z', 'b', 'r', 'm', 'h', 'n', 'M', 'O'};
	int cSz = sizeof(cLetters) / sizeof(cLetters[1]);

	cout << "Letters.: ";
	display(cLetters, cSz);

	// make any lower-case letter to upper.
	transform(cLetters, cLetters+cSz, cLetters, capitalize);

	cout << "Converted: ";
	display(cLetters, cSz);

	return 0;
}

int mod2(int num) { return num % 2; }
char capitalize(char ch) { return islower(ch) ? toupper(ch) : ch; }

// function's body.
template <class T>
void display(T* arr, int size)
{
	cout << "\n=================================================================================\n";
	for(int i = 0; i < size; i++)
		cout << "   " << arr[i] << "   |";
	cout << "\n=================================================================================\n";
}



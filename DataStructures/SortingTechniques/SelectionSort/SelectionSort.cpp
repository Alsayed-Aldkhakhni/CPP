//============================================================================
// Name        : SelectionSort.cpp
// Date        : June 22, 2024
// Author      : Alsayed-Aldkhakhni
// Copyright   : Nothing to be mentioned.
// Description : Selection sort technique implementation.
// Complexity  : Time: O(n^2), Space: O(1) since it is an in-place technique.
//============================================================================

#include <iostream> // for cin, cout objects declaration.
using namespace std;// for their definition.
const short LIM = 10;

// functions' prototype.
template<class Type>
void selectionSort(Type*, int);

template<class Type>
void display(Type*, int);

template<class Type>
void Swap(Type&, Type&);

int main()
{
	int intArr[LIM] = {13, -10, 12, -100, 150, 110, 55, -210, 7, 8};
	char charArr[LIM] = {'x', 'A', 'C', 'm', 'R', 'n', 'j', 'W', 'u', 'P'};

	// array of integers.
	cout << "Before: "; display(intArr, LIM);
	selectionSort(intArr, LIM);
	cout << "\nAfter: "; display(intArr, LIM);

	cout << "\n\n******************************\n\n";

	// array of characters.
	cout << "Before: "; display(charArr, LIM);
	selectionSort(charArr, LIM);
	cout << "\nAfter: "; display(charArr, LIM);

	// indicates a successful execution.
	return 0;
}

// functions' definition.
template<class Type>
void selectionSort(Type* arr, int size)
{
	int temp;
	int min;

	for(int i = 0; i < size-1; i++)
	{
		min = i;

		// find the minimum item's index.
		for(int j = i+1; j < size; j++)
			if(arr[j] < arr[min]) min = j;

		// swap.
		Swap(arr[i], arr[min]);
	}
}

template<class Type>
void Swap(Type& x, Type& y)
{
	Type z = x;
	x = y;
	y = z;
}

template<class Type>
void display(Type* arr, int)
{
	cout << "\n============================================================================\n|";
	for(int j = 0; j < LIM; j++)
		cout << "  " << arr[j] << "  |";
	cout << "\n============================================================================\n";

}

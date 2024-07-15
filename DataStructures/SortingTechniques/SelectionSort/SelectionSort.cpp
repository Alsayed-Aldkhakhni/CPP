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

// functions' prototype.
template<class Type>
void selectionSort(Type*, int);

template<class Type>
void display(Type*, int);

template<class Type>
void Swap(Type&, Type&);

int main()
{
	int intArr[] = {13, -10, 12, -100, 150, 110, 55, -210, 7, 8};
	char charArr[] = {'x', 'A', 'C', 'm', 'R', 'n', 'j', 'W', 'u', 'P'};

	// dynamic calculation to the size of the arrays.
	int intSize = sizeof(intArr) / sizeof(intArr[1]);
	int charSize = sizeof(charArr)/ sizeof(charArr[1]);

	// array of integers.
	cout << "Before:  "; display(intArr, intSize);
	selectionSort(intArr, intSize);
	cout << "\nAfter: "; display(intArr, intSize);

	cout << "\n\n******************************\n\n";

	// array of characters.
	cout << "Before: "; display(charArr, charSize);
	selectionSort(charArr, charSize);
	cout << "\nAfter: "; display(charArr, charSize);

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
void display(Type* arr, int size)
{
	cout << "\n============================================================================\n|";
	for(int j = 0; j < size; j++)
		cout << "  " << arr[j] << "  |";
	cout << "\n============================================================================\n";

}

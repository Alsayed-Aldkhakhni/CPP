//============================================================================
// Name        : InsertionSort.cpp
// Date        : June 22, 2024
// Author      : Alsayed-Aldkhakhni
// Copyright   : Nothing to be mentioned.
// Description : Insertion sort technique implementation.
// Complexity  : Time: O(n^2), Space: O(1) since it is an in-place technique.
//============================================================================

#include <iostream> // for cin, cout objects declaration.
using namespace std;// for their definition.

// functions' prototype.
template<class Type>
void InsertionSort(Type*, int);

template<class Type>
void display(Type*, int);

int main()
{
	int intArr[] = {13, -10, 12, -100, 150, 110, 55, -210, 7, 8};
	char charArr[] = {'x', 'A', 'C', 'm', 'R', 'n', 'j', 'W', 'u', 'P'};

	// dynamic calculation to the size of the arrays.
	int intSize = sizeof(intArr) / sizeof(intArr[1]);
	int charSize = sizeof(charArr)/ sizeof(charArr[1]);

	// array of integers.
	cout << "Before:  "; display(intArr, intSize);
	InsertionSort(intArr, intSize);
	cout << "\nAfter: "; display(intArr, intSize);

	cout << "\n\n******************************\n\n";

	// array of characters.
	cout << "Before: "; display(charArr, charSize);
	InsertionSort(charArr, charSize);
	cout << "\nAfter: "; display(charArr, charSize);

	// indicates a successful execution.
	return 0;
}

// functions' definition.
template<class Type>
void InsertionSort(Type* arr, int len)
{
	int key, j;
	for(int i = 1; i < len; i++)    // find the current item to be sorted.
	{
		key = arr[i];
		j = i - 1;

		while(j >= 0 && arr[j] > key)// shifting part.
		{
			arr[j+1] = arr[j];
			j = j-1;
		}

		arr[j+1] = key;
	}
}

template<class Type>
void display(Type* arr, int size)
{
	cout << "\n============================================================================\n|";
	for(int j = 0; j < size; j++)
		cout << "  " << arr[j] << "  |";
	cout << "\n============================================================================\n";

}

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

// the sort method.
template<class T>
void sort(T* arr, int len)
{
	int key, j;
	for(int i = 1; i < len; i++)
	{
		key = arr[i];
		j = i - 1;

		// shifting part.
		while(j >= 0 && arr[j] > key)
		{
			arr[j+1] = arr[j];
			j = j-1;
		}

		arr[j+1] = key;
	}
}

// display the array.
template<class T>
void display(T* arr, int size)
{
	cout << "\n\n|";
	for(int j = 0; j < size; j++)
		cout << "  " << arr[j] << "  |";
	cout << "\n\n";
}



int main()
{
	int intArr[] = {13, -10, 12, -100, 150};
	char charArr[] = {'x', 'A', 'C', 'm', 'R'};

	// dynamic calculation to the size of the arrays.
	int intSize = sizeof(intArr) / sizeof(intArr[1]);
	int charSize = sizeof(charArr)/ sizeof(charArr[1]);

	// array of integers.
	cout << "Before:  "; display(intArr, intSize);
	sort(intArr, intSize);
	cout << "\nAfter: "; display(intArr, intSize);

	cout << "\n\n";

	// array of characters.
	cout << "Before: "; display(charArr, charSize);
	sort(charArr, charSize);
	cout << "\nAfter: "; display(charArr, charSize);

	// indicates a successful execution.
	return 0;
}





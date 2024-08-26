//============================================================================
// Name        : SelectionSort.cpp
// Date        : June 22, 2024
// Author      : Alsayed-Aldkhakhni
// Copyright   : Nothing to be mentioned.
// Description : Selection sort technique implementation.
// Complexity  : Time: O(n^2); Space: O(1) since it is an in-place technique.
//============================================================================

#include <iostream> // for cin, cout objects declaration.
using namespace std;// for their definition.

// swap x and y.
template<class T>
void Swap(T& x, T& y)
{
	T z = x;
	x = y;
	y = z;
}

// sort 'arr' in selection sort technique.
template<class T>
void sort(T* arr, int size)
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

// display arr.
template<class T>
void display(T* arr, int size)
{
	cout << "\n|";
	for(int j = 0; j < size; j++)
		cout << "  " << arr[j] << "  |";
	cout << "\n";

}

int main()
{
	int intArr[] =   {13, -10, 12, -100, 150};
	char charArr[] = {'x', 'A', 'C', 'm', 'R'};

	// dynamic calculation to the size of the arrays.
	int intSize = sizeof(intArr) / sizeof(intArr[1]);
	int charSize = sizeof(charArr)/ sizeof(charArr[1]);

	// array of integers.
	cout << "Before:  "; display(intArr, intSize);
	sort(intArr, intSize);
	cout << "\nAfter: "; display(intArr, intSize);

	cout << "******************************\n";

	// array of characters.
	cout << "Before: "; display(charArr, charSize);
	sort(charArr, charSize);
	cout << "\nAfter: "; display(charArr, charSize);

	// indicates a successful execution.
	return 0;
}







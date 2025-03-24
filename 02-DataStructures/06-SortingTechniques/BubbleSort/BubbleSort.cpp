//============================================================================
// Name        : BubbleSort.cpp
// Date        : June 22, 2024
// Author      : Alsayed-Aldkhakhni
// Copyright   : Nothing to be mentioned.
// Description : Bubble sort technique implementation.
// Complexity  : Time: O(n^2), Space: O(1) since it is an in-place technique.
//============================================================================

#include <iostream> // for cin, cout objects declaration.
using namespace std;// for their definition.

// swap the values of x, y.
template<class Type>
void Swap(Type& x, Type& y)
{
	Type z = x;
	x = y;
	y = z;
}

// bubble sort function.
template<class Type>
void sort(Type arr[], int len)
{
	// step on each index in the array.
	for(int i = 0; i < len; i++)
	{
		// comparing the current item with the rest.
		for(int j = 0; j < len-i-1; j++)
		{
			// Swapping the adjacent elements.
			if(arr[j]  > arr[j+1])
				Swap(arr[j], arr[j+1]);
		}
	}
}

// display the arr.
template<class Type>
void display(Type* arr, int size)
{
	cout << "\n|";
	for(int j = 0; j < size; j++)
		cout << "  " << arr[j] << "  |";
	cout << "\n";

}


int main()
{
	int intArr[] =   {13, -10, 12, -10, 15};
	char charArr[] = {'x', 'A', 'C', 'm', 'P'};

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






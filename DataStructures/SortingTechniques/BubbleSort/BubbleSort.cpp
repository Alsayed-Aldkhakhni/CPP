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
const short LIM = 10;

// functions' prototype.
template<class Type>
void bubbleSort(Type*, int);

template<class Type>
void display(Type*, int);

template<class Type>
void Swap(Type&, Type&);

int main()
{
	int intArr[LIM] = {13, -10, 12, -10, 15, 11, 55, -21, 7, 8};
	char charArr[LIM] = {'x', 'A', 'C', 'm', 'R', 'n', 'j', 'W', 'u', 'P'};

	// array of integers.
	cout << "Before: "; display(intArr, LIM);
	bubbleSort(intArr, LIM);
	cout << "\nAfter: "; display(intArr, LIM);

	cout << "\n\n******************************\n\n";

	// array of characters.
	cout << "Before: "; display(charArr, LIM);
	bubbleSort(charArr, LIM);
	cout << "\nAfter: "; display(charArr, LIM);

	// indicates a successful execution.
	return 0;
}

// functions' definition.
template<class Type>
void bubbleSort(Type arr[], int len)
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
	cout << "\n========================================================================\n|";
	for(int j = 0; j < LIM; j++)
		cout << "  " << arr[j] << "  |";
	cout << "\n========================================================================\n";

}

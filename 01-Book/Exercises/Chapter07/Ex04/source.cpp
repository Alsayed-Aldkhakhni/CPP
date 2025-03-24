//============================================================================
// Name        : source.cpp
// Date        : July 11, 2024
// Author      : Alsayed-Aldkhakhni
// Version     : V1.0
// Copyright   : Nothing to be mentioned.
// Description : Find the maximum value in an array.
//============================================================================

#include <iostream> // for cin, cout objects declaration.
#include <string>   // to use the 'string' class, data type.
using namespace std;// for cin, cout definition.

// function's prototype.
int findMax(int [], int);

int main()
{
	// fill an array with items.
	int iList[] = {10, 50, 88, -100, 135, 123588, 555, 9999};
	int size = sizeof(iList) / sizeof(iList[0]);
	
	// pass it to the function.
	int max = findMax(iList, size);
	cout << "The maximum value in this array is: " << iList[max] << ", at index: " << max << "\n";
	
	// indicates a successful execution
	return 0;
}

// function's body.
int findMax(int list[], int size)
{
	int max = 0;
	for(int i = 1; i < size; i++)
	{
		if(list[max] < list[i])
			max = i;
	}
	
	return max;
}
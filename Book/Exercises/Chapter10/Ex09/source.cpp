/*
 * Subject: Fill an array of arrays of integers.
 *
 * Date: July 22, 2024
 *
 * Author: Alsayed-Aldkhakhni
 *
 * Last modification: July 22, 2024
 *
 * */

#include <iostream> // for the declaration of cin, cout objects.
using namespace std;// for their definition.

// functions' declarators.
void fillArr(int**, int);
void display(int** iArrPtr, int size);

int main()
{
	const int SIZE = 10;
	int* iArrPtr[SIZE];

	// allocate the sub-arrays.
	for(int i = 0; i < SIZE; i++)
		*(iArrPtr+i) = new int[SIZE];

	fillArr(iArrPtr, SIZE);
	display(iArrPtr, SIZE);

	// indicates a successful execution, popping off the stack.
	return 0;
}

// functions' definitions.
void fillArr(int** iArrPtr, int size)
{
	int x = 0;
	for(int i = 0; i < size; i++)
	{
		for(int j = 0; j < size; j++)
		{
			// if you want it to read the items from the user.
			//cout << "   Enter item [" << i << "][" << j << "]: ";
			//cin >> iArrPtr[i][j];
		
			iArrPtr[i][j] = x*10;
			x++;
		}
	}
}


void display(int** iArrPtr, int size)
{
	for(int i = 0; i < size; i++)
	{
		for(int j = 0; j < size; j++)
		{
			cout << "   Item [" << i << "][" << j << "]: ";
			cout << iArrPtr[i][j];
			cout << "\n";
		}

		cout << "==============================\n";
	}
}

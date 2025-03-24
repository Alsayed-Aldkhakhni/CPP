/*
 * Subject: Binary search technique implementation.
 * 
 * Complexity: Time: [ Best-> O(1), Wrost&Average-> O(log n) ]. Space: O(1).
 *
 * Date: July 28, 2024
 *
 * Author: Alsayed-Aldkhakhni
 *
 * Last modification: July 28, 2024
 *
 * */

#include <iostream> // for the declaration of cin, cout.
using namespace std;// for the definition  of them.

// functions' prototypes.
int binarySearch(int*, int, int, int);
void display(int*, int);

int main()
{
	// array must be sorted to fit with binary search.
	int items[] = {2, 5, 20, 40, 50, 60, 80, 100, 110, 113, 200, 700};
	int size = sizeof(items) / sizeof(items[1]);
	
	display(items, size);

	int key;
	cout << "Enter an integer to search for: ";
	cin >> key;

	int x = binarySearch(items, 0, size-1, key);

	if(x != -1)
		cout << "Found at index: (" << x << ").\n";
	else
		cout << "Not found in this range.\n";

	// indicates a successful execution.
	return 0;
}

// function's definition.
int binarySearch(int* items, int low, int high, int key)
{
	if(high < low) // base case. 
		return -1;
	else
	{
		int m = (low+high)/2;
	
		if(items[m] == key)    // if the key is in the middle of the array.
			return m;
		else if(key > items[m])// if it in the right side of the sub-array. 
			return binarySearch(items, m+1, high, key);
		else                   // if it in the left  side of the sub-array.
			return binarySearch(items, low, m-1, key);
	}
}

void display(int* items, int size)
{
	cout << "\n========================================================================\n";
	for(int i = 0; i < size; i++)
		cout << *(items+i) << ",  ";
	cout << "\n========================================================================\n";
}

/*
 * Subject: Linear search technique implementation.
 * 
 * Complexity: Time: [ Best-> O(1), Wrost&Average-> O(n) ]. Space: O(1).
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
int linearSearch(int*, int, int);
void display(int*, int);

int main()
{
	int items[] = {12, 5, 20, 10, 13, -45, 2, 7, 69, 21, 35, 1};
	int size = sizeof(items) / sizeof(items[1]);
	
	display(items, size);

	int key;
	cout << "Enter an integer to search for: ";
	cin >> key;

	int x = linearSearch(items, size, key);
	if(x != -1)
		cout << "Found at index: (" << x << ").\n";
	else
		cout << "Not found in this range.\n";

	return 0;
}

// function's definition.
int linearSearch(int* items, int size, int key)
{
	for(int i = 0; i < size; i++)
	{
		if(*(items+i) == key)
			return i;
	}

	return -1;
}

void display(int* items, int size)
{
	cout << "\n========================================================================\n";
	for(int i = 0; i < size; i++)
		cout << *(items+i) << ",  ";
	cout << "\n========================================================================\n";
}

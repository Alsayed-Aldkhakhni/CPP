/*
 * Subject: Read float items and average them.
 *
 * Date: July 21, 2024
 *
 * Author: Alsayed-Aldkhakhni
 *
 * Last modification: July 21, 2024
 **/

#include <iostream> // for the declaration of cin, cout objects.
using namespace std;// for their definition.

// functions' prototype.
void readItems(float*, int);
double average(float*, int);

int main()
{
	const int SIZE = 10;
	float arr[SIZE];

	// invoke the reading method.
	readItems(arr, SIZE);
	cout << "\nAverage: " << average(arr, SIZE) << "\n\n";

	// indicates a successful execution, poping off the stack.
	return 0;
}

// functions' definition.
void readItems(float* iArr, int size)
{
	for(int i = 0; i < size; i++)
	{
		cout << "Enter item #" << i+1 << ": ";
		cin >> *(iArr+i);
	}
}

double average(float* iArr, int size)
{
	double sum = 0;
	for(int i = 0; i < size; i++)
		sum += *(iArr+i);

	return (sum / double(size));
}

/*
 * Subject: Sort an array of floats.
 *
 * Date: July 29, 2024
 *
 * Author: Alsayed-Aldkhakhni
 *
 * Last modification: July 29, 2024
 *
 * */

#include <iostream>  // for the declaration of cin, cout.
#include <algorithm> // for sort algorithm.
#include <functional>// for specifing the ordering.
using namespace std; // for the definition of cin, cout.

// functions' prototypes.
void display(float*,   int);
void readItems(float*, int);

int main()
{
	int x;
	cout << "How many items?: ";
	cin >> x;
	if(x <= 0) exit(1);

	float arrPtr[x];
	
	readItems(arrPtr, x);
	display(arrPtr, x);

	// those are the same.
	//sort(arrPtr, arrPtr+x); // default is acendening.
	//sort(arrPtr, arrPtr+x, less<float>());

	sort(arrPtr, arrPtr+x, greater<float>());
	display(arrPtr, x);

	// indicates a successful execution.
	return 0;
}


// functions' definitions.
void display(float* ptr, int SZ)
{
	cout << "\n==========================================================\n";
	for(int i = 0; i < SZ; i++) cout << *(ptr+i) << ",  ";
	cout << "\n==========================================================\n";
}

void readItems(float* ptr, int SZ)
{
	for(int i = 0; i < SZ; i++)
	{
		cout << "    Enter item #"<<i+1<<": ";
		cin >> *(ptr+i);
	}
}





/*
 * Subject: Merge two pointers to arryas of type float.
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

// functions' prototype.
void readItems(float*, int);
void display(float*, int);
void merge(float*, float*, float*, int);


int main()
{
	const int SIZE = 5;
	float fArr1[SIZE];
	float fArr2[SIZE];
	float fArr3[SIZE*2];

	readItems(fArr1, SIZE);
	cout << "===============\n";
	readItems(fArr2, SIZE);

	merge(fArr1, fArr2, fArr3, SIZE);

	display(fArr1, SIZE);
	display(fArr2, SIZE);
	display(fArr3, SIZE*2);

	return 0;
}


// functions' definition.
void display(float* fArr, int size)
{
	for(int i = 0; i < size; i++)
		cout << *(fArr+i) << ", ";
	cout << "\n\n";
}

void readItems(float* fArr, int size)
{
	for(int i = 0; i < size; i++)
	{
		cout << "Enter the item #" << i+1 << ": ";
		cin >> *(fArr+i);
	}
}

void merge(float* src1, float* src2, float* dest, int size)
{
	int i;
	for(i = 0; i < size; i++)
		*(dest+i) = *(src1+i);

	for(int j = 0; j < size; i++, j++)
		*(dest+i) = *(src2+j);
}

/*
 * Subject: Make our own Array data structure.
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
//#########################################################################//
class Array
{
private:
	enum{SZ = 10};
	int* iArrsPtr[SZ];
	int size, rows;
public:
	// 50
	Array(int sz)
	{
		if(sz <= 0 || sz/10 > SZ)
		{
			cout << "Invalid size.\n";
			exit(1);
		}

		size = sz;

		// 50
		rows = size / 10;// 50/10= 5, 0->4, sub-arrays.
		for(int k = 0; k < rows; k++)
			*(iArrsPtr+k) = new int[10];
	}

	int& operator[](int k)
	{	
		if(k >= size || k < 0)
		{
			cout << k << " is an invalid index.\n";
			exit(1);
		}
		
		// k = 10,[1,0]
		// k = 5, [0,5]
		// k = 0, [,]		
		int j = k % 10;
		k = k / 10;
		int i = k % 10;
		
		return iArrsPtr[i][j];
	}

	~Array() { for(int i = 0; i < rows; i++){ delete[] iArrsPtr[i];} }
};

int main()
{
	int size = 100;
	Array arr1(size);

	// fill the array.
	for(int i = 0; i < size; i++)
		arr1[i] = i;

	// will cause a program termination.
	//arr1[size] = 100;

	for(int i = 0; i < size; i++)
	{
		if(i%10==0) cout << "\n";
		if(arr1[i] < 10) cout << "0";
		cout << arr1[i] << ", ";
	}

	cout << "\n\n";

	// indicates a successful execution, popping off the stack.
	return 0;
}

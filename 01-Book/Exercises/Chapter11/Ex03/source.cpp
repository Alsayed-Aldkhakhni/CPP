/*
 * Subject: Make our own Array data storage.
 *
 * Date: July 23, 2024
 *
 * Author: Alsayed-Aldkhakhni
 *
 * Last modification: July 23, 2024
 *
 * */

#include <iostream> // for the declaration of cin, cout objects.
using namespace std;// for their definition.

//#########################################################################//
class Array
{
private:
	int* ptr;
	int size;

public:
	// one-arg ctor.
	Array(int sz)
	{
		if(sz <= 0)
		{
			cout << "Invalid size.\n";
			exit(1);
		}

		size = sz;
		ptr = new int[size];
	}

	// default copy ctor.
	// X(X&)
	Array(Array& arr1)
	{
		if(this == &arr1)
		{
			cout << "Objects are the same.\n";
			return;
		}

		size = arr1.size;

		delete[] ptr;
		ptr = new int[size];

		for(int i = 0; i < size; i++)
			*(ptr+i) = *(arr1.ptr+i);
	}

	// subscript,[], operator.
	int& operator[](int i)
	{
		if(i < 0 || i >= size)
		{
			cout << i << " is an invalid index.\n";
			exit(1);
		}

		return *(ptr+i);
	}

	// assignment operator.
	void operator=(Array& arr1)
	{
		if(this == &arr1)
		{
			cout << "Objects are the same.\n";
			return;
		}
		
		size = arr1.size;

		delete[] ptr;
		ptr = new int[size];

		for(int i = 0; i < size; i++)
			*(ptr+i) = *(arr1.ptr+i);
	}

	// release the memory dedicated to the current object.
	~Array() { delete[] ptr; }
};
//#########################################################################//

int main()
{
	Array arr1(10);
	Array arr2(1);

	for(int i = 0; i < 10; i++)
		arr1[i] = i*2;
	
	cout << "============================================\n";
	
	cout << "Arr1: ";
	for(int i = 0; i < 10; i++)
		cout << arr1[i] << "  ";
	
	cout << "\n============================================\n";

	arr2 = arr1;

	cout << "Arr2: ";
	for(int i = 0; i < 10; i++)
		cout << arr2[i] << "  ";

	cout << "\n============================================\n";

	Array arr3(arr2);

	cout << "Arr3: ";
	for(int i = 0; i < 10; i++)
		cout << arr3[i] << "  ";

	cout << "\n============================================\n";
	
	// invlaid assignment.
	arr2 = arr2;

	return 0;
}


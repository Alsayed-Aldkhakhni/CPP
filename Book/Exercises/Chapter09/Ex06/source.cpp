/*
 * Subject: Inherit an array that enables the user to specifiy the bounds from one checks the bounds.
 *
 * Date: July 20, 2024
 *
 * Author: Alsayed-Aldkhakhni
 *
 * Last modification: July 20, 2024
 **/

#include <iostream> // for the declaration of cin, cout objects.
using namespace std;// for their definition.

//####################################################################//
class SafeArray
{
protected:
 	enum {SZ = 100};
	int iArr[SZ];

public:
	SafeArray() {}

	int& operator[](int i)
	{
		if(i < 0 || i >= SZ)
		{
			cout << i << " Invalid index.\n";
			exit(1);
		}

		return iArr[i];
	}
};
//####################################################################//
class Array : public SafeArray
{
private:
	int upperB, lowerB;

public:
	// 100 200
	Array(int low, int up)
	{
		if(low > up || low < 0 || up - low > SZ)
		{
			cout << "Invalid bounds.\n";
			exit(1);
		}

		lowerB = low; // 100
		upperB = up;  // 200
	}

	int& operator[](int i)
	{
		if(i < lowerB || i >= upperB)
		{
			cout << i << " exceeded the specifiyed bounds.\n";
			exit(1);
		}

		return	SafeArray::operator[](i%SZ);
	}
};
//####################################################################//


int main()
{
	// instantiate and specifiy the bounds.
	Array Array1(100, 200);

	// fill the array.
	for(int i = 100; i < 200; i++)
		Array1[i] = i;

	// Array1[200] = 200; // will cause program termination.

	// display the content.
	for(int i = 100; i < 200; i++)
	{
		if(i % 10 == 0) cout << '\n';
		cout << Array1[i] << "   ";
	}

	cout << '\n';

	return 0;
}

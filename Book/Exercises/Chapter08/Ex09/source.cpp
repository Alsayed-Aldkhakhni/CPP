/*
 * Subject: SafeArray that enables the user to specifiy the bounds.
 *
 * Date: July 17, 2024
 *
 * Author: Alsayed-Aldkhakhni
 *
 * Last modification: July 17, 2024
 * 
 * */

#include <iostream>
using namespace std;

//########################################################################//
class SafeArray
{
private:
	enum{SZ = 100};
	int items[SZ];
	int uBound, lBound;
	
public:
	// 100 175
	SafeArray(int lowerBound, int upperBound)
	{
		if(lowerBound >= 0 && upperBound - lowerBound <= SZ)
		{
			uBound = upperBound % SZ;
			lBound = lowerBound % SZ;
		}
		else
		{
			cout << "Invalid bounds.\n";
			exit(1);
		}
	}
	
	// subscript operator, '[]'.
	int& operator[](int i)
	{
		if((i-SZ) < lBound || (i-SZ) >= uBound)
		{
			cout << i << " is invalid index.\n";
			exit(1);
		}
		
		return items[i-SZ];
	}
};
//########################################################################//

int main()
{
	// instantiate an object of type SafeArray
	// and specifiy the bounds.
	SafeArray array1(100, 190);
	
	// fill the array.
	for(int i = 100; i < 190; i++)
		array1[i] = i;
	
	// read the items.
	for(int i = 100; i < 190; i++)
	{
		if(i%10 == 0)
			cout << "\n";
		
		cout << array1[i] << "   ";
	}
	
	cout << "\n\n";
	
	// will cause program termination.
	// array1[190] = 190;
	
	// indicates a successful execution,
	// causing the function to be poped off the stack.
	return 0;
}

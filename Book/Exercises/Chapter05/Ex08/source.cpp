/*
 * Subject: Implement the swap function.
 * 
 * Date: January 1, 2024
 * 
 * Author: Alsayed-Aldkhakhni
 * 
 * Last modification: July 8, 2024
 * 
 * */

#include <iostream> // for objects cin, cout declaration.
using namespace std;// for their definition.

// function's prototype.
void swap(int&, int&);

int main()
{
	int int1, int2;
	
	// read the numbers.
	cout << "Enter two numbers: ";
	cin >> int1 >> int2;
	
	// before swapping.
	cout << "Before:\n"
		 << "int1 = " << int1 << "   int2 = " << int2 << '\n';
	
	// swap the values.
	swap(int1, int2);
	
	
	// after swapping.
	cout << "After:\n"
		 << "int1 = " << int1 << "   int2 = " << int2 << '\n';
	
	// indicates a successful execution.
	return 0;
}

// function's definition.
void swap(int& x, int& y)
{
	int z = x;
	x = y;
	y = z;
}
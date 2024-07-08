/*
 * Subject: A function that sets the smaller of 2 numbers with 0.
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
inline void setSmaller0(int&, int&);

int main()
{
	// read the numbers.
	int x, y;
	cout << "Enter two numbers: "; 
	cin >> x >> y;
	
	// before changing.
	cout << "Before:\n"
		 << "x = " << x << "   y = " << y << "\n\n";
	
	// changing.
	setSmaller0(x, y);
	
	// after changing.
	cout << "After:\n"
		 << "x = " << x << "   y = " << y << "\n\n";

	return 0;
}

// function definition.
inline void setSmaller0(int& x, int& y)
{
	if(x < y)
		x = 0;
	else if(y < x)
		y = 0;
}


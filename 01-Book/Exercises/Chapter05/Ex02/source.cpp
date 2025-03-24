/*
 * Subject: A power function to get the value of x^y.
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
inline double power(double, int = 2);

int main()
{
	// test the function.
	for(int i = 1; i <= 10; i++)
		cout << "2^" << i << "  =  " << power(2, i) << "\n";
	
	// indicates a successful execution.
	return 0;
}

// function's definition, body.
double power(double base, int expon)
{
	// take a copy to not change.
	double x  = base;
	for(int i = 1; i < expon; i++) base *= x;
	
	return base;
}
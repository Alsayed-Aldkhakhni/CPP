/*
 * Subject: Add two fractions.
 * 
 * Date: December 1, 2023
 * 
 * Author: Alsayed-Aldkhakhni
 * 
 * Last modification: July 6, 2024
 */

#include <iostream> // for cin, cout objects declaration.
using namespace std;// for the definition of cin, cout.

int main()
{
	int x, y;
	char dummy;
	
	// prompt for the 1st fraction.
	cout << "Enter 1st fraction(x/y): ";
	cin >> x >> dummy >> y;

	// for the second.
	int a, b;
	cout << "Enter 2nd fraction(a/b): ";
	cin >> a >> dummy >> b;
	
	// print the result.
	cout << "The sum is: " << (x*b + y*a) << '/' << (y*b) << "\n";
	
	// indicates a successful execution.
	return 0;
}
/*
 * Subject: Convert temprature from Celsius to Fahrenheit.
 * 
 * Date: December 1, 2023
 * 
 * Author: Alsayed-Aldkhakhni
 * 
 * Last modification: July 6, 2024
 */

#include <iostream> // for cin, cout objects declaration.
using namespace std;// for their definition.

int main()
{
	// read the temprature in celsius.
	double c;
	cout << "Enter the temprature in Celsius: ";
	cin >> c;
	
	// conversion.
	double f = c * 9/5 + 32;
	cout << "Is eqivalent to: " << f << " in Fahrenheit.\n";
	
	// indicates a successful execution.
	return 0;
}
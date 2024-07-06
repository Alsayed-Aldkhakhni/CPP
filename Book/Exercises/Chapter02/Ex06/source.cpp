/*
 * Subject: Exchange an amount of dollars to other monetary units on a certain day.
 * 
 * Date: December 2, 2023
 * 
 * Author: Alsayed-Aldkhakhni
 * 
 * Last modification: July 6, 2024
 */

#include <iostream> // for cin, cout objects declaration.
using namespace std;// for their definition.

int main()
{
	// read the amount in dollars.
	double dollars;
	cout << "Enter an amount of dollars: ";
	cin >> dollars;
	
	// print the other amounts.
	cout << "The dollars is:          $"       << dollars << '\n';
	cout << "Those in Pounds is:      \u00A3" << dollars / 1.487 << '\n';
	cout << "Those in Yen is:         \u00A5" << dollars / 0.00955 << '\n';
	cout << "Those in German mark is: DM"     << dollars / 0.584 << '\n';
	cout << "Those in Franc is:       \u20A3" << dollars / 0.172<< '\n';
	
	
	// indicates a successful execution.
	return 0;
}

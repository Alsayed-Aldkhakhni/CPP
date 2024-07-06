/*
 * Subject: Convert from old British monetary notation to the new.
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
	int pounds, shillings, pence;
	
	// read pounds.
	cout << "Enter pounds: ";
	cin >> pounds;
	
	// shillings.
	cout << "Enter shillings: ";
	cin >> shillings;
	
	// pence.
	cout << "Enter pence: ";
	cin >> pence;
	
	// convert.
	cout << "The old notation, \u00A3" << pounds << '.' << shillings << '.' << pence 
		 << " is in the new: \u00A3" << pounds + shillings / 20.0 + pence / 240.0 << ".\n";
	
	// indicates a successful execution.
	return 0;
}
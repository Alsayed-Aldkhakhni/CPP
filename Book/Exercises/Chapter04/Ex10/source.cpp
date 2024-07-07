/*
 * Subject: Simulate old British monetary system using structure.
 * 
 * Date: December 1, 2023
 * 
 * Author: Alsayed-Aldkhakhni
 * 
 * Last modification: July 6, 2024
 */

#include <iostream> // for cin, cout objects declaration.
using namespace std;// for the definition of cin, cout.

//////////////////////////////////////
struct Sterling
{
	int pounds;
	int shillings;
	int pence;
};
//////////////////////////////////////


int main()
{
	// an object to store the old amount.
	Sterling str1;
	
	// to read the amount in the new system.
	double newNotation;
	
	// read the amount.
	cout << "Enter an amount of pounds in the new notation: ";
	cin >> newNotation;
	
	// validate the amount.
	if(newNotation <= 0)
	{
		cout << "Invalid amount of money.\n";
		exit(1);
	}
	
	// converting from new notation to the old notation.
	str1.pounds    = static_cast<int>(newNotation); // the pounds.
	str1.shillings = static_cast<int>( (newNotation - str1.pounds) * 20); // the shillings.
	str1.pence     = static_cast<int>( ((newNotation - str1.pounds) * 20 - str1.shillings ) * 12); // the pence.
	
	// display the amounts.
	cout << "You entered:      \u00A3" << newNotation << "\n"
		 << "In old notation:  \u00A3" << str1.pounds << '.' << str1.shillings << '.' << str1.pence << ".\n\n";

	// indicates a successful execution.
	return 0;
}
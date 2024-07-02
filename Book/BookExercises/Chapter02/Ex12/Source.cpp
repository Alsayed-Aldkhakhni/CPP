/*
 * Subject: Convert an amount in the new British monetary system to the old one.
 *
 * Date: April 9, 2024
 *
 * Author: Alsayed Aldkhakhni
 *
 * Last modification: May 16, 2024
 */

// Preprocessor directive instruct preprocessor 
//  to substitute them with their content into this file.
#include <iostream>	// cin, cout declaration.
using namespace std;// contains the defination of 'cin', 'cout' objects.

int main()
{
	// to hold the amount of money entered by the user.
	double amount;
	
	// prompt the user what this program does.
	cout << "A program converts money from new British system to the old.\n\n";
	
	// prompt the user what to do.
	cout << "Enter an amount of money: ";
    cin >> amount; // read his input.
    
    // pounds are the same in the two systems.
    int pound = static_cast<int>(amount);
    
	// extract the fractional part, shillingss and pence.
    amount = amount - pound;
    
	// get the shillingss.
    int shillings = static_cast<int>(amount * 20);
    
	// get the pence.
    int pence = static_cast<int>(((amount * 20) - (shillings)) * 12);
    
    // print the result.
    cout << "In old form is: \x9c" << pound << '.' << shillings << '.' << pence << ".\n";
    
	//  flag the 'OS' that the program executed successfully.
    return 0;
}

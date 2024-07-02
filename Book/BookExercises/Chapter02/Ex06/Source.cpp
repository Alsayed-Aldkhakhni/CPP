/*
 * Subject: Convert an amount of dollars to four equivalent monetary systems [Mark, Yen, Pound, Franc] at a certain day.
 *
 * Date:October 11, 2023
 *
 * Written by: Alsayed Aldkhakhni.
 *
 * Last modification: May 16, 2024
 */

#include<iostream>	// declaration of 'cin' and 'cout'.
using namespace std;// definition of cin, cout.

int main()
{
	// To hold the amount entered by the user.
	float dollarsAmount = 0.0;

	// Asking the user to insert amount of dollars.
	cout << "Enter the dollars: ";
	
	// Get that amount.
	cin >> dollarsAmount;

	// amount of dollars converted to those units[Pound,Franc,Mark,Yen].
	cout << "That amount, \'$" << dollarsAmount << "\'," << " is equivalent to:\n"
		 << dollarsAmount / 1.487F << " Pound,\n" << dollarsAmount /  0.172F << " Franc,\n" 
		 << dollarsAmount / 0.584F << " Mark,\n"  << dollarsAmount / 0.00955F << " Yen.\n";
											

	// Flag the 'OS' that the program is done.
	return 0;
}
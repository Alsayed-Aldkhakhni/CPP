/*
 * Subject: Convert from old monetary notation of the British Empire to the new one.
 *
 * Date: October 12, 2023
 *
 * Written by: Alsayed Aldkhakhni.
 *
 * Last modification: May 16, 2024
 */


#include<iostream>	// header file contains the declaration of 'cin' and 'cout'.
using namespace std;// contains the defintion of this specific versions 'cin' and 'cout'.

int main()
{
	// Initialize these identifiers to hold the data of the program.
	float Pounds = 0.0, Shillings = 0.0, Pence = 0.0, ConvertedAmount = 0.0;

	// Asking the user to input Pounds.
	cout << "Enter Pounds: ";
	cin >> Pounds; // Get pounds.

	// Asking him to input the shillings.
	cout << "Enter Shillings: ";
	cin >> Shillings; // Get that shillings.

	// And here to input the pence.
	cout << "Enter Pence: ";
	cin >> Pence; // Get that pence.

	// This formula is to convert form the old system to the new.
	ConvertedAmount = Pounds + Shillings / 20 + Pence / 240;

	// Final step to display the old amount and the new one.
	cout <<"Decimal pounds: \x9c" << ConvertedAmount << "\n";

	// flags the 'OS' that the program is done.
	return 0;
}

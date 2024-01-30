/*
 * Subject: A program  to convert the old monetary notation of the British Empire to the new notation.
 *
 * Date: October 12, 2023
 *
 * Written by: Alsayed Aldkhakhni.
 */


#include<iostream>						// 'iostream' is a header file contains the declaration of 'cin' and 'cout'.
using namespace std;					// 'std' is a namespace that contains the defintion of 'cin' and 'cout'.

int main()
{
										// Initialize these identifiers to hold the data of the program.
	float Pounds = 0.0, Shillings = 0.0, Pence = 0.0, ConvertedAmount = 0.0;

	cout << "Enter Pounds: ";			// Asking the user to input Pounds.
	cin >> Pounds;						// Get pounds.

	
	cout << "Enter Shillings: ";		// Asking him to input the shillings.
	cin >> Shillings;					// Get that shillings.

	cout << "Enter Pence: ";			// And here to input the .
	cin >> Pence;						// Get that pence.

										// This formula is to convert form the old system to the new one.
	ConvertedAmount = Pounds + Shillings / 20 + Pence / 240;

										// Final step to display the old amount and the new one.
	cout <<"Decimal pounds: \x9c" << ConvertedAmount << "\n";

	return 0;							// flags the 'OS' that the program is done.
}
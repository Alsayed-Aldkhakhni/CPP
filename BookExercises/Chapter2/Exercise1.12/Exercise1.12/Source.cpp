/*
 * Subject: convert decimal pounds to the old British monetary notation.
 *
 * Date: October 12, 2023
 *
 * Written by: Alsayed Aldkhakhni.
*/

#include<iostream>									// 'iostream' is a header file that contains the declaration of 'cin' and 'cout'.
using namespace std;								// namespace 'standard' is essential for 'cin' and 'cout' which contains their definition.

int main()
{					
	float decimalAmount = 0.0;						// To hold the amount entered by the user

	cout << "Enter decimal pounds: ";				// asking the user to enter decimal amount in the new British monetary system.
	cin >> decimalAmount;							// Get that amount.

	int  pounds = static_cast<int>(decimalAmount);  // pounds.
													// reset fraction converted to shillings.
	float fracShilling = (decimalAmount - pounds) * 20; 

	int shilling = static_cast<int>(fracShilling);  // the integer shillings 
													//		and the rest fraction is to pence.
	float fracPence = (fracShilling - shilling) * 12;

	int pence = static_cast<int>(fracPence);		// the final pence and the reset of the fraction is not necessary.

													// For the final step, I will print the old notation in the converted form.
	cout  << "\n\x9c" << pounds << '.' << shilling << '.' << pence << ".\n";

	return 0;										// indicates the 'OS' that the program executed successfully.
}
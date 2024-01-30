/*
 * Subject: This program is to convert an amount of dollars to four equivalent monetary units [Mark,Yen,Pound,Franc] at a certain day.
 *
 * Date: 10 / 11 / 2023...11th of October.
 *
 * Written by: Alsayed Aldkhakhni.
 */


#include<iostream>							// declaration of 'cin' and 'cout'.
using namespace std;						// definition of cin, cout.

int main()
{
	float DollarsAmount = 0.0;				// To hold the amount entered by the user.

	cout << "Enter the dollars: ";			// Asking the user to insert amount of dollars.
	cin >> DollarsAmount;					// Get that amount.


											// amount of dollars converted to those units[Pound,Franc,Mark,Yen].
	cout << "That amount \'" << DollarsAmount << " U.S.\'" << " is equivalent to:\n"
		 << DollarsAmount / 1.487F << " Pound,\n" << DollarsAmount /  0.172F << " Franc,\n" 
		 << DollarsAmount / 0.584F << " Mark,\n"  << DollarsAmount / 0.00955F << " Yen.";

	cout << "\n-----------------------";	// This line to make the output more clear.
											

	return 0;								// Flag the 'OS' that the program is done.
}
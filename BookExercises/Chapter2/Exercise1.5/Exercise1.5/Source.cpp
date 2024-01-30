/*
 * Subject: A program to check whether a user entered a lowercase character or an uppercase character.
 *
 * Date: 10 / 11 / 2023 ...11th of October.
 *
 * Written by: Alsayed Aldkhakhni.
 */


#include<iostream>						  // For the declaration of 'cin' and 'cout'.
#include<ctype.h>						  // For 'islower' function.
using namespace std; 

int main()								  // The entry point.
{
	char charIn = '\0';					  // To hold the char entered.

	cout << "Enter a random character: "; // Prompt message, inform the user what to do.
	cin >> charIn;						  // Get that character.

	cout << islower(charIn);			  // Print the result. 
	cout << "\n-------";				  // Print a line to make the output clear.

	return 0;							  // flag the 'OS' that the program is done.
}
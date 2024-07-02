/*
 * Subject: Check whether the user entered a lowercase character.
 *
 * Date: October 11, 2023
 *
 * Written by: Alsayed Aldkhakhni.
 *
 * Last modification: May 16, 2024
 */

// preprocessor directives.
#include<iostream>	// For the declaration of 'cin' and 'cout'.
#include<ctype.h>	// For 'islower' function.
using namespace std;// For the definition of cin, cout objects.

// The entry point.
int main()
{
	// To hold the char entered.
	char charIn = '\0';	
	
 	// Prompt message, inform the user what to do.
	cout << "Enter a random character: ";
	
	// Get that character.
	cin >> charIn;

	// Print the result. 
	cout << islower(charIn);
	
	// flag the 'OS' that the program is executed successfully.
	return 0;
}
/*
 * Subject: Check if the character is lower.
 * 
 * Date: December 2, 2023
 * 
 * Author: Alsayed-Aldkhakhni
 * 
 * Last modification: July 6, 2024
 */

#include <iostream> // for cin, cout objects declaration.
#include <string.h> // for islower library function.
using namespace std;// for the definition of cin, cout.

int main()
{
	// declare the variable to read the user's input.
	char ch;
	
	// prompt the user to enter the char.
	cout << "Enter a random character: ";
	cin >> ch;
	
	// pass it to the function and print its returned value.
	cout << islower(ch) << "\n";
	
	// indicates a successful execution.
	return 0;
}

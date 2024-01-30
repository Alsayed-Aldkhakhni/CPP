/*
 * Subject: A program to evaluate gallons of gas to cubic foot.

 * Date: 10 / 10 / 2023

 * Written by: Alsayed Ali.
 */

// preprocessor directive to fetch the whole content of that file 'iostream'.
#include<iostream>   					// This 'header file' contains the declaration of cin & cout.
using namespace std;				 	// This namespace 'std' contains the definition of cin & cout.

float  const CubicFoot = 7.481F;		// to convert from gallons to cubic foot.


int main()
{
	float gallons;						  // To hold the user's input.

	cout << "Enter the gallons of gas: "; // I am asking the user to insert the gallons.
	cin >> gallons;						  // Get the gallons of gas.


	cout << "In cubic foot: "			  // Print the result in cubic foot.
		 << gallons / CubicFoot;

	cout << "\n-------------------------------------------";

	return 0; 							// flags the calling program, operating system in this case,
			     						// that the program executed successfully.
}
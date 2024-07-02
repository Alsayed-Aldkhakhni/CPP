/*
 * Subject: Evaluate gallons of gas to cubic foot.
 *
 * Date: October 10, 2023
 *
 * Written by: Alsayed Ali.
 *
 * Last modification: May 16, 2024
 */

// preprocessor directive to fetch the whole content of that file 'iostream'.
#include<iostream>   // This 'header file' contains the declaration of cin & cout.
using namespace std; // This namespace 'std' contains the definition of cin & cout.
	
// to convert from gallons to cubic foot.
float  const CubicFoot = 7.481F;

int main()
{
	// To hold the user's input.
	double gallons;

	// I am asking the user to insert the gallons.
	cout << "Enter the gallons of gas: "; 
	
	// Get the gallons of gas.
	cin >> gallons;	

	// Print the result in cubic foot.
	cout << "In cubic foot: " << (gallons / CubicFoot) << "\n";

	// flags the calling program, operating system in this case,
	// 	that the program executed successfully.
	return 0; 
}

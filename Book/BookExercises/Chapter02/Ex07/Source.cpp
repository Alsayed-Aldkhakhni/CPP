/*
 * Subject: Convert the temperature in Celsius to Fahrenheit.
 *
 * Date: October 11, 2023
 *
 * Written by: Alsayed Aldkhakhni. 
 *
 * Last modification: May 16, 2024
 */

#include<iostream>	// the declaration of objects 'cin' and 'cout'.
using namespace std;// definition of cin, cout.
					
int main()
{

	// to hold the temperatures.
	float Fahrenheit = 0.0, Celsius = 0.0;

	// Asking the user to enter a temperature in Celsius.
	cout << "Enter the temperature in Celsius: ";
	
	// Get that temperature.
	cin >> Celsius;


	// This formula is to convert form Celsius to Fahrenheit.
	Fahrenheit = Celsius * 9 / 5 + 32;

	// Print the converted temperature.
	cout << Celsius << " is equivalent to " << Fahrenheit << " in Fahrenheit.\n";

	// Flag the 'OS' that the program is done. 'executed successfully.'
	return 0;
}

/*
 * Subject: A program to convert the temperature entered form the user in Celsius to Fahrenheit.
 *
 * Date: 10 / 11 / 2023.........11th of October.
 *
 * Written by: Alsayed Aldkhakhni. 
 */


#include<iostream>			// For using 'cin' and 'cout'.
using namespace std;		// definition of cin, cout.
					
int main()
{

	float Fahrenheit = 0.0, // holds the Fahrenheit temperature.
		  Celsius = 0.0;    // holds the Celsius temperature.


							// Asking the user to enter a temperature in Celsius.
	cout << "Enter the temperature in Celsius: ";
	cin >> Celsius;			// Get that temperature.


							// This formula is to convert form Celsius to Fahrenheit.
	Fahrenheit = Celsius * 9 / 5 + 32;

							// Print the converted temperature.
	cout << Celsius << " is equivalent to " << Fahrenheit << " in Fahrenheit.";

	
	cout << "\n\n";			// This line for clarity.

	return 0;				// Flag the 'OS' that the program is done. 'executed successfully.'
}
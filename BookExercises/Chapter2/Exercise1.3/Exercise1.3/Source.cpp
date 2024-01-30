/*
 * Subject: Testing the assignment operator and decrement. 
 *
 * Date: 10 / 11 / 2023
 *
 * Written by: Alsayed Ali
 */


#include<iostream> 				// This is a 'header file' contains the declaration of 'cin' and 'cout' objects.
using namespace std; 			// The definition of them , 'cin' and 'cout'.

int main()						// Starting point.
{
	int num = 10;				

	cout << num;				// Printing that value [10].
	cout << "\n======\n";		// Just a line to improve the clarity of the output.


	num += 10;					// Adding 10.

	cout << num;				// Print the new value [20].
	cout << "\n======\n";		// That line to enhance the output.

	cout << --num;				// Print the new value [19].
	cout << "\n======";			// Do you know what is that?

	return 0;					// flags the 'OS' that the program successfully executed.
}
/*
 * Subject: Testing some operators. 
 *
 * Date: October 11, 2023
 *
 * Written by: Alsayed Ali
 *
 * Last modification: May 16, 2024
 */


// preproccessor directive, instructs the preprocessor to fetch the content of this file.
#include<iostream> 	// This is a 'header file' contains the declaration of 'cin' and 'cout' objects.
using namespace std;// The definition of them , 'cin' and 'cout'.

// Starting point.
int main()
{
	// define a variable.
	int num = 10;				

	cout << num; // Printing that value [10].
	cout << "\n";// Just a line to improve the clarity of the output.


	num += 10;   // Adding 10.

	cout << num; // Print the new value [20].
	cout << "\n";// That line to enhance the output.

	cout << --num;// Print the new value [19].
	cout << "\n"; // Do you know what this is?

	// flags the 'OS' that the program successfully executed.
	return 0;
}
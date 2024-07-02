/*
 * Subject: Add two fractions.
 *
 * Date: October 12, 2023
 *
 * Written by: Alsayed Aldkhakhni.
 *
 * Last modification: May 16, 2024
 */

#include<iostream>	// for the declaration 'cin' & 'cout'.
using namespace std;// for the definition of 'cin' & 'cout', which version of the object does in this context.

int main()
{

	// declare neede variables to hold user's input.
	int num1, num2, dnum1, dnum2;

	// to hold the division sign.
	char dummyChar;
								 
	// prompt the user to input the first fraction.
	cout << "Enter the 1st fraction(x/y): ";
	
	// Get the first fraction.
	cin >> num1 >> dummyChar >> dnum1;

	// second fraction.
	cout << "Enter the 2nd fraction(x/y): ";
	
	// Get the second fraction.
	cin >> num2 >> dummyChar >> dnum2;

	// print the answer.
	// Notice: you don't need the '()' it's just for clarity.
	cout << "Sum = " << (num1 * dnum2) + (num2 * dnum1)	 << '/' << dnum1 * dnum2;				
	
								
	// print an empty line.
	cout << "\n";

	// Flag the 'OS' that the program is done.'successful execution'
	return 0;
}

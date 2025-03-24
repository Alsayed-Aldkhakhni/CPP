/*
 * Subject: Generate a multiplication table for fractions.
 *
 * Date: January 14, 2024
 *
 * Author: Alsayed-Aldkhakhni
 *
 * Last modification: July 11, 2024
 * 
 * */

#include <iostream>  // for the declaration of cin, cout objects.
#include "Fraction.h"// to use this user-defined type.
using namespace std; // for the definition of cin, cout.

int main()
{
	Fraction mul;
	
	// read the user's input.
	int denom;
	cout << "Enter a number: ";
	cin >> denom;
	
	// print the horizontal upper header.
	cout << "\t";
	for(int i = 1; i < denom; i++)
	{
		Fraction frac1(i, denom);
		
		frac1.getFraction();
		cout << "\t";
	}
	
	cout << "\n-----------------------------------------------\n";
	
	// print the vertical left header.
	for(int i = 1; i < denom; i++)
	{
		Fraction frac1(i, denom);
		frac1.getFraction();
		
		// print the content of each row.		
		cout << "\t";
		for(int j = 1; j < denom; j++)
		{
			Fraction frac2(j, denom);
			
			mul = frac1.mul(frac2);
			mul.getFraction();
			
			cout << "\t";
		}
		
		cout << '\n';
	}
	
	// indicates a successful execution.
	return 0;
}

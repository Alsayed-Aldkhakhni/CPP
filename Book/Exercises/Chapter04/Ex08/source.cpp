/*
 * Subject: Add two fractions represented by structures.
 * 
 * Date: December 1, 2023
 * 
 * Author: Alsayed-Aldkhakhni
 * 
 * Last modification: July 6, 2024
 */

#include <iostream> // for cin, cout objects declaration.
using namespace std;// for the definition of cin, cout.

/////////////////////////////
struct Fraction
{
	int numerator;
	int denominator;
};
/////////////////////////////


int main()
{
	// instantiate 3 objects of type Fraction.
	Fraction frac1, frac2, sum;
	char dummyChar; // division sign.
	
	// read the first fraction.
	cout << "Enter a fraction[x/y]: ";
	cin >> frac1.numerator >> dummyChar >> frac1.denominator;
	
	if(frac1.denominator == 0)
	{
		cerr << "Division by zero is not allowed.\n";
		exit(1);
	}
	
	// read the second fraction.
	cout << "Enter a fraction[x/y]: ";
	cin >> frac2.numerator >> dummyChar >> frac2.denominator;
	
	if(frac2.denominator == 0)
	{
		cerr << "Division by zero is not allowed.\n";
		exit(1);
	}
	
	// add the fractions together.
	sum.numerator   = frac1.numerator * frac2.denominator + frac2.numerator * frac1.denominator;
	sum.denominator = frac1.denominator * frac2.denominator;
	
	// display them.
	cout << frac1.numerator << '/' << frac1.denominator << " + " 
		 << frac2.numerator << '/' << frac2.denominator << " = "
		 << sum.numerator << '/' << sum.denominator << "\n";

	// indicates a successful execution.
	return 0;
}

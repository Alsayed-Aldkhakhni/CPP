/*
 * Subject: Four-function calculator for fractions using struct.
 * 
 * Date: December 5, 2024
 * 
 * Author: Alsayed-Aldkhakhni
 * 
 * Last modification: July 6, 2024
 */	
		
#include <iostream> // the declaration of objects cin, cout.
using namespace std;// their definition.

//////////////////////////////
struct Fraction // sruct tag.
{
	int numerator;
	int denominator;
};
//////////////////////////////

int main()
{
	Fraction frac1, frac2;
	char operation, dummy;
	
	// read the fractions.
	cout << "Enter fraction, operator and fraction: ";
	cin >> frac1.numerator >> dummy >> frac1.denominator
		>> operation
	    >> frac2.numerator >> dummy >> frac2.denominator;
	
	// invalid fractions.
	if(frac1.denominator == 0 || frac2.denominator == 0)
	{
		cout << "Division by zero is undefined.\n";
		exit(1);
	}

	
	Fraction sum, diff, mul, div;
	
	// print the operands.
	cout << frac1.numerator << '/' << frac1.denominator << " " << operation << " " 
		 << frac2.numerator << '/' << frac2.denominator << " = ";
	
	// carry out the operation based on the value of operation.
	switch(operation)
	{
	case '+':
		sum.numerator   =  (frac1.numerator   * frac2.denominator) + (frac1.denominator * frac2.numerator);
		sum.denominator =  (frac2.denominator * frac1.denominator);
		cout << sum.numerator << '/' << sum.denominator << "\n";
		break;
		
	case '-':
		diff.numerator   =  (frac1.numerator * frac2.denominator) - (frac1.denominator * frac2.numerator);
		diff.denominator =  (frac2.denominator * frac1.denominator);
		cout << diff.numerator << '/' << diff.denominator << "\n";
		break;
	
	case '*':
		mul.numerator   =  (frac1.numerator   * frac2.numerator);
		mul.denominator =  (frac2.denominator * frac1.denominator);
		cout << mul.numerator << '/' << mul.denominator << "\n";
		break;
	
	case '/':
		div.numerator   =  (frac1.numerator   * frac2.denominator);
		div.denominator =  (frac1.denominator * frac2.numerator);
		cout << div.numerator << '/' << div.denominator << "\n";
		break;
	
	default:
		cout << "Invalid operator.\n";
	}
	
	// indicates a successful execution.
	return 0;
}
		
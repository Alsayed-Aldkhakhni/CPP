/*
 * Subject: Four-function calculator struct and functions to handle the operations.
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

// functions' prototypes.
Fraction add(Fraction&, Fraction&);
Fraction sub(Fraction&, Fraction&);
Fraction mul(Fraction&, Fraction&);
Fraction div(Fraction&, Fraction&);
void display(Fraction);

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
	
	// print the operands.
	cout << frac1.numerator << '/' << frac1.denominator << " " << operation << " " 
		 << frac2.numerator << '/' << frac2.denominator << " = ";
	
	// carry out the operation based on the value of operation.
	switch(operation)
	{
	case '+':
		display(add(frac1, frac2));
		break;
		
	case '-':
		display(sub(frac1, frac2));
		break;
	
	case '*':
		display(mul(frac1, frac2));
		break;
	
	case '/':
		display(div(frac1, frac2));
		break;
	
	default:
		cout << "Invalid operator.\n";
	}
	
	// indicates a successful execution.
	return 0;
}

// functions' definitions.
Fraction add(Fraction& frac1, Fraction& frac2)
{
	Fraction temp;
	
	temp.numerator   =  (frac1.numerator   * frac2.denominator) + (frac1.denominator * frac2.numerator);
	temp.denominator =  (frac2.denominator * frac1.denominator);

	return temp;
}

Fraction sub(Fraction& frac1, Fraction& frac2)
{
	Fraction temp;
	
	temp.numerator   =  (frac1.numerator * frac2.denominator) - (frac1.denominator * frac2.numerator);
	temp.denominator =  (frac2.denominator * frac1.denominator);

	return temp;
}

Fraction mul(Fraction& frac1, Fraction& frac2)
{
	Fraction temp;
	
	temp.numerator   =  (frac1.numerator   * frac2.numerator);
	temp.denominator =  (frac2.denominator * frac1.denominator);

	return temp;
}

Fraction div(Fraction& frac1, Fraction& frac2)
{
	Fraction temp;

	temp.numerator   =  (frac1.numerator   * frac2.denominator);
	temp.denominator =  (frac1.denominator * frac2.numerator);
	
	return temp;
}

void display(Fraction frac)
{
	cout << frac.numerator << '/' << frac.denominator << "\n";
}
		
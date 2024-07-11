/*
 * Subject: define our own data type that simulates fractions.
 *
 * Date: January 14, 2024
 *
 * Author: Alsayed-Aldkhakhni
 *
 * Last modification: July 11, 2024
 * 
 * */

#include <iostream> // for the declaration of cin, cout objects.
using namespace std;// for the definition of cin, cout.
//#########################################################################//
class Fraction      // class definition.
{
private:
	int numerator;
	int denominator;
	void lowTerms();
	
public:
	// ctor.
	Fraction(int num = 0, int denom = 1) : numerator(num)
	{
		if(denom == 0)
		{
			cout << "Division by zero is illegal.\n";
			exit(1);			
		}
		
		denominator = denom;
	}
	
	// read the fraction from the user.
	void setFraction()
	{
		int x, y; char dummy;
		cout << "Enter a fraction as (x/y): ";
		cin >> x >> dummy >> y;
		
		if(y == 0)
		{
			cout << "Division by zero is illegal.\n";
			exit(1);
		}
		
		numerator = x;
		denominator = y;
	}
	
	// display the fraction.
	void getFraction()
	{
		lowTerms(); // simplify before displaying.
		cout << numerator << '/' << denominator << " = " (numerator / float(denominator)) << '\n';
	}
	
	// addition.
	void add(Fraction& frac)
	{
		int num   = numerator * frac.denominator + denominator * frac.numerator;
		int denom = denominator * frac.denominator;

		numerator = num;
		denominator = denom;
	}
	
	Fraction avg(int divisor) const
	{
		return Fraction(numerator, denominator * divisor);
	}
};

void Fraction::lowTerms()
{
	// take copies to divide by later.
	int num   = numerator;
	int denom = denominator;

	// some validation.
	if(num < 0)   num = -num;
	if(denom < 0) denom = -denom;
	if(num == 0) { numerator = 0; denominator = 1; return; }
	
	int temp;
	
	// sample: 24/36
	while(num != 0)
	{
		if(denom > num) // 36 > 24, 24 > 12, 12 > 12
		{
			temp = num;
			num = denom; // 36, 24
			denom = temp;// 24, 12
		}
		
		num -= denom; // 36 - 24 = 12, 24 - 12 = 12, 12 - 12 = 0 
	}
	
	
	numerator   /= denom;
	denominator /= denom;
}
//#########################################################################//


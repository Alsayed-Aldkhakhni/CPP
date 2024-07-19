/*
 * Subject: Carry out 4-arithmetic operations on Fraction objects by overloaded operators.
 *
 * Date: July 17, 2024
 *
 * Author: Alsayed-Aldkhakhni
 *
 * Last modification: July 17, 2024
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
	void lowTerms(int&, int&);
	
public:
	// ctor.
	Fraction(int num = 0, int denom = 1)
	{
		if(denom == 0)
		{
			cout << "Division by zero is illegal.\n";
			exit(1);			
		}
		
		// simplify the fraction.
		lowTerms(num, denom);
		numerator = num;
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
	void getFraction() const
	{
		cout << numerator << '/' << denominator << " = " << (numerator / float(denominator)) << "\n";
	}
	
	// addition.
	Fraction operator+(Fraction& frac) const
	{
		int num   = numerator * frac.denominator + denominator * frac.numerator;
		int denom = denominator * frac.denominator;
		
		return Fraction(num, denom);
	}
	
	// subtraction.
	Fraction operator-(Fraction& frac) const
	{
		int num   = numerator * frac.denominator - denominator * frac.numerator;
		int denom = denominator * frac.denominator;
		
		return Fraction(num, denom);
	}
	
	// multiplication.
	Fraction operator*(Fraction& frac) const
	{
		int num   = numerator   * frac.numerator;
		int denom = denominator * frac.denominator;
		
		return Fraction(num, denom);
	}
	
	// division.
	Fraction operator/(Fraction& frac) const
	{
		int num   = numerator   * frac.denominator;
		int denom = denominator * frac.numerator;
		
		return Fraction(num, denom);
	}
	
	// rational operators.
	bool operator==(const Fraction& frac) const
	{
		return (numerator == frac.numerator && denominator == frac.denominator);
	}
	
	bool operator!=(const Fraction& frac) const
	{
		return (numerator != frac.numerator || denominator != frac.denominator);
	}
};

void Fraction::lowTerms(int& x, int& y)
{
	// take copies to divide by later.
	int num   = x;
	int denom = y;

	// some validation.
	if(num < 0)   num = -num;
	if(denom < 0) denom = -denom;
	if(num == 0) { x = 0; y = 1; return; }
	
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
	
	
	x /= denom;
	y /= denom;
}
//#########################################################################//

int main()
{
	// instantiate the objects to hold the data.
	Fraction frac1, frac2;
	Fraction stop(0, 1);
	
	// read the fractions.
	frac1.setFraction();
	frac2.setFraction();
	
	while(frac1 != stop || frac2 != stop)
	{	
		cout << "\n\n";
		cout << "+: "; (frac1+frac2).getFraction();
		cout << "-: "; (frac1-frac2).getFraction();
		cout << "*: "; (frac1*frac2).getFraction();
		cout << "/: "; (frac1/frac2).getFraction();
		cout << "\n\n";
		
		frac1.setFraction();
		frac2.setFraction();	
	}	

	// indicates a successful execution.
	return 0;
}




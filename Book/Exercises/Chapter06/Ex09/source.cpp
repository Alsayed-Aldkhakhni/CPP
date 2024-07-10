/*
 * Subject: Simulate fractions as class.
 * 
 * Date: January 20, 2024
 * 
 * Author: Alsayed-Aldkhakhni
 * 
 * Last modification: July 10, 2024
 * 
 * */

#include <iostream> // for cin, cout declaration.
using namespace std;// for their definition.

//######################################################################################//
class Fraction
{
private:
	int numerator;
	int denominator;
	
public:
	// constructors.
	Fraction(int num = 1, int denom = 1) : numerator(num)
	{
		if(denom == 0)
		{
			cout << "Division by zero is illegal.\n";
			exit(1);
		}
		
		denominator = denom;
	}
	
	// read fraction from the user.
	void setFraction()
	{
		int x, y; char dummy;
		cout << "Enter a fraction(x/y): ";
		cin >> x >> dummy >> y;
		
		if(y == 0)
		{
			cout << "Division by zero is illegal.\n";
			exit(1);
		}
		
		numerator = x;
		denominator = y;
	}
	
	// display it.
	void getFraction() const
	{
		cout << numerator << '/' << denominator << " = " << (numerator / float(denominator)) << "\n";
	}
	
	// add two fractions.
	Fraction add(Fraction frac1) const
	{
		int num   = numerator * frac1.denominator + denominator * frac1.numerator;
		int denom = denominator * frac1.denominator;
		
		return Fraction(num, denom);	
	}
};
//######################################################################################//

int main()
{
	// instantiate 3 objects.
	Fraction frac1, frac2, sum;
	
	for(int i = 0; i < 5; i++)
	{
		// read the fractions.
		frac1.setFraction();
		frac2.setFraction();
		
		// adding them.
		sum = frac1.add(frac2);
		
		// display the fractions.
		cout << "    Frac1:  "; frac1.getFraction();
		cout << "    Frac2:  "; frac2.getFraction();
		cout << "    Sum1+2: "; sum.getFraction();
		cout << "\n\n";
	}
	
	
	// indicates a successful execution.
	return 0;
}

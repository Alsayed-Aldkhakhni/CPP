#include <iostream>			// cin, cout declaration.
#include "Rational.h"		// class interface.

void Rational::reduceFraction(int a, int b)
{
	// sample fraction.
	// 24 / 36
	
	//take copies to find the greatest common deviser 'GCD'.

	int num = a;			// 24 
	int donum = b;			// 36

	if (b > a)				// to know which one is the bigger.
	{
		int temp = num; num = donum; donum = temp;
	}

	while (donum != 0)		// keep going to find the number between them whose reminder is 0
	{
		int temp = donum;	// 24, 12

		donum = num % donum;// 36 % 24 = 12, 24 % 12 = 0
		num = temp;			// 24, 12
	}

	// divide the actual values with the 'GCD', num, in this step.

	numerator = a / num;	// 24 / 12  = 2
	denominator = b / num;	// 36 / 12 = 3
}

//************************************************************

Rational::Rational(int a, int b)
{
	try // check validation.
	{
		if (b == 0) throw "Can't divide by 0, so i will set it to 1\f";
	}
	catch (const char* msg)
	{
		std::cout << msg; // show the message.
		b = 1;			  // set the denominator to 1
	}

	reduceFraction(a,b); // reduce the fraction.
}

//************************************************************

void Rational::setNumerator(int num) { numerator = num; }

int Rational::getNumerator() const { return numerator; }

//************************************************************

void Rational::setDenominator(int denom)
{
	try
	{
		if (denom == 0) throw "Can't divide by 0, so i will set it to 1\f";
	}
	catch (const char* msg)
	{
		std::cout << msg;
		denom = 1;
	}

	denominator = denom;
}

int Rational::getDenominator() const { return denominator; }

//************************************************************

Rational Rational::operator+(Rational R0)
{
	int num = numerator * R0.denominator + denominator * R0.numerator;

	int denom = denominator * R0.denominator;

	return Rational(num, denom);
}

Rational Rational::operator-(Rational R0)
{
	int num = numerator * R0.denominator - denominator * R0.numerator;

	int denom = denominator * R0.denominator;

	return Rational(num,denom);
}

//************************************************************

Rational Rational::operator*(Rational R0)
{

	int num = numerator * R0.numerator;

	int denom = denominator * R0.denominator;

	return Rational(num, denom);
}

Rational Rational::operator/(Rational R0)
{
	int num = numerator * R0.denominator;

	int denom = denominator * R0.numerator;

	return Rational(num, denom);
}

//************************************************************

void display(Rational R0) // class's friend.
{
	std::cout << R0.numerator << '/' << R0.denominator << " = "
			  << float(R0.numerator) / float(R0.denominator) << "\f\f";
}
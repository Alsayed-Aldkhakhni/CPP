#pragma once		// preprocessor wrapper prevents the redefinition of a header file's content.
class Rational		// class definition.
{					// friend to access the object's members and print normally without (.).
	friend	void display(Rational);


private:			// data members section.
	int numerator;
	int denominator;

					// it's private since we won't use it directly.
	void reduceFraction(int, int); 

public:				// member functions.
					// default argument ctor.
	Rational(int num = 1, int dnum = 1); 

					// mutators.
	int getNumerator() const;
	int getDenominator() const;

					// accessors
	void setNumerator(int);
	void setDenominator(int);

					// overloading operators.
	Rational operator+(Rational);
	Rational operator-(Rational);

	Rational operator*(Rational);
	Rational operator/(Rational);
};
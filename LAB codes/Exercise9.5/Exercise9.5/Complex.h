#pragma once	// preprocessor wrapper prevent the redefinition of the header file.
class Complex	// class definition.
{				// class's friend.
friend void display(Complex Com); 

private:		// data members.
	double realPart;
	double imaginaryPart;

public:			// member functions.
				// default argument ctor.
	Complex(double real = 1, double imagin = 1);

				// overload two operators '+, -' to perform these operations on my class's objects.
	Complex operator +(Complex) const;
	Complex operator -(Complex) const;
				// const since it won't modify the values of objects.
};
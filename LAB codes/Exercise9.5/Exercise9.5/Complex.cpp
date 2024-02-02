// preprocessor directive instructs the preprocessor, a part of the compiler, to
// fetch the whole content of these header files to the current source file.

#include <iostream>			// contains cin, cout declaration.
#include"Complex.h"			// the class interface.

//****************************************************************	
// 		
Complex::Complex(double real, double imagine) :realPart(real), imaginaryPart(imagine)
{
							// 'cotr'
}

void display(Complex Com)	// friend.
{
	std::cout << '(' << Com.realPart << ", " << Com.imaginaryPart << "i)\n\n";
}

//************************** operators ****************************

Complex Complex::operator+(Complex C1) const
{
	double real = realPart + C1.realPart;
	double imagine = imaginaryPart + C1.imaginaryPart;

	return Complex(real, imagine);
}

Complex Complex::operator-(Complex C1) const
{
	double real = realPart - C1.realPart;
	double imagine = imaginaryPart - C1.imaginaryPart;

	return Complex(real, imagine);
}
//****************************************************************
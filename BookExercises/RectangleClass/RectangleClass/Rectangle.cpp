// The actual implementation of Rectangle class.
 

// preprocessor directives instruct the compiler's preprocessor to fetch the whole content of these header files.
#include <iostream>		// contains 'cout' declaration.
#include "Rectangle.h"	// class interface.

//***********************************************************************************

						// overloaded ctor to enable the user to set his values.
Rectangle::Rectangle(float Len, float Wid)
{
	setLength(Len);		// call the function to check the values, it's more controlled.
	setWidth(Wid);
}

						// default ctor to initialize the attributes once we make an objet.
						// initializer list.
Rectangle::Rectangle():length(0.0), width(0.0) 
{}

Rectangle::~Rectangle() // destructor to deallocate the memory space reserved for an object.
{}

//*************************** setters & getters **************************************

void Rectangle::setLength(float Len) { length = Len > 0.0 ? Len : 0; }

void Rectangle::setWidth(float Wid) { width = Wid > 0.0 ? Wid : 0; }

float Rectangle::getLength() const { return length; }

float Rectangle::getWidth() const { return width; }

//***********************************************************************************

float Rectangle::getArea() const { return length * width; }

float Rectangle::getCircumference() const { return (length + width) * 2; }

//******************************** Operators *****************************************

									// const since won't modify the data members.
Rectangle Rectangle::operator + (Rectangle R0) const 
{
	float len = length + R0.length;	// just take copies.
	float wid = width + R0.width;

	return Rectangle(len, wid);		// use overloaded ctor to initialize the returned object.
}

Rectangle Rectangle::operator - (Rectangle R0) const
{
	float len = length - R0.length;
	float wid = width - R0.width;

	return Rectangle(len, wid);		// return the difference.
}

//***********************************************************************************

void Rectangle::display() const		// display the information about this caller object.
{
	std::cout << "Length: " << getLength()
		      << "\tWidth: " << getWidth()
			  << "\fArea: " << getArea()
			  << "\tCircumference: " << getCircumference();
}
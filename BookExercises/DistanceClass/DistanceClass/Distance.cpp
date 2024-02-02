// Preprocessor directives instructs the compiler's preprocessor to fetch the whole content of these header files.
#include <iostream>						// 'cout' declaration.
#include "Distance.h"					// members declaration, prototypes.


//******************************* Special methods ************************************

Distance::Distance() :feet(0), inches(0)// default ctor.
{}

Distance::Distance(int ft, float inch)	// overloaded ctor.
{
	setFeet(ft);
	setInches(inch);
}

Distance::~Distance()					// destructor.
{}

//******************************** Printing methods ***********************************

void Distance::displayDistance() const
{
	std::cout << getFeet() << '\''
			  << "-" << getInches() << '\"' << '\f';
}

void display(Distance D1)
{
	std::cout << D1.feet << '\''
			  << "-" << D1.inches << '\"' << '\f';
}

//***************************** Feet's functions ***************************************

void Distance::setFeet(int foot) { feet = foot > 0 ? foot : 0; }

int Distance::getFeet() const { return feet; }

//***************************** Inches' functions **************************************

void Distance::setInches(float inch) { inches = inch > 0.0 ? inch : 0; }

float Distance::getInches() const { return inches; }

//***************************** Addition functions *************************************

Distance Distance::add(const Distance dist) const // const since it doesn't modify any data member.
{
	Distance tempDist;

	tempDist.feet = feet + dist.feet;
	tempDist.inches = inches + dist.inches;

	if (tempDist.inches >= 12.0) // Since a foot equals 12 inches.
	{
		tempDist.feet++;
		tempDist.inches -= 12.0;
	}

	return tempDist;
}

void Distance::add(Distance obj1, Distance obj2) // this modify the data members of the caller object.
{
	// the feet and inches here are referring to the attributes of the caller object.
	// feet here is a direct access and obj1.feet is indirect access to its attribute.

	feet = obj1.feet + obj2.feet;				// total feet.
	inches = obj1.inches + obj2.inches;			// total inches.
}


// static methods.
// it can't be 'const' since the const method doesn't modify the object's data..
// but static method doesn't operate on objects but on the class itself.

Distance Distance::addDistance(Distance dist1, Distance dist2)
{
	int ft = dist1.feet + dist2.feet;
	float inch = dist1.inches + dist2.inches;

	if (inch >= 12.0)							// since a foot is 12 inches.
	{
		ft++;
		inch -= 12;
	}

	return Distance(ft ,inch);					// the overloaded ctor to initialize data members, feet and inches.
}


// overloading the '+' operator.

Distance Distance::operator+(Distance inputDist) const
{
	Distance tempDist;

	tempDist.feet = feet + inputDist.feet;
	tempDist.inches = inches + inputDist.inches;

	return Distance(tempDist);					// return the sum.
}


// overloading the '-' operator.

Distance Distance::operator-(Distance inputDist) const
{
	Distance tempDist;

	tempDist.feet = feet - inputDist.feet;
	tempDist.inches = inches - inputDist.inches;

	return Distance(tempDist);
}

//***************************************************************************************
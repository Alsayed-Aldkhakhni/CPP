//============================================================================
// Name        : Distance.h
// Date        : July 12, 2024
// Author      : Alsayed-Aldkhakhni
// Version     : V1.0
// Copyright   : Nothing to be mentioned.
// Description : Distance class that simulates english distance system.
//============================================================================
#include <iostream> // for cin, cout declaration.
using namespace std;// the definition of cin, cout.

//#############################################################################//
class Distance    // class definition.
{
private:
	int feet;
	float inches;
	
	void validate(int, float );
public:
	Distance() : feet(0), inches(0.0) {}

	Distance(float fVal)
	{
		if(fVal <= 0)
		{
			cout << "Invalid floating value.\n";
			exit(1);
		}


		feet = static_cast<int>(fVal);
		inches = static_cast<float>((fVal-feet) * 12);

		validate(feet, inches);
	}

	Distance(int ft, float inch) { validate(ft, inch); }

	void setDist();
	void getDist() const;

	Distance operator-(Distance& dist);
	friend	Distance operator*(Distance dist1, Distance dist2);
};
//#############################################################################//

// for handling the data part.
void Distance::getDist() const { cout << "\u00A3" << feet << "\'-" << float(inches) << "\".\n"; }
void Distance::setDist()
{
	int ft; float inch;
	
	cout << "Enter a distance[15 11.99]: ";
	cin >> ft >> inch;
	
	validate(ft, inch);
}

// for data validation.
void Distance::validate(int ft, float inch)
{
	if(inch < 0 || ft < 0)
	{
		cout << "Invalid value(s) entered.\n";
		exit(1);
	}
	
	feet = ft;
	inches = inch;
	
	// sample: 25
	if(inch >= 12)
	{
		// 25/12 = 2  <-- int accepts no fractions.
		feet += inch / 12;

		// 25 - [(25/12) * 12] 
		// 25 - [24] = 1.
		inches = inch - ( int(inch / 12) * 12);
		// inches = inch % 12; // also works.
	}
}

// subtract two operators.
Distance Distance::operator-(Distance& dist)
{
	// convert to decimal
	float cDist = feet + inches/12;
	float iDist = dist.feet + dist.inches/12;
	
	// subtract both values.
	cDist -= iDist;
	
	// convert the result.
	int ft = static_cast<int>(cDist);
	float inch = static_cast<float>((cDist - ft) * 12);
	
	return Distance(ft, inch);
}

// friend function, not belong to the class.
Distance operator*(Distance dist1, Distance dist2)
{
	float fDist1 = dist1.feet + dist1.inches / 12.0;
	float fDist2 = dist2.feet + dist2.inches / 12.0;

	fDist1 = fDist1 * fDist2;

	int ft = static_cast<int>(fDist1);
	float inch = static_cast<float>((fDist1 - ft) * 12);

	return Distance(ft, inch);
}
//#############################################################################//

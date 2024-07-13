//============================================================================
// Name        : source.c
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
	Distance(int ft=0, float inch= 0.0) { validate(ft, inch); }
	void setDist();
	void getDist() const;
	Distance operator-(Distance& dist);
};
//#############################################################################//

// for handling the data part.
void Distance::getDist() const { cout << "\u00A3" << feet << "\'-" << inches << "\".\n"; }
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
		// 25/2 = 2  <-- int accept no fractions.
		feet += inch / 12;

		// 25 - [(25/12) * 12] 
		// 25 - [24] = 1.
		inches = inch - ( int(inch / 12) * 12);
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
//#############################################################################//

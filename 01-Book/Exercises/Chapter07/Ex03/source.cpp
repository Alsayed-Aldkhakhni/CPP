//============================================================================
// Name        : source.cpp
// Date        : July 11, 2024
// Author      : Alsayed-Aldkhakhni
// Version     : V1.0
// Copyright   : Nothing to be mentioned.
// Description : Average some distances of class Distance.
//============================================================================

#include <iostream> // for cin, cout objects declaration.
using namespace std;// for cin, cout definition.

//############################################################################//
class Distance
{
private:
	int feet;
	float inches;
	
	void validate(int, float);
public:
	// this serves as no and 2-arg ctor.
	Distance(int ft = 0, float inch = 0.0) { validate(ft, inch); }
	
	// read the data from the user.
	void setDist()
	{
		int ft; float inch;
		cout << "Enter a distance[e.g. 7 11.99]: ";
		cin >> ft >> inch;
		
		validate(ft, inch);
	}
	
	// display the standard form.
	void getDist() const { cout << feet << "\'-" << inches << "\".\n"; }
	
	// add the input distance to the caller.
	void add(Distance& dist)
	{
		feet   += dist.feet;
		inches += dist.inches;
	}
	
	Distance avg(int divisor)
	{
		// convert to decimal.
		float total = (feet + (inches / 12.0)) / divisor;
		
		// the new values.
		int ft = static_cast<int>(total);
		float inch = (total - ft) * 12;
		
		// the average value.
		return Distance(ft, inch);
	}
};

void Distance::validate(int ft, float inch)
{
	// validate the input.
	if(ft < 0 || inch < 0)
	{
		cout << "Invalid value entered.\n";
		exit(1);
	}
	
	// assign the values of they're valid.
	feet = ft;
	inches = inch;
	
	// logical step.
	if(inch >= 12) // sample: 25
	{
		// 25 / 12 = 2 <-- no fractions.
		feet += inch / 12;
		
		// 25 - (25 / 12) / 12 = 25 - 24 = 1. 
		inches = inch - ( (inch / 12) * 12); 
	}
}

//############################################################################//

int main()
{
	// # of objects.
	const short LIM = 5;
	Distance dists[LIM];
	Distance sum, avg;
	
	// read the data and add it.
	for(int i = 0; i < LIM; i++)
	{
		dists[i].setDist();
		sum.add(dists[i]);
	}
	
	// average it.
	avg = sum.avg(LIM);
	
	// display the distances.
	for(int i = 0; i < LIM; i++)
	{
		cout << "Distance #" << i+1 << ": ";
		dists[i].getDist();
	}
	
	// the average.
	cout << "Average: "; avg.getDist();
	
	// the program executed without any errors.
	return 0;
}


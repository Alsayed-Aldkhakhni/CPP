//============================================================================
// Name        : source.cpp
// Date        : July 11, 2024
// Author      : Alsayed-Aldkhakhni
// Version     : V1.0
// Copyright   : Nothing to be mentioned.
// Description : Average some fractions.
//============================================================================

#include <iostream>  // for cin, cout objects declaration.
#include "Fraction.h"// the reference of data type Fraction.
using namespace std; // for cin, cout definition.

int main()
{
	const short LIM = 10;  // size of the array.
	Fraction fracList[LIM],// objects to hold data.
	         sum, avg;
	int n = 0;             // # of fractions entered.
	char ans = 'y';        // user's answer to insert more fractions.
	
	// iterate until the end.
	while(ans == 'y' && n < LIM)
	{
		// read and add the fraction.
		fracList[n].setFraction();
		sum.add(fracList[n++]);
		
		cout << "One more?(y, n): ";
		cin >> ans;
	}
	

	// display the fractions.
	for(int i = 0; i < n; i++)
	{
		cout << "Fraction #"<< i+1 << ": "; fracList[i].getFraction();
	}
	
	// average them.
	avg = sum.avg(n);
	
	// display the average value.
	cout << "Average of them: "; avg.getFraction();
	
	// indicates a successful execution.
	return 0;
}
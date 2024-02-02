/*
 * Subject: A class that handles English measurement system.
 *
 * Date: November 25, 2023
 *
 * Author: Alsayed Aldkhakhni
 */

#include<iostream>						// declaration of cout,'<<' operator.
#include "Distance.h"					// the declaration of our ueser defind data type.
using namespace std;					// the definition of cout, '<<' operator.

int main()
{	
	Distance D0(11, 2.5F), D1(5, 7.25F), D2;

	// * this member function directly access the attributes of 'D2',
	// * and indirectly access the attributes of 'D0' and 'D1',
	// * and replace the result of addition in the attributes of D3 directly.

	D2.add(D0, D1);						// this is overloaded 'add()' method.
	D2.displayDistance();				// display the sum using member function.

	cout << "\n*******************\n\n";

	/***************************** test operators overloading. ********************************/


	Distance d1(5, 7.236F), d2, d3, d4; // I'm taking 4 objects of type 'Distance'.

	d2.setFeet(2);						// set the attributes using the member functions.
	d2.setInches(4.22F);

	d1.displayDistance();				// display distance using member function.
	display(d2);						// display distance d2 using friend function.

	cout << "\f";

	d3 = d1 + d2;						// adding two 'Distances'.

	cout << "Sum:  ";					// display the sum.
	d3.displayDistance();				

	d4 = d1 - d2;						// subtracting two 'Distances'.

	cout << "Diff: ";					// display the result using friend function.
	display(d4);						

	return 0;							// indicates the operating system that the program executed successfully.
}
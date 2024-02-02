/*
 * Subject: A rectangle class that simulates the rectangle object.
 *
 * Date: November 19, 2023
 *
 * Author: Alsayed Ali
 */

// preprocessor directives instruct the compiler's preprocessor
//  to fetch the whole content of these header files.

#include <iostream>			// A header file contains the declaration of 'cout' function, which i used, and more funciton.
#include "Rectangle.h"		// To get your class in this file and use its members.

using namespace std;		// the definition of cout, and other objects.
int main()
{
							// take 4-instances of type 'Rectangle'.
	Rectangle R0, R1, R2(7.25F,3.26F),R3;

	R1.setLength(12.5F);	// set the length.
	R1.setWidth(9.236F);	// the width.

	R0 = R1 + R2;			// add them.
	R0.display();			// display the result.

	cout << "\n-------------------------------------\f";

	R3 = R0 - R2;			// the value of 'R1'.
	R3.display();

	cout << "\n-------------------------------------";
	return 0;				// indicates the operating system that the program executed successfully.
}
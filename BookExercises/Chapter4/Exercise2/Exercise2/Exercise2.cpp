/*
 * Subject: A program that models a point in the coordinate plane.
 *
 * Date: December 11, 2023
 *
 * Author: Alsayed Aldkhakhni
 */

// Preprocessor directive instruct the compiler's preprocessor to
//  fetch the whole content of that header file into the current source file.
#include <iostream>						// for cin, cout declaration.
using namespace std; 					// 'cin', 'cout' defination.

struct Point 							// structure's tag.
{
	int xCoordinate;					// members.
	int yCoordinate;
};

int main()
{
	Point P1{}, P2{}, P0{};

	cout << "Enter coordinate: "; 		// Prompt message to inform the user what to do.
										// get the coordinates and assign them in the members.
	cin >> P1.xCoordinate >> P1.yCoordinate; 

	cout << "Enter coordinate: "; 		// Prompt message to inform the user what to do.
										// get the coordinates and assign them in the members.
	cin >> P2.xCoordinate >> P2.yCoordinate; 
										// adding them together.
	P0.xCoordinate = P1.xCoordinate + P2.xCoordinate;
	P0.yCoordinate = P1.yCoordinate + P2.yCoordinate;

	cout << "\n\n";
										// print the three points.
	cout << "Point 1: "
		 << '(' << P1.xCoordinate << ',' << P1.yCoordinate << ')' << '\f';

	cout << "Point 2: "
		 << '(' << P2.xCoordinate << ',' << P2.yCoordinate << ')' << '\f';

	cout << "Point 3: "
		 << '(' << P0.xCoordinate << ',' << P0.yCoordinate << ')' << '\f';

	return 0; 							// flag the 'OS' that the program executed successfully.
}
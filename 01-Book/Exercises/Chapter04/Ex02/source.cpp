/*
 * Subject: Simulate a point structure on the plane. 
 * 
 * Date: December 12, 2023
 * 
 * Author: Alsayed-Aldkhakhni
 * 
 * Last modification: July 7, 2024
 * 
 * */

#include <iostream> // for cin, cout declaration.
using namespace std;// for their definition.

struct Point // structure tag.
{
	short x;
	short y;
};

int main()
{
	// declare 3 objects of Point structure.
	Point point1, point2, point3;
	
	// read the 1st point.
	cout << "Enter coordinates of a point: ";
	cin >> point1.x >> point1.y;
	
	// read the 2nd point.
	cout << "Enter coordinates of a point: ";
	cin >> point2.x >> point2.y;
	
	// sum the two points.
	point3.x = point1.x + point2.x;
	point3.y = point1.y + point2.y;
	
	// display the points.
	cout << "The points: \n"
		 << "1st point:   (" << point1.x << ", " << point1.y << ")\n"
		 << "2nd point:   (" << point2.x << ", " << point2.y << ")\n"
		 << "Sum of them: (" << point3.x << ", " << point3.y << ")\n";

	 // indicates a successful execution.
	return 0;
}


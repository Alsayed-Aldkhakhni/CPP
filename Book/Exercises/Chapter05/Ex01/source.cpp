/*
 * Subject: A function that caculates the area of the circule.
 * 
 * Date: January 1, 2024
 * 
 * Author: Alsayed-Aldkhakhni
 * 
 * Last modification: July 8, 2024
 * 
 * */


#include <iostream> // for objects cin, cout declaration.
using namespace std;// for their definition.

// functions' prototypes.
double readRadius();
double calcArea(double);

int main()
{
	// call the functions.
	double radius = readRadius();
	double area   = calcArea(radius);
	
	// print the result.
	cout << "Ther area is: " << area << "\n\n";
	
	// indicates a successful execution
	return 0;
}

// functions' definitions.
double readRadius()
{
	double r;
	cout << "Enter the radius of the circule: ";
	cin >> r;
	
	if(r < 0)
	{
		cout << "Invliad radius.\n";
		exit(1);
	}
	
	return r;
}

double calcArea(double radius)
{
	return radius * radius * 3.14159F;
}
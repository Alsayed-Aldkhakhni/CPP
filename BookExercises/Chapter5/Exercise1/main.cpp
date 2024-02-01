/*
 * Subject: A program to calculate the area of a circle.
 *
 * Date: November 20, 2023
 *
 * Author: Alsayed Aldkhakhni
 */


// preprocessor directive that instructs the preprocessor to fetch 
// the whole content of the that header file to the current source file.

#include <iostream> 			// cin, cout declaration is in this header file.

float calcArea(float radius); 	// function's prototype.

int main()
{
	float radius;				// create the varible which will hold the user's input.

								// prompt message tells the user what's going on.
	std::cout << "Enter the radius of a circule: ";
	std::cin >> radius;			// get the radius from him.
	
								// call the function that will calculate and return the area.
	std::cout << "Radius is: " << calcArea(radius); 
	
	return 0;					// flags the 'OS' that the program is done.
}
								
float calcArea(float radius)	// function defination.
{
	return (radius * radius) * 3.1415F;
}
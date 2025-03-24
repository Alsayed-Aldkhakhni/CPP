/* *
 * Subject: Simulate a room and its three dimensions.  
 * 
 * Date: December 12, 2023
 * 
 * Author: Alsayed-Aldkhakhni
 * 
 * Last modification: July 7, 2024
 * 
 * */

#include <iostream> // for objects cin and cout declaration.
using namespace std;// for their definition.

struct Distance     // structure tag.
{
	int feet;
	float inches;
};

struct Volume
{
	Distance length;
	Distance width;
	Distance hight;
};

int main()
{
	// define the room and its dimensions.
	Volume bedroom{{3, 5.5}, {4, 2.8}, {5, 6.9}};
	
	// display the dinmensions.
	cout << "A bedroom with the following dimensions:\n"
		 << "Length: " << bedroom.length.feet << "'-" << bedroom.length.inches << "\"\n"
		 << "Width:  " << bedroom.width.feet  << "'-" << bedroom.width.inches << "\"\n"
		 << "Hight:  " << bedroom.hight.feet  << "'-" << bedroom.hight.inches << "\"\n";
	
	// convert the dimensions to be decimal.
	float length = bedroom.length.feet + bedroom.length.inches / 12.0;
	float width  = bedroom.width.feet  + bedroom.width.inches  / 12.0;
	float hight  = bedroom.hight.feet  + bedroom.hight.inches  / 12.0;
	
	// notice this is not an object of Volume struct, it is lower 'v'.
	double volume = length * width * hight;
	
	// print the volume just calculated.
	cout << "The volume of this room is: " << volume << "\n\n";

	// indicates a successful execution.
	return 0;
}
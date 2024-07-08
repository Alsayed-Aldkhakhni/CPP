/*
 * Subject: A function that compares two distance structures.
 * 
 * Time: January 1, 2024
 * 
 * Author: Alsayed-Aldkhakhni
 * 
 * Last modification: July 8, 2024
 * 
 * */

#include <iostream> // for objects cin, cout declaration.
using namespace std;// for their definition.
////////////////////////////////////
struct Distance     // struct tag.
{
	int feet;
	float inches;
};
////////////////////////////////////

// functions' prototype.
Distance& distCmp(Distance&, Distance&);
void showDist(Distance&);

int main()
{
	// instantiate 3 objects.
	Distance dist1{7, 1.5}, dist2{8, 1.5}, big;
	
	// call the function.
	big = distCmp(dist1, dist2);
	
	// call the other one to display.
	showDist(dist1);
	showDist(dist2);
	showDist(big);
	
	// indicates a successful execution.
	return 0;
}

// functions' definition.
void showDist(Distance& dist)
{
	cout << "distance: " << dist.feet << "'-" << dist.inches << "\"\n";
}

Distance& distCmp(Distance& dist1, Distance& dist2)
{
	if(dist1.feet > dist2.feet && dist1.inches > dist2.inches)
		return dist1;
	else
		return dist2;
}

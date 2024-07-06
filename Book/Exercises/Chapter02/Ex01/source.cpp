/*
 * Subject: Convert gas from gallons to cubic foot.
 * 
 * Date: December 1,  2023
 * 
 * Author: Alsayed-Aldkhakhni
 * 
 * Last modification: July 6, 2024
 */

#include <iostream> // for cout, cin declaration.
using namespace std;// for their definition.

int main()
{
	// define a gallons per foot.
	const float GALLONS_IN_FOOT = 7.481;
	float gallons;
	
	// prompt the user the number of gallons.
	cout << "Enter number of gallons: ";
	cin >> gallons;
	
	// convert the amount and display it.
	float cubicFoot = gallons / GALLONS_IN_FOOT;
	cout << gallons << " gallons = " << cubicFoot << " in cubic foot.\n";
	
	// indicates a successful execution.
	return 0;
}

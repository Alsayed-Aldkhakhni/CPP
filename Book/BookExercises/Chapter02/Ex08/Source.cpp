/*
 * Subject: A table of cities and their populations.
 *
 * Date: October 12, 2023
 *
 * Written by: Alsayed Aldkhakhni.
 *
 * Last modification: May 16, 2024
 */


#include <iostream>	// contains 'cin' and 'cout' declaration.
#include <iomanip>	// For 'setw' and 'setfill'.
using namespace std;// contains definition of cin, cout.

int main()
{
	// print a table of cities and their populations.
	cout << "LOCATION" << setw(15) << "POPULATION" << endl
		 << "Portcity" << setw(15) << setfill('.') << "2425785" << endl
		 << "Hightwon" << setw(15) << setfill('.') << "47" << endl
		 << "Lowville" << setw(16) << setfill('.') << "9761\n";

	// Flag the 'OS' that the program is done.
	return 0;
}

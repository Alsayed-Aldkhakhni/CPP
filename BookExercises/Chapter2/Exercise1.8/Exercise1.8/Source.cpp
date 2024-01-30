/*
 * Subject: A program to print some locations and their population values.
 *
 * Date: 10 / 12 / 2023........12th of October.
 *
 * Written by: Alsayed Aldkhakhni.
 */


#include<iostream>			// contains 'cin' and 'cout' declaration.
#include<iomanip>			// For 'setw' and 'setfill'.

using namespace std;		// contains definition of cin, cout.

int main()
{
	cout << "LOCATION" << setw(15) << "POPULATION" << endl
		 << "Portcity" << setw(15) << setfill('.') << "2425785" << endl
		 << "Hightwon" << setw(15) << setfill('.') << "47" << endl
		 << "Lowville" << setw(15) << setfill('.') << "9761";

	
	cout << "\n\n";			 // To enhance the clarity of the output.

	return 0;				 // Flag the 'OS' that the program is done.
}
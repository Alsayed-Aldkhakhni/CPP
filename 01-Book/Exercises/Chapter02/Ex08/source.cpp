/*
 * Subject: Print a table of data.
 * 
 * Date: December 1, 2023
 * 
 * Author: Alsayed-Aldkhakhni
 * 
 * Last modification: July 6, 2024
 */

#include <iostream> // for cin, cout objects declaration.
#include <iomanip>  // for setw, setfill library functions.
using namespace std;// for the definition of cin, cout.

int main()
{
	long pop1=2425785, pop2=47, pop3=9761;
	
	// print the data with filling character '.'
	cout << setfill('.')
		 << setw(8) << "LOCATION" << setw(12) << "POPULATION" << endl
		 << setw(8) << "Portcity" << setw(12) << pop1 << endl
		 << setw(8) << "Hightown" << setw(12) << pop2 << endl
		 << setw(8) << "Lowville" << setw(12) << pop3 << endl;
	
	// indicates a successful execution.
	return 0;
}
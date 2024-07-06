/*
 * Subject: Print a table of data.
 * 
 * Date: December 1, 2023 
 * 
 * Author: Alsayed-Aldkhakhni
 * 
 * Last modification: July 6, 2024
 */

#include <iostream> // for cout declaration.
#include <iomanip>  // for setw declaration.
using namespace std;// for their definition.

int main()
{
	
	// print the data.
	cout << "1990" << setw(10) << "135"  << "\n"
		 << "1991" << setw(10) << "7290" << "\n"
	     << "1992" << setw(10) << "11300"<< "\n"
	     << "1993" << setw(10) << "16200"<< "\n";
	
	// indicates a successful execution.
	return 0;
}

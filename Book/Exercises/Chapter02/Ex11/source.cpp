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
#include <iomanip>  // for setiosflags() library function.
using namespace std;// for their definition.


int main()
{
	
	// print the table header.
	cout << setiosflags(ios::left)
		 << setw(15) << "Last name" << setw(15) << "First name" << setw(20) << "Street address"
		 << setw(15) << "Town" << setw(5) << "State\n";
	
	cout << "------------------------------------------------------------------------\n";
	
	// print the content.
	cout << setiosflags(ios::left)
	     << setw(15) << "Jones" << setw(15) << "Bernard" << setw(20) << "109 Pine Lane"
		 << setw(15) << "Littletown" << setw(2) << "MI\n";
	
	cout << setiosflags(ios::left)
	     << setw(17) << "O’Brian" << setw(15) << "Coleen" << setw(20) << "42 E. 99th Ave."
		 << setw(15) << "Bigcity" << setw(2) << "NY\n";
	
	cout << setiosflags(ios::left)
	     << setw(15) << "Wong" << setw(15) << "Harry" << setw(20) << "121-A Alabama St."
		 << setw(15) << "Lakeville" << setw(2) << "IL\n";

	
	return 0;
}

 
 
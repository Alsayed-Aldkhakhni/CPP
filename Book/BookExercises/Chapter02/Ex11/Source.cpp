/*
 * Subject: Print a table of people.
 *
 * Date: October 12, 2023.
 *
 * Written by: Alsayed Aldkhakhni.
 *
 * Last modification: May 16, 2024
 */


#include<iostream>	// contains the declaration of 'cin' and 'cout'.
#include<iomanip>	// essential for 'setw' and 'setiosflags'.
using namespace std;// contains the definition of 'cin' and 'cout', what the current version of them does.

int main()
{
	// print the headers of the table.
	cout << setw(15) << setiosflags(ios::left) << "Last name" 
		 << setw(15) << setiosflags(ios::left) << "First name" 
		 << setw(20) << setiosflags(ios::left) << "Street address" 
		 << setw(15) << setiosflags(ios::left) << "Town" 
		 << setw(15) << setiosflags(ios::left) << "State";

	// This line is used to separate between the headers and the data.
	cout << "\n-----------------------------------------------------------------------\n";

	
	// first record.
	cout << setw(15) << setiosflags(ios::left) << "Jones"
		 << setw(15) << setiosflags(ios::left) << "Bernard"
		 << setw(20) << setiosflags(ios::left) << "109 Pine Lane"
		 << setw(15) << setiosflags(ios::left) << "Littletown"
		 << setw(15) << setiosflags(ios::left) << "MI" << "\n";

	// second record.
	cout << setw(15) << setiosflags(ios::left) << "O'Brain"
		 << setw(15) << setiosflags(ios::left) << "Coleen"
		 << setw(20) << setiosflags(ios::left) << "42 E. 99th Ave."
		 << setw(15) << setiosflags(ios::left) << "BigCity"
		 << setw(15) << setiosflags(ios::left) << "NY" << "\n";

	// third record.
	cout << setw(15) << setiosflags(ios::left) << "Wong"
		 << setw(15) << setiosflags(ios::left) << "Harry"
		 << setw(20) << setiosflags(ios::left) << "121-A Alabama St."
		 << setw(15) << setiosflags(ios::left) << "Lakeville"
		 << setw(15) << setiosflags(ios::left) << "IL";

	// flags the 'OS' that the program is done.
	return 0;
}

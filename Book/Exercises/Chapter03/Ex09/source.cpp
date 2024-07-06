/*
 * Subject: Calculate the possible arrangements for setting x-guests on y-seats.
 * 
 * Date: December 5, 2024
 * 
 * Author: Alsayed-Aldkhakhni
 * 
 * Last modification: July 6, 2024
 */

#include <iostream> // for cout, cin declaration.
using namespace std;// for cout, cin definition.

int main()
{
	int guests, seats;
	
	// read the guests number.
	cout << "Enter the number of guests: ";
	cin >> guests;
	
	// read the seats number.
	cout << "Enter the number of seats: ";
	cin >> seats;

	// validate the input.
	if(guests < 0 || seats < 0)
	{
		cout << "Invalid value entered.\n";
		exit(1);
	}
	
	long possibilities = 1;
	
	// calculate the arrangements.
	for(int i = 1, j = guests; i <= seats; i++)
		possibilities *= j--;
	
	// print the answer.
	cout << "The arrangements of " << guests << " guests set on " << seats << " seats is "
		 << possibilities << "\n\n";

	// indicates a successful execution.
	return 0;
}
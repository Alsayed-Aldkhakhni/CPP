/*
 * Subject: Print number's multiplies. 
 * 
 * Date: December 5, 2024
 * 
 * Author: Alsayed-Aldkhakhni
 * 
 * Last modification: July 6, 2024
 */

#include <iostream> // for cout, cin declaration.
#include <iomanip>  // for setw() library function.
using namespace std;// for cin, cout definition.

int main()
{
	// read the number.
	int num;
	cout << "Enter a number: ";
	cin >> num;
	
	// calculate the table of multiplies.
	for(int i = 1, j = 1; i <= 20; i++)
	{
		for(; j <= 10*i; j++)
			cout << setw(7) << num*j;
		
		cout << "\n";
	}
	
	
	// indicates a successful execution.
	return 0;
}
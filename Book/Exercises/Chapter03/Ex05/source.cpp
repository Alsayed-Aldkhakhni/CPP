/*
 * Subject: Pyramid of Xs.
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
	// the number of lines for the pyramid to be displayed.
	int lines;
	cout << "Enter # of lines: ";
	cin >> lines;
	
	// outer loop for lines.
	for(int i = 1; i <= lines; i++)
	{
		// spaces.
		for(int k = lines - i; k > 0; k--)
			cout<< " ";
		
		// Xs.
		for(int j = 1; j <= 2*i - 1; j++)
			cout << "x";
		
		// start from the next line.
		cout << "\n";
	}
	
	// indicates a successful execution.
	return 0;
}
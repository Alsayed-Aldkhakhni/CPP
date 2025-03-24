/*
 * Subject: Convert from new British monetary system the old.
 * 
 * Date: December 1, 2023
 * 
 * Author: Alsayed-Aldkhakhni
 * 
 * Last modification: July 6, 2024
 */

#include <iostream> // for cin, cout objects declaration.
using namespace std;// for their definition.

int main()
{
	// read the amount.
	double newNotation;
	cout << "Enter the amount in new notation: ";
	cin >> newNotation;
	
	// sample: 3.51
	int pounds = static_cast<int>(newNotation); // 3

	// (3.51 - 3) * 20.0
	// (0.51) * 20.0 = 10
	int shillings = static_cast<int>((newNotation - pounds ) * 20.0);
	
	// ((3.51 - 3) * 20.0 - 10) * 12.0 = 2
	// ((0.51) * 20.0     - 10) * 12.0
	// (10.2              - 10) * 12.0
	// (0.2					  ) * 12.0
	// = 2
	int pence = static_cast<int>( ((newNotation - pounds ) * 20.0 - shillings) * 12.0);
	
	// so the answer is 3.10.2.
	cout << "The new notation: \u00A3" << newNotation << "\n"
	 	 << "The old notation: \u00A3" << pounds << '.' << shillings << '.' << pence << '.' << "\n";
	
	// indicates a successful execution.
	return 0;
}
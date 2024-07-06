/*
 * Subject: Test operators.
 * 
 * Date: December 1, 2023
 * 
 * Author: Alsayed-Aldkhakhni
 * 
 * Last modification: July 6, 2024
 */

#include <iostream> // for cout declaration.
using namespace std;// for its definition.

int main()
{
	// integer constant.
	cout << 10 << "\n";
    
	// define the variable.
    int var = 10;
    
    // arithmetic assignment operator.
    cout << (var += 10) << "\n";
    	
    // decrement operator.
    cout << --var  << "\n";
    
	// indicates a successful execution.
	return 0;
}

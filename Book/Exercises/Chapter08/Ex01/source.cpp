//============================================================================
// Name        : source.c
// Date        : July 12, 2024
// Author      : Alsayed-Aldkhakhni
// Version     : V1.0
// Copyright   : Nothing to be mentioned.
// Description : Subtract 2 english distances using overloaded - operator.
//============================================================================
#include <iostream>  // for cin, cout declaration.
#include "Distance.h"// the reference to Distance data type.
using namespace std; // the definition of cin, cout.

int main()
{
	// instantiate 3 objects.
	Distance dist1, dist2, diff;
	
	// carry out the operations.
	for(int i = 0; i < 5; i++)
	{
		// read the distances.
		dist1.setDist();
		dist2.setDist();
		
		// subtract them.
		diff = dist1 - dist2;
		
		// display.
		cout << "\n";
		cout << "dist1: "; dist1.getDist();
		cout << "dist2: "; dist2.getDist();
		cout << "diff:  "; diff.getDist();
		cout << "\n";
	}
	
	// indicates a successful execution.
	return 0;
}





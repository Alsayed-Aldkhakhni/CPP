//============================================================================
// Name        : source.cpp
// Date        : July 12, 2024
// Author      : Alsayed-Aldkhakhni
// Version     : V1.0
// Copyright   : Nothing to be mentioned.
// Description : Test overloaded and friend operators on english distances.
//============================================================================
#include <iostream>  // for cin, cout declaration.
#include "Distance.h"// the reference to Distance data type.
using namespace std; // the definition of cin, cout.

int main()
{
	// instantiate 2 objects.
	Distance dist1, dist2;
	Distance dist3;

	// carry out the operations.
	for(int i = 0; i < 5; i++)
	{
		// read the distances.
		dist1.setDist();
		dist2.setDist();
		
		// display.
		cout << "\n";

		cout << "dist1: "; dist1.getDist();
		cout << "dist2: "; dist2.getDist();

		cout << "diff:  "; (dist1-dist2).getDist();
		cout << "mul:   "; (dist1*dist2).getDist();
		
		dist3 = 3.25 * dist2;
		cout << "mul:   "; dist3.getDist();

		cout << "\n";
	}
	
	// indicates a successful execution.
	return 0;
}





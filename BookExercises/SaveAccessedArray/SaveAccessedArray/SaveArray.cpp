#include <iostream>						// declaration of cout.
#include "SaveArray.h"					// to use the methods of that class.

SaveArray::SaveArray() {}				// default constructor.

int& SaveArray::operator[](int index)	// the definition of the operator '[]' to work as we want.
{
	if (index < 0 || index >= SIZE)		// check the boundary.
	{
		std::cout << "Exceeded the boundary.\n";
		exit(1);						// if the boundary exceeded the limit, stop immediately.
	}

	return arr[index];					// otherwise return the position.
}
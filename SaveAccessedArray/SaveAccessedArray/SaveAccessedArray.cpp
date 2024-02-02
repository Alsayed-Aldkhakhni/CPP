/*
 * Subject: A program that makes its array to check the index before doing the operation.
 * 
 * Date: January 4, 2023
 * 
 * Author: Alsayed Aldkhakhni
 */

#include <iostream>				// cout declaration.
#include "SaveArray.h"			// class header file to use 'SaveArray' data type.

int main()
{
	SaveArray arr1;				// get an instance 'arr1' of type 'SaveArray'.

	for (int i = 0; i < 5; i++)	// set the values in the array.
	{
		arr1[i] = i * 2;		// multiply 'i' by 2 and store the result in the index 'i'.
	}

	//std::cout << arr1[100];	// you will get an error, since you exceeded the limit.

	for (int i = 0; i < 5; i++)	// display the array.
	{
		std::cout << i + 1 << "th item = " << arr1[i] << '\n';
	}

	return 0;					// flags the operating system that the program executed successfully.
}
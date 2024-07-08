/*
 * Subject: Static variable vs global one in function's body.
 * 
 * Time: January 1, 2024
 * 
 * Author: Alsayed-Aldkhakhni
 * 
 * Last modification: July 8, 2024
 * 
 * */

#include <iostream> // for objects cin, cout declaration.
using namespace std;// for their definition.

int intGlobVar = 0;

//////////////////////////
// functions' prototype.
void sayHi1();
void sayHi2();
//////////////////////////

int main()
{
	// call the first function and pass to it the global variable.
	for(int i = 0; i < 10; i++) sayHi1();
	
	cout << "----------------------------\n";
	
	// call the other one that takes nothing.
	for(int i = 0; i < 10; i++) sayHi2();
	
	// indicates sucessful execution.
	return 0;
}

// functions' bodies.
void sayHi1()
{
	cout << "I have been called " << ++intGlobVar << " times.\n";
}

void sayHi2()
{
	static int x = 0;	
	cout << "I have been called " << ++x << " times.\n";
}



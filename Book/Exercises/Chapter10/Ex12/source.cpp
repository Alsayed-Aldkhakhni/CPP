/*
 * Subject: A poor try to simulate C++ pointers' behaviour.
 *
 * Date: July 22, 2024
 *
 * Author: Alsayed-Aldkhakhni
 *
 * Last modification: July 22, 2024
 *
 * */

#include <iostream> // for the declaration of cin, cout objects.
using namespace std;// for the definition  of cin, cout.

//#################################################################################//
// stores the data.
float fMemory[10];
int fMemTop = 0;

// stores the address.
int addresses[10];
int adMemTop = 0;

class Float // the data type.
{
private:
	int address;
public:
	Float(float fVal) : address(fMemTop++)
	{
		fMemory[address] = fVal;
	}

	int operator&() { return address; }
};

class PtrFloat // the pointer.
{
private:
	int address;

public:
	PtrFloat(int i) : address(i)
	{
		addresses[adMemTop++] = address;
	}

	float& operator*() { return fMemory[ addresses[address]]; }
};

//#################################################################################//
int main()
{
	Float var1 = 1.234;
	Float var2 = 5.678;

	PtrFloat ptr1 = &var1;
	PtrFloat ptr2 = &var2;

	cout << "*ptr1= " << *ptr1 << "\n";
	cout << "*ptr2= " << *ptr2 << "\n";

	*ptr1 = 7.123;
	*ptr2 = 8.456;

	cout << "*ptr1= " << *ptr1 << "\n";
	cout << "*ptr2= " << *ptr2 << "\n";

	// indicates a successful execution, popping off the stack.
	return 0;
}

//============================================================================
// Name        : source.cpp
// Date        : July 12, 2024
// Author      : Alsayed-Aldkhakhni
// Version     : V1.0
// Copyright   : Nothing to be mentioned.
// Description : Array that checks the index before accessing it.
//============================================================================
#include <iostream> // for cin, cout objects declaration.
using namespace std;// for their definition.

//##########################################################################//
class SafeArray
{
private:
	enum {LIM = 100};
	int arr[LIM];

public:
	SafeArray() {}
	
	void store(int index, int value)
	{
		if(index < 0 || index >= LIM)
		{
			cout << "Ivalid index.\n";
			exit(1);
		}
		
		arr[index] = value;
	}
	
	int retrieve(int index) const
	{
		if(index < 0 || index >= LIM)
		{
			cout << "Ivalid index.\n";
			exit(1);
		}
		
		return arr[index];
	}
	
};
//##########################################################################//

int main()
{
	// instantiate an object.
	SafeArray safe_array1;
	
	// store some items.
	for(int i = 0; i < 15; i++)
		safe_array1.store(i, i);
	
	// safe_array1.store(100, 50); // will flag an error.
	
	// display them.
	for(int i = 0; i < 15; i++)
		cout << "Item #" << i+1 << ": " << safe_array1.retrieve(i) << '\n';
	
	// safe_array1.retrieve(100); // will flag an error.
	
	// indicates a successful execution
	return 0;
}





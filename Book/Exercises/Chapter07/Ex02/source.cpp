//============================================================================
// Name        : source.cpp
// Date        : July 11, 2024
// Author      : Alsayed-Aldkhakhni
// Version     : V1.0
// Copyright   : Nothing to be mentioned.
// Description : Read data of an array of Employees.
//============================================================================

#include <iostream> // for cin, cout objects declaration.
#include <string>   // to use the 'string' class, data type.
using namespace std;// for cin, cout definition.

//#################################################################//
class Employee      // class definition.
{
private:
	int number;
	string name;
	
public: 
	// ctor.
	Employee() : number(1000), name("Mohammed") {}
	
	// read the employee's data.
	void setData()
	{
		cout << "     Enter employee number: ";
		cin >> number;
		
		if(number <= 0)
		{
			cout << "Invalid number.\n";
			exit(1);
		}
		
		cin.ignore();
		cout << "     Enter employee name:   ";
		getline(cin, name);
	}
	
	
	// display it.
	void getData() const
	{
		cout << "Employee's Data:\n"
			 << "\tnumber: " << number << '\n'
			 << "\tname:   " << name << '\n';
	}
};
//#################################################################//

int main()
{
	// define the array of employees.
	short LIM = 5;
	Employee emp[LIM];
	
	
	// read their data.
	for(int i = 0; i < LIM; i++)
	{
		emp[i].setData();
		cout << "\n";
	}
	
	// display it.
	for(int i = 0; i < LIM; i++)
	{
		emp[i].getData();
		cout << "\n";
	}
	
	// indicates a succesful execution.
	return 0;
}



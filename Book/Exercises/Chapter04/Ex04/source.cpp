/* *
 * Subject: Simulate an employee as a structure. 
 * 
 * Date: December 12, 2023
 * 
 * Author: Alsayed-Aldkhakhni
 * 
 * Last modification: July 7, 2024
 * 
 * */

#include <iostream> // for objects cin and cout declaration.
using namespace std;// for their definition.

struct Employee     // structure tag.
{
	int number;
	float compensation;
};


int main()
{
	// declare 3 variables of type Employee.
	Employee emp1, emp2, emp3;
	
	cout << "Enter data of 3 employees:\n";
	
	cout << "Employee #" << 1 << ":\n"
		 << "    Enter employee number: ";
	cin >> emp1.number;
	
	cout << "    Enter his compensation: ";
	cin >> emp1.compensation;
	
	// validate the input.
	if(emp1.compensation < 0 || emp1.number <= 0)
	{
		cout << "Invalid value(s) entered.\n";
		exit(1);
	}
	
	cout << "\n\n";
	
	cout << "Employee #" << 2 << ":\n"
		 << "    Enter employee number: ";
	
	cin >> emp2.number;
	
	cout << "    Enter his compensation: ";
	cin >> emp2.compensation;
	
	// validate the input.
	if(emp2.compensation < 0 || emp2.number <= 0)
	{
		cout << "Invalid value(s) entered.\n";
		exit(1);
	}

	cout << "\n\n";
	
	cout << "Employee #" << 3 << ":\n"
		 << "    Enter employee number: ";
	
	cin >> emp3.number;
	
	cout << "    Enter his compensation: ";
	cin >> emp3.compensation;
	
	// validate the input.
	if(emp3.compensation < 0 || emp3.number <= 0)
	{
		cout << "Invalid value(s) entered.\n";
		exit(1);
	}

	cout << "\n\n";
	
	// display the data of each employee.
	cout << "Their data:\n"
		 << "   Employee #1:\n"
		 << "        Number:        " << emp1.number << "\n"
		 << "        compensation: $" << emp1.compensation << "\n\n";
		 
	cout << "   Employee #2:\n"
		 << "        Number:        " << emp2.number << "\n"
		 << "        compensation: $" << emp2.compensation << "\n\n";	 
		 
	cout << "   Employee #3:\n"
		 << "        Number:        " << emp2.number << "\n"
		 << "        compensation: $" << emp3.compensation << "\n\n";
	
	// indicates a successful execution.
	return 0;
}
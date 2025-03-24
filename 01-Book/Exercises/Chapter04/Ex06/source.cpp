/* *
 * Subject: Employee type as enum.
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

enum etype { laborer, secretary, manager, accountant, executive, researcher };

int main()
{
	char charEmpType;
	etype empType;
	
	// read the type from the user.
	cout << "Enter employee type (first letter only)\n"
			"   laborer, secretary, manager,\n"
			"   accountant, executive, researcher): ";
	
	cin >> charEmpType;
	
	// store the type based on the char.
	switch(charEmpType)
	{
	case 'l':
		empType = laborer;
		break;
		
	case 's':
		empType = secretary;
		break;
		
	case 'm':
		empType = manager;
		break;
		
	case 'a':
		empType = accountant;
		break;
		
	case 'e':
		empType = executive;
		break;
		
	case 'r':
		empType = researcher;
		break;
		
	default:
		cout << "Invalid value entered.\n";
		exit(1);
	}
	
	cout << "\n";
	
	// display the type based on the enum.
	switch(empType)
	{
	case laborer:
		cout << "Employee type is laborer.\n";
		break;
		
	case secretary:
		cout << "Employee type is secretary.\n";
		break;
		
	case manager:
		cout << "Employee type is manager.\n";
		break;
		
	case accountant:
		cout << "Employee type is accountant.\n";
		break;
		
	case executive:
		cout << "Employee type is executive.\n";
		break;
		
	case researcher:
		cout << "Employee type is researcher.\n";
		break;
	}
	
	return 0;
}
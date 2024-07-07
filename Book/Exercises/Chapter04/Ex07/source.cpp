/* *
 * Subject: Modeling an employee with Employee structure.
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

//////////////////////////////////////////////
// hiring date.
struct Date         // structure tag.
{
	short day;
	short month;
	short year;
};

// employee type.
enum etype { laborer, secretary, manager,
	         accountant, executive, researcher };

// model the employee entity.
struct Employee     // structure tag.
{
	int number;
	float compensation;
	Date hiringDate;
	etype type;
};
//////////////////////////////////////////////


int main()
{
	// declare 3 objects of type Employee.
	Employee emp1, emp2;
	char dummy, charEmpType;
	
	cout << "Enter data of 2 employees:\n";
	
	cout << "Employee #" << 1 << ":\n"
		 << "    Enter employee number: ";
	cin >> emp1.number;
	
	cout << "    Enter his compensation: ";
	cin >> emp1.compensation;
	
	// read the date.
	cout << "    Enter hiring date[mm/dd/yy]: ";
	cin >> emp1.hiringDate.month >> dummy >> emp1.hiringDate.day >> dummy >> emp1.hiringDate.year;
	
	// simple validation.
	if(emp1.hiringDate.year <= 0 || (emp1.hiringDate.day <= 0  || emp1.hiringDate.day > 31) ||
			                         (emp1.hiringDate.month <= 0 || emp1.hiringDate.month > 12))
	{
		cout << "Invalid value(s) entered for the date.\n";
		exit(1);
	}
	
	// read the type from the user.
	cout << "    Enter employee type (first letter only)\n"
			"       laborer, secretary, manager,\n"
			"       accountant, executive, researcher): ";
	
	cin >> charEmpType;
	
	// store the type based on the char.
	switch(charEmpType)
	{
	case 'l':
		emp1.type = laborer;
		break;
		
	case 's':
		emp1.type = secretary;
		break;
		
	case 'm':
		emp1.type = manager;
		break;
		
	case 'a':
		emp1.type = accountant;
		break;
		
	case 'e':
		emp1.type = executive;
		break;
		
	case 'r':
		emp1.type = researcher;
		break;
		
	default:
		cout << "Invalid value entered.\n";
		exit(1);
	}
	
	cout << "\n\n";
	
	////////////////////////////////////////////////////////////////////////////
	// 2nd employee.

	cout << "Employee #" << 2 << ":\n"
		 << "    Enter employee number: ";
	cin >> emp2.number;
	
	cout << "    Enter his compensation: ";
	cin >> emp2.compensation;
	
	// read the date.
	cout << "    Enter hiring date[mm/dd/yy]: ";
	cin >> emp2.hiringDate.month >> dummy >> emp2.hiringDate.day >> dummy >> emp2.hiringDate.year;
	
	// simple validation.
	if(emp2.hiringDate.year <= 0 || (emp2.hiringDate.day <= 0  || emp2.hiringDate.day > 31) ||
									 (emp2.hiringDate.month <= 0 || emp2.hiringDate.month > 12))
	{
		cout << "Invalid value(s) entered for the date.\n";
		exit(1);
	}
	
	// read the type from the user.
	cout << "    Enter employee type (first letter only)\n"
			"       laborer, secretary, manager,\n"
			"       accountant, executive, researcher): ";
	
	cin >> charEmpType;
	
	// store the type based on the char.
	switch(charEmpType)
	{
	case 'l':
		emp2.type = laborer;
		break;
		
	case 's':
		emp2.type = secretary;
		break;
		
	case 'm':
		emp2.type = manager;
		break;
		
	case 'a':
		emp2.type = accountant;
		break;
		
	case 'e':
		emp2.type = executive;
		break;
		
	case 'r':
		emp2.type = researcher;
		break;
		
	default:
		cout << "Invalid value entered.\n";
		exit(1);
	}
	
	cout << "\n\n";
	
	// displaying the data.
	//***************************************************************************//
	// 1st employee.
	cout << "Their data:\n"
		 << "   Employee #1:\n"
		 << "        Number:         " << emp1.number << "\n"
		 << "        compensation:   $" << emp1.compensation << "\n"
		 << "        hiring date :   " << emp1.hiringDate.month << '/' << emp1.hiringDate.day << '/' << emp1.hiringDate.year << "\n"
		 << "        employee type:  ";

	// print the type.
	switch(emp1.type)
		{
		case laborer:
			cout << "laborer.\n";
			break;
			
		case secretary:
			cout << "secretary.\n";
			break;
			
		case manager:
			cout << "manager.\n";
			break;
			
		case accountant:
			cout << "accountant.\n";
			break;
			
		case executive:
			cout << "executive.\n";
			break;
			
		case researcher:
			cout << "researcher.\n";
			break;
		}

	cout << "\n";
	
	// 2nd employee.
	cout << "   Employee #2:\n"
		 << "        Number:         " << emp2.number << "\n"
		 << "        compensation:   $" << emp2.compensation << "\n"
		 << "        hiring date :   " << emp2.hiringDate.month << '/' << emp2.hiringDate.day << '/' << emp2.hiringDate.year << "\n"
		 << "        employee type:  ";

	// print the type.
	switch(emp2.type)
	{
	case laborer:
		cout << "laborer.\n";
		break;
		
	case secretary:
		cout << "secretary.\n";
		break;
		
	case manager:
		cout << "manager.\n";
		break;
		
	case accountant:
		cout << "accountant.\n";
		break;
		
	case executive:
		cout << "executive.\n";
		break;
		
	case researcher:
		cout << "researcher.\n";
		break;
	}
	
	return 0;
}


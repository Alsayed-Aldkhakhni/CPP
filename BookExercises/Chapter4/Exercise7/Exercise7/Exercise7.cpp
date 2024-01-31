/*
 * Subject: Improve the capabilities of 'Employee' struct.
 *
 * Date: December 12, 2023
 *
 * Author: Alsayed Aldkhalkhni 
 */


// Preprocessor directives instruct the compiler's preprocessor to include the entire content
// of these two header files, iostream and iomanip, into the current source file.
#include <iostream> 			// Contains the declarations of 'cin' and 'cout'.
#include <iomanip>  			// Contains the declarations of 'setw' and 'setfill'.

using namespace std; 			// Provides access to the definitions of cin, cout, setw, and setfill.

								// create an enumeration with its possible values.
enum etype { laborer, secretary, manager, accountant, executive, researcher };

//*************************************************
struct date 					// hiring date.
{
	int day; 					// members.
	int month;
	int year;
};
//*************************************************
struct Employee // structure definition, tag.
{								 // members.
	unsigned int employeeNumber; // since the number of employee is positive.
	float employeeCompensation;  // Compensation may be has fractional part.
	date employeementDate;       // date of hiring.
	etype employeeTitle; 		 // title of the employee.
};
//************************************************
int main()
{
	Employee emp{}; 			// taking a variable of type 'Employee'.

	cout << "Enter employee's data....\f";

	int num = 0;				// these two variables to hold the data before assigning.
	float comp = 0;
								// prompt message, tells the user what to do.
	cout << "\tEnter employee number: "; 
	cin >> num;					// get the employee's number.

								// check the input's validation.
	emp.employeeNumber = num > 0 ? num : 0;

	cout << "\tEnter employee compensation: ";
	cin >> comp;				// get the compensation of the employee.
								// check the input's validation.
	emp.employeeCompensation = comp > 0 ? comp : 0;

								// these variables is to check the date values before assigning.
	int dd = 0, mm = 0, yy = 0; char ch = '0';

								// prompt message, tells the user what to do.
	cout << "\tEnter the date in following format mm/dd/yy: ";
	cin >> mm >> ch >> dd >> ch >> yy; // get values.

								// check the validation.
	emp.employeementDate.month = mm >= 1 && mm <= 12 ? mm : 0;
	emp.employeementDate.day = dd >= 1 && dd <= 31 ? dd : 0;
	emp.employeementDate.year = yy > 0 ? yy : 0;

	char chosen = '0'; 			// to hold the user's input.

								// prompt message tells the user the avaliable titles.
	cout << "\tEnter employee type (first letter only).."
			"\n\tlaborer, secretary,\n\tmanager, accountant,\n\texecutive, researcher: ";

	cin >> chosen; 				// take the input.
	chosen = tolower(chosen); 	// convert it to lower case.

	switch (chosen) 			// checking.
	{
		case 'l':
			emp.employeeTitle = laborer;
			break;

		case 's':
			emp.employeeTitle = secretary;
			break;

		case 'm':
			emp.employeeTitle = manager;
			break;

		case 'a':
			emp.employeeTitle = accountant;
			break;

		case 'e':
			emp.employeeTitle = executive;
			break;

		case 'r':
			emp.employeeTitle = researcher;
			break;

		default: 				// if the user's input wrong.
			cout << "Out of range.\f";
	}

	cout << "\n\n";				// separate the input and the output.

	cout << "Employee's data:\f"
	 	 << "\tEmployee number: " << emp.employeeNumber << '\f'
		 << "\tEmployee compensation: $" << emp.employeeCompensation << '\f';

	cout << "\tHiring date: "
		 << setfill('0') << setw(2) << emp.employeementDate.month << '/' << setw(2)
		 << emp.employeementDate.day << '/' << setw(4) << emp.employeementDate.year << "\n\t";


	switch (emp.employeeTitle) // print the employee's title based on user's input.
	{
		case 0:
			cout << "Employee type is laborer\f";
			break;

		case 1:
			cout << "Employee type is secretary\f";
			break;

		case 2:
			cout << "Employee type is manager\f";
			break;

		case 3:
			std::cout << "Employee type is accountant\f";
			break;

		case 4:
			cout << "Employee type is executive\f";
			break;

		case 5:
			cout << "Employee type is researcher\f";
			break;
	}

	return 0; 				// indicates the operating system that the program executed successfully.
}
/*
 * Subject: Simulate an employee using class Employee.
 * 
 * Date: January 14, 2024
 * 
 * Author: Alsayed-Aldkhakhni
 * 
 * Last modification: July 9, 2024
 * */


#include <iostream> // for the declaration of cin, cout objects.
#include <iomanip>  // for setw(), setfill() library functions.
#include "Date.h"   // the reference of 'Date' data type.
using namespace std;// for the definition of cin, cout.
//####################################################################################//
enum eType{laborer, secretary, manager, accountant, executive, researcher};

class Employee      // class definition.
{
private:
	int number;
	double salary;
	Date hiringDate;
	eType type;
	
public:
	// ctor.
	Employee() : number(1), salary(0.0), type(laborer) {}
	
	// his number.
	void setNumber(int num)
	{
		if(num <= 0)
		{
			cout << "Invalid employee number.\n";
			exit(1);
		}
		
		number = num;
	}
	
	// how much does he take?
	void setSalary(double sal)
	{
		if(sal <= 0)
		{
			cout << "Invalid employee salary.\n";
			exit(1);
		}
		
		salary = sal;
	}
	
	// what does he work in my company??
	void setType(char tp)
	{
		switch(tp)
		{
		case 'l':
			type = laborer;
			break;
			
		case 's':
			type = secretary;
			break;
			
		case 'm':
			type = manager;
			break;
			
		case 'a':
			type = accountant;
			break;
			
		case 'e':
			type = executive;
			break;
			
		case 'r':
			type = researcher;
			break;
			
		default:
			cout << "Invalid employee type.\n";
			exit(1);			
		}
	}
	
	// read the date.
	void setHiringDate() { hiringDate.setDate(); }
	
	// read the employee's data from the user.
	void setData()
	{
		// read the employee's number.
		int num;
		cout << "   Enter employee number: ";
		cin >> num;
		setNumber(num);
		
		// his salary.
		double sal;
		cout << "   Enter employee salary: ";
		cin >> sal;
		setSalary(sal);
		
		// the 1st deployement date.
		setHiringDate();
		
		// his job at the company.
		char tp;
		cout << "   Enter 1st letter only [laborer, secretary, manager,\n"
				"                          accountant, executive, researcher]: ";
		cin >> tp;
		setType(tp);
	}
	
	// display the whole data.
	void getData() const 
	{
		cout << "Employee's data.\n";
		cout << "     Number:        " << number << "\n";
		cout << "     Salary:       $" << setiosflags(ios::fixed) << setprecision(2) << salary << '\n';
		cout << "     Hiring date:   "; hiringDate.getDate();
		cout << "     employee type: ";
		
		switch(type)
		{
		case 0:
			cout << "laborer."; break;
			
		case 1:
			cout << "secretary."; break;
			
		case 2:
			cout << "manager."; break;
			
		case 3:
			cout << "accountant."; break;
			
		case 4:
			cout << "executive."; break;
			
		case 5:
			cout << "researcher."; break;
		}
		
		cout << "\n\n";
	}
};
//####################################################################################//

int main()
{
	// instantiate 2 objects of that class.
	Employee emp1, emp2;
	
	// read their data.
	emp1.setData(); cout << "\n\n";
	emp2.setData();
	
	// display it.
	emp1.getData();
	emp2.getData();
	
	// indicates a successful execution.
	return 0;
}


/* *
 * Subject: Simulate an employee as a class. 
 * 
 * Date: January 12, 2023
 * 
 * Author: Alsayed-Aldkhakhni
 * 
 * Last modification: July 7, 2024
 * 
 * */

#include <iostream> // for objects cin and cout declaration.
using namespace std;// for their definition.
////////////////////////////////////////////////////////////////
class Employee
{
private:
	int number;
	double compensation;
	
public:
	Employee() : number(0), compensation(0.0) {}
	
	void setNumber(int num)
	{
		if(num <= 0)
		{
			cout << "Invalid employee number.\n";
			exit(1);
		}
		
		number = num;
	}
	
	void setCompensation(double comp)
	{
		if(comp <= 0)
		{
			cout << "Invalid compensation.\n";
			exit(1);
		}
		
		compensation = comp;
	}
	
	int getNumber() const { return number; }
	double getCompensation() const { return compensation; }
	
	void setData()
	{
		int x; double y;
		
		cout << "    Enter employee number: ";
		cin >> x; setNumber(x);
		
		cout << "    Enter employee compensation: ";
		cin >> y; setCompensation(y);
	}
	
	void getData() const
	{
		cout << "    Employee number:        " << getNumber() << '\n'
			 << "    Employee compensation: $" << getCompensation() << "\n\n";
	}
};
////////////////////////////////////////////////////////////////
int main()
{
	// declare 3 variables of type Employee.
	Employee emp1, emp2;
	
	// read the data.
	emp1.setData();
	cout << "\n\n";
	emp2.setData();
	
	cout << "\n\n\n";	
	
	// display the data.
	emp1.getData();
	emp2.getData();
	
	// indicates a successful execution.
	return 0;
}
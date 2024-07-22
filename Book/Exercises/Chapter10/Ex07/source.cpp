/*
 * Subject: Ordering an array of pointers of Person objects.
 *
 * Date: July 22, 2024
 * 
 * Author: Alsayed-Aldkhakhni
 *
 * Last modification: July 22, 2024
 *
 * */

#include <iostream> // for the declaration of cin, cout objects.
using namespace std;// for their definition.
//#################################################################//
class Person
{
private:
	string name;
	float salary;

public:
	Person() : salary(0.0), name("") {cin.ignore(1);}

	void setData()
	{
		cout << "   Enter Person's name:   ";
		getline(cin, name);

		cout << "   Enter Person's salary: ";
		cin >> salary;

		if(salary <= 0)
		{
			cout << "Invalid salaryensation.\n";
			exit(1);
		}
	}

	void getData() const 
	{
		cout << "   Person's name:    " << name << "\n"
		     << "   Person's salary: $" << salary << "\n";
	}

	float getSalary() const { return salary;}
};
//#################################################################//

// functions' prototypes.
void sort(Person**, int);
void display(Person**, int);

int main()
{
	Person* pers[10];
	int numOfPers = 0;
	char ans;

	// read the data from the user.
	for(int i = 0;; i++)
	{
		pers[i] = new Person;
		pers[i]->setData();
		numOfPers++;

		cout << "\nOne more?(y, n): ";
		cin >> ans;

		if(ans != 'y') break;
	}

	// sort then display.
	sort(pers, numOfPers);
	display(pers, numOfPers);
	
	// release the resources. [memory].
	for(int i = 0; i < numOfPers; i++)
		delete pers[i];

	// indicates a successful execution.
	return 0;
}


// functions' bodies.
// p1 p2 p3 p4
// 0  1  2  3
void sort(Person** persPtr, int numOfPers)
{
	for(int i = 0; i < numOfPers-1; i++)
	{
		for(int j = i+1; j < numOfPers; j++)
		{
			// Don't forget: -> takes precedece over *
			if((*(persPtr+i))->getSalary() > (*(persPtr+j))->getSalary())
			{
				Person* temp = *(persPtr+i);
				*(persPtr+i) = *(persPtr+j);
				*(persPtr+j) =   temp;
			}
		}
	}
}


void display(Person** persPtr, int numOfPers)
{
	for(int i = 0; i < numOfPers; i++)
	{
		(*(persPtr+i))->getData();
		cout << "=============================\n";
	}
}


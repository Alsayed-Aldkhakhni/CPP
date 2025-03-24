/*
 * Subject: Simulate date using class Date .
 * 
 * Date: January 14, 2024
 * 
 * Author: Alsayed-Aldkhakhni
 * 
 * Last modification: July 9, 2024
 * */


#include <iostream> // for the declaration of cin, cout objects.
#include <iomanip>  // for setw(), setfill() library functions.
using namespace std;// for their, cin and cout, definition.
//######################################################################################//
const short monthsEnds[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
//--------------------------------------------------------------------------------------//
class Date // class definition.
{
private:   // inaccessable members.
	int year;
	int month;
	int day;

	bool isLeap(int y) { return (y % 100 != 0 && y % 4 == 0) || (y % 400 == 0); }
	
public:
	// constructors.
	Date() : year(1), month(1), day(1) {}
	Date(int m, int d, int y) { setMonth(m); setDay(d); setYear(y);	}
	
	//////////////////////////////// Mutators ////////////////////////////
	void setYear(int y) // year setter.
	{
		if(y <= 0 || y >= 3000)
		{
			cout << "Invalid year.\n";
			exit(1);
		}
		
		year = y;
	}
	
	void setMonth(int m) // month setter.
	{
		if(m <= 0 || m > 12)
		{
			cout << "Invalid month.\n";
			exit(1);
		}
		
		month = m;
	}

	void setDay(int d)   // day setter.
	{
		if(d <= 0 || d > 31)
		{
			cout << "Invalid day.\n";
			exit(1);
		}
		
		day = d;
	}
	///////////////////////////////////////////////////////////////////////
	// read date from the user.
	void setDate()
	{
		int d, m, y; char dummy;
		
		cout << "Enter date as [mm/dd/yy]: ";
		cin >> m >> dummy >> d >> dummy >> y;
		
		setMonth(m);
		setYear(y);
		setDay(d);
		
		if(isLeap(y) == true) // if it is a leap.
		{
			if(m == 2)		  // 1st, check the 2nd month.
			{
				if(d <= monthsEnds[d] + 1)
					day = d;
				else
				{
					cout << "Invalid day, it's a leap year.\n";
					exit(1);
				}
			}
			else              // otherwise check using the normal ends.
			{
				if(d <= monthsEnds[d])
					day = d;
				else
				{
					cout << "Exceeded the limit days for this month.\n";
					exit(1);
				}
					
			}
		}
		else // not a leap.
		{
			if(d <= monthsEnds[m])
			{
				month = m;
				day   = d;
				year  = y;
			}
			else
			{
				cout << "Exceeded the limit days for this month.\n";
				exit(1);
			}
		}
	}
	
	// display the date.
	void getDate() const
	{
		cout << setfill('0') << setw(2) << month << "/" << setw(2) << day << "/" << setw(4) << year << "\n\n";
	}
};
//######################################################################################//

int main()
{
	// instantiate an object.
	Date date1;
	
	// test the date.
	for(int i = 0; i < 5; i++)
	{
		date1.setDate();
		date1.getDate();
	}
	
	// indicates a successful execution.
	return 0;
}







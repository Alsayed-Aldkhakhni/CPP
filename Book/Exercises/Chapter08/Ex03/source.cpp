/*
 * Subject: Add two objects of type Time using (+) operator.
 * 
 * Date: January 15, 2024
 * 
 * Author: Alsayed-Aldkhakhni
 * 
 * Last modification: July 16, 2024
 * 
 * */

#include <iostream> // for the declaration of objects cin, cout.
#include <iomanip>  // for setw, setfill
using namespace std;// for their definition.
///////////////////////////////////////////////////////////////////////////////////////////////////
class Time          // class definition.
{
private:            // data members.
	int hours;
	int minutes;
	int seconds;
	
public:             // member functions.
	Time() : hours(0), minutes(0), seconds(0) {}
	Time(int h, int m, int s) { setHours(h); setMinutes(m); setSeconds(s); }
	
	///////////////////////////data members handlers./////////////////////////////////
	void setHours(int h) 
	{
		if(h <= 12 && h > 0)
			hours = h;
		else
		{
			cout << "Invalid value for hours.\n";
			exit(1);
		}
	}
	
	void setMinutes(int m) 
	{
		if(m <= 59 && m >= 0)
			minutes = m;
		else
		{
			cout << "Invalid value for minutes.\n";
			exit(1);
		}
	}
	
	void setSeconds(int s) 
	{
		if(s <= 59 && s >= 0)
			seconds = s;
		else
		{
			cout << "Invalid value for seconds.\n";
			exit(1);
		}
	}
	/////////////////////////////////////////////////////////////////////////////////
	
	Time operator+(Time& t2)
	{
		// add the values.
		int h = hours   + t2.hours;
		int m = minutes + t2.minutes;
		int s = seconds + t2.seconds;
		
		// handling the carry.
		if(s >= 60)
		{
			m += s / 60;
			s  = s - (s / 60) * 60; 
		}
		
		if(m >= 60)
		{
			h += m / 60;
			m  = m - (m / 60) * 60; 
		}
		
		// return nameless object back.
		return Time(h, m, s);
	}

	void display() const
	{ cout << setfill('0') << setw(2) << hours << ":" << setw(2) << minutes << ":"<< setw(2) << seconds << '\n';}
};
///////////////////////////////////////////////////////////////////////////////////////////////////////


int main()
{
	// instantiate 3 objects.
	Time t1(5, 40, 30), t2(6, 21, 35), t3;
	
	// add the 1st two.
	t3 = t1 + t2;
	
	// diplay all the objects.
	cout << "Time1:   "; t1.display();
	cout << "Time2:   "; t2.display();
	cout << "Time1+2: "; t3.display();
	
	// indicates a successful execution.
	return 0;
}


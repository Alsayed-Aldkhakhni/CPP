/*
 * Subject: Overload unary operators pre-fix and post-fix.
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

	
	Time operator++()
	{
		if(seconds < 59)
			seconds++;
		else
		{
			seconds = 0;
			
			if(minutes < 59)
				minutes++;
			else
			{
				hours++;
				minutes = 0;
			}
		}
		
		return Time(hours, minutes, seconds);
	}
	
	Time operator++(int)
	{
		Time temp(hours, minutes, seconds);
		
		if(seconds < 59)
			seconds++;
		else
		{
			seconds = 0;
			
			if(minutes < 59)
				minutes++;
			else
			{
				hours++;
				minutes = 0;
			}
		}
		
		return temp;
	}
	
	Time operator--()
	{
		if(seconds > 0)
			seconds--;
		else
		{			
			if(minutes > 0)
			{
				minutes--;
				seconds = 58;
			}
			else
			{
				hours--;
				minutes = 58;
				seconds = 58;
			}
		}
		
		return Time(hours, minutes, seconds);
	}
	
	Time operator--(int)
	{
		Time temp(hours, minutes, seconds);
		
		if(seconds > 0)
			seconds--;
		else
		{			
			if(minutes > 0)
			{
				minutes--;
				seconds = 58;
			}
			else
			{
				hours--;
				minutes = 58;
				seconds = 58;
			}
		}
		
		return temp;
	}	
	
	void display() const
	{ cout << setfill('0') << setw(2) << hours << ":" << setw(2) << minutes << ":"<< setw(2) << seconds << '\n';}
};
///////////////////////////////////////////////////////////////////////////////////////////////////////


int main()
{
	// instantiate 4 objects.
	Time t1(5, 40, 55), t2(6, 21, 5), t3, t4;
	

	for(int i = 0; i < 10; i++)
	{
		t1++;
		t2--;
		
		cout << "\n-----------------\n";
		cout << "t1: "; t1.display();
		cout << "t2: "; t2.display();
	}
	
	
	t3 = ++t1;
	t4 = --t2;
	
	cout << "t3: "; t3.display();
	cout << "t4: "; t4.display();
	
	// indicates a successful execution.
	return 0;
}


/*
 * Subject: Carry out arithmetic operations on Time objects.
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
//#####################################################################################//
class Time          // class definition.
{
private:            // data members.
	int hours;
	int minutes;
	int seconds;
	
public:             // member functions.
	Time() : hours(0), minutes(0), seconds(0) {}
	Time(int h, int m, int s) { setHours(h); setMinutes(m); setSeconds(s); }

	// members' handerls. 
	////////////////////////////////////////////////////////////////
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
	////////////////////////////////////////////////////////////////
	
	// +, - operators.
	///////////////////////////////////////////////////////////////

	// plus operator.
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
	
	// minus operator.
	Time operator-(Time& t1)
	{
		int secs1 = hours * 3600 + minutes * 60 + seconds;
		int secs2 = t1.hours * 3600 + t1.minutes * 60 + t1.seconds;
		
		if(secs1 < secs2)
		{
			cout << "There is not negative time.\n";
			exit(1);
		}
		
		secs1 = secs1 - secs2;
		
		int h = secs1 / 3600;
		int s = (secs1 - h*3600) % 60;
		int m = (secs1 - h*3600 - s) / 60;
		
		return Time(h, m, s);
	}	
	///////////////////////////////////////////////////////////////
	
	// ++ operator. [prefix, postfix].
	///////////////////////////////////////////////////////////////

	// prefix.
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
	
	// postfix.
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
	///////////////////////////////////////////////////////////////
	
	// -- operator. [prefix, postfix].
	///////////////////////////////////////////////////////////////

	// pre.
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
	
	// post.
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
	/////////////////////////////////////////////////////////////////////

	// multiplication.
	Time operator*(float scale)
	{
		if(scale <= 0 || scale > 1)
		{
			cout << "Invalid scaling value.\n";
			exit(1);
		}
		
		int secs = (hours*3600 + minutes*60 + seconds) * scale;

		int h = secs / 3600;
		int m = ( secs - ((secs / 3600) * 3600) ) / 60;
		int s = secs - h*3600 - m*60;
		
		return Time(h, m, s);
	}
	/////////////////////////////////////////////////////////////////////

	// display the time in a good fromate.	
	void display() const
	{ 
		cout << setfill('0') << setw(2)
			 << hours << ":" << setw(2)
			 << minutes << ":"<< setw(2)
			 << seconds << '\n';
	}
	/////////////////////////////////////////////////////////////////////
};
//#####################################################################################//
int main()
{
	// instantiate five objects.
	Time t1(7, 40, 55), t2(3, 21, 5), t3, t4, t5;

	// carry out the calculation.
	t3 = t1 + t2;
	t4 = t1 - t2;
	t5 = t1 * 0.5;

	// display the results.
	cout << "t1: "; t1.display();
	cout << "t2: "; t2.display();	
	cout << "\n\n";
	cout << "t3: "; t3.display();
	cout << "t4: "; t4.display();
	cout << "t5: "; t5.display();
	
	// indicates a successful execution.
	return 0;
}


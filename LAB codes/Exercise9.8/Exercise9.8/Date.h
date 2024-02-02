#pragma once	// preprocessor wrapper prevents the redefinition of header file.
class Date		// class definition.
{
				// a friend to print the the date normally without (.)
friend void printDate(Date);

private:		// data members.
	unsigned short year;
	unsigned short month;
	unsigned short day;

				// this method is private since we won't use it directly.
	bool isLeap(unsigned short); 

public:			// member functions.

				// default argument ctor.
	Date(unsigned short Y = 1900, unsigned short M = 1, unsigned short D = 1); 

				// go to next day.
	void nextDay(); 
};

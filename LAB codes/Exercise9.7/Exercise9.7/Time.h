#pragma once	// preprocessor wrapper prevents the redefinition of the header file.
class Time		// class specifier.
{
				// a friend method to print the time normally.
friend void print(Time); 

private:		// data members.
	unsigned short hours;
	unsigned short minutes;
	unsigned short seconds;

public:			// member functions.
				// default argument ctor.
	Time(unsigned short h = 1, unsigned short m = 1, unsigned short s = 1); 
	void tick();// to increment the seconds by 1
};
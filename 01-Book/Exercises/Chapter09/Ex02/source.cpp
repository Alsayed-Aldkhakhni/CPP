/*
 * Subject: A protected string class that stores only what fits to its internal size.
 * 
 * Date: July 20, 2024
 * 
 * Author: Alsayed-Aldkhakhni
 * 
 * Last modification: July 20, 2024
 * 
 * */

#include <iostream> // for the declaration of cin, cout objects.
#include <cstring>  // for strlen, strcpy library functions.
using namespace std;// for the definition of cin, cout.

//########################################################################//
class String
{
protected:
	enum { SZ = 80 };
	char str[SZ];
	
public:
	String() { str[0] = '\0'; }
	String(const char s[]) { strcpy(str, s); }
	
	void display() const { cout << str << '\n'; }
	operator char*() { return str; }
};
//########################################################################//
class Pstring : public String
{
public:
	Pstring(const char s[])
	{
		if(strlen(s) < SZ)
			String(s);
		else
		{
			for(int i = 0; i < SZ; i++)
				str[i] = s[i];
			
			str[SZ] = '\0';
		}
	}
};
//########################################################################//


int main()
{
	Pstring pstr1 = "It doesn't matter who we are, what matter's our plan.\n"
			        "No one cared who i was till i put on the mask.";
	
	pstr1.display();

	return 0;
}


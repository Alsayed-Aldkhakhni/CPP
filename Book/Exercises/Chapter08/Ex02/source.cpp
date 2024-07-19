/*
 * Subject: Concatinate 2 C-string objects using overloaded (+), (+=) operators.
 *
 * Date: July 14, 2024
 *
 * Author: Alsayed-Aldkhakhni
 *
 * Last modification: July 14, 2024
 * */

#include <iostream> // for cin, cout objects declaration.
#include <cstring>  // for strlen, strcpy library functions.
using namespace std;// the definition of cin, cout.

//##########################################################################//
class String // class definition.
{
private:     // statement length.
	enum{LIM = 100};
	char str[LIM];
	
public:
	// ctors.
	String() { strcpy(str, "\0"); }
	String(const char s[])
	{
		if(strlen(s) < LIM)
			strcpy(str, s);
		else
		{
			cout << "Exceeded the limits.\n";
			exit(1);
		}
	}
	
	
	void display() const { cout << str << "\n"; }
	
	// (+) operator.
	String operator+(String& s)
	{
		if(strlen(s.str) + strlen(str) >= LIM)
		{
			cout << "Exceeded the limits.\n";
			exit(1);
		}
		
		char temp[LIM];
		strcpy(temp, str);
		strcat(temp, s.str);
		
		return String(temp);
	}
	
	// (+=) operator.
	String operator+=(String& s)
	{
		if(strlen(s.str) + strlen(str) >= LIM)
		{
			cout << "Exceeded the limits.\n";
			exit(1);
		}
		
		strcat(str, s.str);
		
		return String(str);
	}
};
//##########################################################################//


int main()
{
	// 1st 2 Strings.
	String str1("You do not know "),
		   str2("what you don't know.");
	
	// 2nd 2.
	String str3("Disepline is doing what you hate to do,"),
		   str4(" but you do it as you love it.");
	
	// display before concatinating.
	cout << "str1: "; str1.display();
	cout << "str2: "; str2.display();
	cout << "----------------\n";
	cout << "str3: "; str3.display();
	cout << "str4: "; str4.display();
	cout << "----------------\n";

	String str5, str6;

	// concatinate.
	str5 = str1 + str2;
	str6 = str3 += str4;

	// display after.
	cout << "str5: "; str5.display();
	cout << "str6: "; str6.display();
	
	// indicates a sucessful execution, cause the function to be poped off the stack.
	return 0;
}

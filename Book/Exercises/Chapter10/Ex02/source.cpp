/*
 * Subject: Uppering a C-string.
 *
 * Date: July 21, 2024
 *
 * Author: Alsayed-Aldkhakhni
 *
 * Last modification: July 21, 2024
 *
 * */

#include <iostream> // for the declaration of cin, cout objects.
#include <cstring>  // for the strlen() library function.
using namespace std;// for their, cin and cout, definition.

//########################################################//
class String
{
private:
	char* str;
public:
	String(const char* s)
	{
		int length = strlen(s);
		str = new char[length+1];
		strcpy(str, s);
	}

	void display() const { cout << str << endl; }
	void upIt()
	{
		for(int i = 0; i < strlen(str); i++)
		    *(str+i) = toupper(*(str+i));
	}

	~String() { delete[] str; }
};
//########################################################//

int main()
{
	String s1 = "You do not know what you don't know.";

	s1.display();
	s1.upIt();
	s1.display();
	
	// indicates a successful execution, poping the function off the stack.
	return 0;
}

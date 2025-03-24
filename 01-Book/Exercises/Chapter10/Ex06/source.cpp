/*
 * Subject: Compare 2 C-strings.
 *
 * Date: July 22, 2024
 *
 * Author: Alsayed-Aldkhakhni
 *
 * Last modification: July 22, 2024
 *
 * */

#include <iostream> // for the declaration of cin, cout objects.
#include <cstring>  // for the library function strlen().
using namespace std;// for the definition of cin, cout.

short compstr(const char*, const char*);

int main()
{

	short myFunction = compstr("Alsayed", "Ali");
	short builtInOne = strcmp("Alsayed", "Ali");

	cout << "My function:  " << myFunction << "\n"
	     << "Built-in one: " << builtInOne << "\n";

	cout << "==========================\n";

	myFunction = compstr("Mostafa", "Khalid");
	builtInOne = strcmp("Mostafa", "Khalid");

	cout << "My function:  " << myFunction << "\n"
	     << "Built-in one: " << builtInOne << "\n";

	cout << "==========================\n";

	myFunction = compstr("Safia", "Rawan");
	builtInOne = strcmp("Safia", "Rawan");

	cout << "My function:  " << myFunction << "\n"
	     << "Built-in one: " << builtInOne << "\n";

	cout << "==========================\n";
	
	myFunction = compstr("Alsayed", "Alsayed");
	builtInOne = strcmp("Alsayed", "Alsayed");
	
	cout << "My function:  " << myFunction << "\n"
	     << "Built-in one: " << builtInOne << "\n";
	
	cout << "==========================\n";
	
	myFunction = compstr("Alsayed", "Khalid");
	builtInOne = strcmp("Alsayed", "Khalid");
	
	cout << "My function:  " << myFunction << "\n"	
	     << "Built-in one: " << builtInOne << "\n";
	
	cout << "==========================\n";


	return 0;
}

// function's body.
short compstr(const char* str1, const char* str2)
{
	short l1 = strlen(str1);
	short l2 = strlen(str2);

	l1 = l1 < l2 ? l1 : l2;
	short rslt = 0;

	for(short i = 0; i < l1; i++)
	{
		if(*(str1+i) < *(str2+i))
		{
			rslt = -1;
			break;
		}
		else if(*(str1+i) > *(str2+i))
		{
			rslt = 1;
			break;
		}
	}

	return rslt;
}

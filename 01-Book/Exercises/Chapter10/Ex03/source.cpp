/*
 * Subject: Ordering the pointers of the days of week.
 *
 * Date: July 22, 2024
 *
 * Author: Alsayed-Aldkhakhni
 *
 * Last modification: July 22, 2024
 *
 * */


#include <iostream> // for the declaration of cin, cout objects. 
#include <cstring>  // for the strcmp() library function. 
using namespace std;// for their definition.

// sort a list of pointers to arrays of characters.
void sort(const char**, int size);

int main()
{
	const int DAYS = 7;

	 //array of pointers to char
	const char* arrPtrs[DAYS] = { "Sunday", "Monday", "Tuesday",
		  		      "Wednesday", "Thursday",
		   		      "Friday", "Saturday"};

	for(int j=0; j<DAYS; j++)
		cout << arrPtrs[j] << ", ";

	sort(arrPtrs, DAYS);
	cout << "\n\n";

	for(int j=0; j<DAYS; j++)
		cout << arrPtrs[j] << ", ";

	cout << "\n\n";

	return 0;
}

// functions' defintion.
void sort(const char** cArr, int size)
{
	void swap(const char**, const char**);

	// bubble sort techinque.
	for(int i = 0; i < size-1; i++)
		for(int j = i+1; j < size; j++)
			swap((cArr+i), (cArr+j));
}

void swap(const char** ch1, const char** ch2)
{
	if(strcmp(*ch1, *ch2) > 0)
	{
		const char* temp = *ch1;
		*ch1 = *ch2;
		*ch2 = temp;
	}
}

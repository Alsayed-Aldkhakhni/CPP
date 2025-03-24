/*
 * Subject: Sort an array of words.
 *
 * Date: July 29, 2024
 *
 * Author: Alsayed-Aldkhakhni
 *
 * Last modification: July 29, 2024
 *
 * */

// those are pre-processor directives to use methods and entities predefined in the language.
#include <iostream> // for the declaration of cin, cout.
#include <string>   // for the class string.
#include <algorithm>// for the sort algorithm.
#include <vector>   // for the vector template class.
using namespace std;// for the definition of cin, cout.

// functions' prototypes.
void readWords(vector<string>&);
void display(vector<string>&);

int main()
{
	vector<string> vWords;

	// read the words from the user.
	readWords(vWords);

	// display before.
	display(vWords);

	// sort the range of words.
	sort(vWords.begin(), vWords.end());

	// display after.
	display(vWords);

	// indicates a successful execution, popping off the stack.
	return 0;
}

// functions' definitions.
void readWords(vector<string>& vWords)
{
	string word;
	char ans;

	do
	{
		cout << "Enter a word: ";
		cin >> word;

		vWords.push_back(word);

		cout << "\n-->One more?(y, n): ";
		cin >> ans;

 	}while(ans == 'y');
}

void display(vector<string>& vWords)
{
	for(int i = 0; i < vWords.size(); i++)
		cout << vWords[i] << "    ";

	cout << "\n\n";
}





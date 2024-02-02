#pragma once				// preprocessor wrapper, forbids redefinition of the header file.
class SaveArray				// class definition, tag.
{
private:					// members data.
	static const unsigned SIZE = 100;
	int arr[SIZE];			// array of 100 integers.

public:
	SaveArray();			// default constructor to construct the object.
							// notice the syntax, return by reference will work in both '=' sides.
	int& operator[](int index); 
};
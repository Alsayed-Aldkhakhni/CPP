#include <iostream>
#include <set>
#include <algorithm>
#include <string>
#include <functional>

using namespace std;

class person
{
private:
	string lastName;
	string firstName;
	long phoneNumber;
public:
	person() : lastName("blank"), firstName("blank"), phoneNumber(0L)
	{}

	person(string lana, string fina, long pho) : lastName(lana), firstName(fina), phoneNumber(pho)
	{}

	friend bool operator<(const person&, const person&);
	friend bool operator==(const person&, const person&);

	void display() const
	{
	cout << endl << lastName << ",\t" << firstName
	     << "\t\tPhone: " << phoneNumber;
	}

	long get_phone() const { return phoneNumber; }
};
//--------------------------------------------------------------
//overloaded < for person class
bool operator<(const person& p1, const person& p2)
{
	if(p1.lastName == p2.lastName)
	return (p1.firstName < p2.firstName) ? true : false;
	return (p1.lastName < p2.lastName) ? true : false;
}
//--------------------------------------------------------------
//overloaded == for person class
bool operator==(const person& p1, const person& p2)
{
	return (p1.lastName == p2.lastName &&
	p1.firstName == p2.firstName ) ? true : false;
}
//--------------------------------------------------------------
//function object to compare persons using pointers
class comparePersons
{
public:
	bool operator() (const person* ptrP1, const person* ptrP2) const
	{ return (*ptrP1) < (*ptrP2); }
};

//--------------------------------------------------------------
//function object to display a person, using a pointer
class displayPerson
{
public:
	void operator() (const person* ptrP) const
	{ ptrP->display(); }
};

int main()
{
	multiset<person*, less<person*> > setPtrsPers;

	person* ptrP1 = new person("KuangThu",  "Bruce",   4157300);
	person* ptrP2 = new person("Deauville", "William", 8435150);
	person* ptrP3 = new person("Wellington","John",    9207404);
	person* ptrP4 = new person("Bartoski",  "Peter",   6946473);
	person* ptrP5 = new person("Fredericks","Roger",   7049982);
	person* ptrP6 = new person("McDonald",  "Stacey",  7764987);

	setPtrsPers.insert(ptrP1);
	setPtrsPers.insert(ptrP2);
	setPtrsPers.insert(ptrP3);
	setPtrsPers.insert(ptrP4);
	setPtrsPers.insert(ptrP5);
	setPtrsPers.insert(ptrP6);


//	multiset<person*, string, less<person> >::iterator sIte = setPtrsPers.begin(); 
//	multiset<person*, string, less<person> >::iterator eIte = setPtrsPers.end();
	//for_each(setPtrsPers.begin(),setPtrsPers.end(), displayPerson() );

	//cout << "\n\n";

//	sort(sIte, eIte, comparePersons());

	cout << "\n\nSorted persons";
	for_each(setPtrsPers.begin(), setPtrsPers.end(), displayPerson() );
	cout << "\n\n\n";

//
//	multiset<string ,person*>::iterator ite = setPtrsPers.begin();
/*
	while( ite != setPtrsPers.end() )
	{
		delete *ite;
		ite++;
	}
*/
	return 0;
} 


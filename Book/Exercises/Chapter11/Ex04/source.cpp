/*
 * Subject: A publishing company that markets both book and audiocassette.
 * 
 * Date: July 23, 2024
 * 
 * Author: Alsayed-Aldkhakhni
 * 
 * Last modification: July 23, 2024
 * 
 * */

#include <iostream> // for the declaration of cin, cout objects.
#include <string>   // for the string data type.
using namespace std;// for the definition of cin, cout.
//################################################################################//
class Publication
{
private:
	string title;
	float price;
	
public:
	Publication() : title(""), price(0.0) {}
	
	// read the data.
	// the 'virtual' keyword tells the compiler that
	// each child will have its own version of this function
	// so if you, compiler, encountered a pointer of base class
	// points to an instance of this class call its
	// own functions not the parent ones.
	virtual	void setData()
	{	
		cin.ignore();
		cin.clear();
		
		cout << "   Enter the title of the wedgit: ";
		getline(cin, title);
		
		cout << "   Enter its price: ";
		cin >> price;
		
		if(price <= 0)
		{
			cout << "-----> Invalid price.\n";
			exit(1);
		}
	}
	
	// display it.
	virtual void getData() const 
	{
		cout << "   Name:       " << title << '\n'
		     << "   Price:     $" << price << '\n';
	}
	
	virtual	bool isOversized() const =0;
};
//################################################################################//
class Book : public Publication
{
private:
	int pageCount;
	
public:
	Book() : pageCount(0) {}
	
	void setData()
	{
		Publication::setData();
		
		cout << "   Enter # of pages: ";
		cin >> pageCount;
		
		if(pageCount <= 0)
		{
			cout << "-----> Invalid number of pages.\n";
			exit(1);
		}
	}
	
	void getData() const
	{
		Publication::getData();		
		cout << "   # of Pages: " << pageCount << '\n';
		cout << "   It's " << (isOversized() ? "oversized.\n" : "not oversized.\n");
	}

	bool isOversized() const { return pageCount >= 800? true : false; }
};
//################################################################################//
class Tape : public Publication
{
private:
	float playingTime;
	
public:
	Tape() : playingTime(0) {}
	
	void setData()
	{
		Publication::setData();
		
		cout << "   Enter playing minutes: ";
		cin >> playingTime;
		
		if(playingTime <= 0)
		{
			cout << "-----> Invalid playing minutes.\n";
			exit(1);
		}
	}
	
	void getData() const
	{
		Publication::getData();
		cout << "   Time:       " << playingTime << "\n";
		cout << "   It's " << (isOversized() ? "oversized\n" : "not oversized\n");
	}

	bool isOversized() const { return playingTime >= 90? true : false; }
};
//################################################################################//

int main()
{
	Publication* pubs[100];
	int numOfPubs = 0;
	char ans = 'y';
	char pubType;

	while(ans == 'y')
	{
		cout << "-->Book or Tape?(b, t): ";
		cin >> pubType;
		pubType = tolower(pubType);

		// allocate memory for book object.
		if(pubType == 'b')
		{
			pubs[numOfPubs] = new Book;
			pubs[numOfPubs]->setData();
			numOfPubs++;
		}
		else if(pubType == 't') // for tape.
		{
			pubs[numOfPubs] = new Tape;
			pubs[numOfPubs]->setData();
			numOfPubs++;
		}
		else 
			cout << "Invalid input.\n\n";
	
		cout << "\n\nOne more?(y, n): ";
		cin >> ans;
	}


	cout << "==========="
		"==========="
		"===========\n";

	for(int i = 0; i < numOfPubs; i++)
	{
		pubs[i]->getData();
		cout << "==========="
			"==========="
			"===========\n";
	}

	// release the memory.
	for(int i = 0; i < numOfPubs; i++)
		delete pubs[i];

	return 0;
};

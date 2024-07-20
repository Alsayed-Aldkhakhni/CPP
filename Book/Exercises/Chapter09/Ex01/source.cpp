/*
 * Subject: A publishing company that markets both book and audiocassette.
 * 
 * Date: July 20, 2024
 * 
 * Author: Alsayed-Aldkhakhni
 * 
 * Last modification: July 20, 2024
 * 
 * */

#include <iostream> // for the declaration of cin, cout objects.
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
	void setData()
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
	void getData() const
	{
		cout << "   Name:       " << title << '\n'
			 << "   Price:     $" << price << '\n';
	}
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
	}
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
		cout << "   Time:   " << playingTime << "\n";
	}
};
//################################################################################//

int main()
{
	Book book1;
	Tape tape1;
	
	book1.setData();
	cout << "\n\n";
	tape1.setData();
	
	cout << "\n\n";
	
	book1.getData();
	cout << "\n----------------\n";
	tape1.getData();
	
	return 0;
}
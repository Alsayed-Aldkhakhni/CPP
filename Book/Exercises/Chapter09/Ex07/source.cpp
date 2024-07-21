/*
 * Subject: Inherit a CountDn that has the rest of unary operators.
 *
 * Date: July 20, 2024
 *
 * Author: Alsayed-Aldkhakhni
 *
 * Last modification: July 20, 2024
 * */

#include <iostream> // for the declaration of inc, cout objects.
using namespace std;// for their definition.
//#######################################################################//
class Counter
{
protected:
	unsigned int count;
public:
	Counter() : count(0) {}
	Counter(int c) : count(c){}
	unsigned int get_count() const { return count; }
	Counter operator++() { return Counter(++count); }
};

class CountDn : public Counter
{
public:
	CountDn() : Counter(){}
	CountDn(int c) : Counter(c){}

	CountDn operator--()    {return CountDn(--count);}
	CountDn operator--(int) {return CountDn(count--);}
	
	using Counter::operator++; // make it visible to not to be shadowed.
	CountDn operator++(int) {return CountDn(count++);}
};

//#######################################################################//

int main()
{
	CountDn c1(10);
	
	c1++;
	cout << c1.get_count() << "\n"; // 11
	
	c1--;
	cout << c1.get_count() << "\n"; // 10
	
	++c1;
	cout << c1.get_count() << "\n"; // 11
	
	--c1;
	cout << c1.get_count() << "\n"; // 10

	return 0;
}

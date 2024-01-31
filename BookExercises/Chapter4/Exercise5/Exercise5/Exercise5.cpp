/*
 * Subject: A program obtains a date from the user and print it again.
 *
 * Date: December 11, 2023
 *
 * Author: Alsayed Aldkhakhni
 */


// preprocessor directives, instuct the complier's preprocessor to fetch the 
// whole data in these header files, iostream and iomainp, to the current source file.
#include <iostream>           // contains declaration of 'cin', 'cout'.
#include <iomanip>            // contains declaration of 'setfill()', 'setw()'.

using namespace std;          // definition of 'cin', 'cout' , 'setw()' and 'setfill()'.

struct date                   // structure tag.
{
    int day;                  // members.
    int month;
    int year;
};

int main()
{

    date d0{};               // declare a variable of type 'date'.

                             // these variables is to check the values before assigning.
    int dd = 0, mm = 0, yy = 0; char ch = '0'; 

                            // prompt message, tells the user what to do.
    cout << "Enter the date in following format mm/dd/yy: ";
                            // get values.
    cin >> mm >> ch >> dd >> ch >> yy; 

                            // check the validation.
    d0.month = mm >= 1 && mm <= 12 ? mm : 0;
    d0.day = dd >= 1 && dd <= 31 ? dd : 0;
    d0.year = yy > 0 ? yy : 0;


    cout << "You entered: " // print the date entered.
         << setfill('0') << setw(2) << d0.month << '/' << setw(2)
         << d0.day << '/' << setw(4) << d0.year << '\f';

    return 0;               // indicates the operating system that the program executed successfully.
}
#include<iostream>      // cin, cout declaration.
#include<string>        // string class declaration.
#include "Date.h"       // class interface.
using namespace std;    // the definition of cin, cout and string.


//*******************************************************************************
                        // the ends of the months.
const int monthDays[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 }; 

                        // months' names.
const string monthName[13] = { "","January", "February", "March", "April","May","June", "July", 
                                  "August", "September", "October", "November", "December" };

                        // determine the leap year.
bool Date::isLeap(unsigned short Y) 
{
    if ((Y % 4 == 0 && Y % 100 != 0) || (Y % 400 == 0))
    {
        return true;    // if it is.
    }

    return false;       // if it's not.
}

//*******************************************************************************

Date::Date(unsigned short Y, unsigned short M, unsigned short D)
{
                        // range validation.
    if ((Y >= 1000 && Y <= 3000) && (M >= 1 && M <= 12) && (D >= 1 && D <= 31))
    {
        year = Y; month = M;

        if (isLeap(Y))  // if it's leap.
        {
            if (M == 2) // and we in the February

            {           // and the day is valid.
                if (D <= 29) 
                {
                        // set the day.
                    day = D; 
                }
                else    // wrong value.
                {
                        // error message and stop immediately.
                    cout << "You exceeded the maximum range for this month.\f";
                    return;
                }
            }
        }
        else            // it's not leap.

        {               // check the days within the month's range or not.
            if (D <= monthDays[M])
            {
                day = D; // if so, then assign it.
            }
            else        // wrong value.
            {
                        // error message and stop immediately.
                cout << "exceeded the range of days for this month.\f";
                return;
            }
        }
    }
    else                // the whole values are not valid.
    {
        cout << "Values are out of range.\f";
        return;
    }
}

//*******************************************************************************

void Date::nextDay()    // increment the current day and go to the following one.
{
                        // check if we are in range of the month's days.
    if (day < monthDays[month] || (isLeap(year) && month == 2 && day < 29))
    {
        day++;          // go to the next day.
    }
    else                // if the month ended.
    {
        day = 1;        // come back to the beginning.

        if (month < 12) // is the year will end or not?
        {
            month++;    // not, then go a month forward.
        }
        else            // else the year ended.
        {
            month = 1;  // start from the beginning.
            year++;     // go forward with the year.
        }
    }

    //if (isLeap(year) && month == 2 && day < 29) day++; // if we in a leap year.
}

//*******************************************************************************

void printDate(Date D0) // display the date in form (i.e. December 18, 2023).
{
    cout << monthName[D0.month] << ' ' << D0.day << ", " << D0.year;
}
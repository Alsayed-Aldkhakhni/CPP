/*
 * Subject: A program that take the time and return the whole seconds number.
 *
 * Date: December 12, 2023
 *
 * Author: Alsayed Aldkhakhni
 */

 // preprocessor directives instruct the compiler's preprocessor to fetch the 
 // whole content of these header files, iostream & conio to the current source file.
#include <iostream>         // 'cin' and 'cout' declaration.
using namespace std;        // the definition of cin, cout.

struct Time                 // structure's tag.
{
    int hours;              // members.
    int minutes;
    int seconds;
};

int main()
{
    Time clock{};           // take a variable of type 'Time'.

    int hrs, mins, secs;    // hold the data to check the validation before assigning.
    char colon;
                            // prompt message instructs the user what to do.
   cout << "Enter time in form ( hh:mm:ss ): "; 
                            // get the values.
   cin >> hrs >> colon >> mins >> colon >> secs;
                            // check the values' range.
    if (hrs >= 0 && mins >= 0 && secs >= 0) 
    {                        // if the values are valid assign them.
        clock.hours = hrs <= 12 ? hrs : 0;
        clock.minutes = mins <= 59 ? mins : 0;
        clock.seconds = secs <= 59 ? secs : 0;
    }

    cout << "Total seconds: " << clock.hours * 3600 +  clock.minutes * 60  + clock.seconds << " seconds.";

    return 0;               // indicats the operating system that the program executed successfully.
}
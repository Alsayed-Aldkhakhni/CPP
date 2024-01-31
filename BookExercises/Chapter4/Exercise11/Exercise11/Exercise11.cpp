/*
 * Subject: A program that take the time and sum the whole seconds number and then display the total time again.
 *
 * Date: December 12, 2023
 *
 * Author: Alsayed Aldkhakhni
 */

 // preprocessor directives instruct the compiler's preprocessor to fetch the 
 // whole content of these header files, iostream & conio to the current source file.
#include <iostream>         // 'cin' and 'cout' declaration.
#include <iomanip>          // for setw, setfill declaration.

struct Time                 // structure's tag.
{
    int hours;              // members.
    int minutes;
    int seconds;
};

int main()
{
    Time time1{}, time2{};  // get two variables of type Time to hold the data will be entered.

    int hrs, mins, secs;    // hold the data to check the validation before assigning.
    char colon;
                            // prompt message instructs the user what to do.
    std::cout << "Enter time in form ( hh:mm:ss ): "; 

    std::cin >> hrs >> colon// get the values.
             >> mins >> colon >> secs;

                            // check the values' range.
    if (hrs >= 0 && mins >= 0 && secs >= 0) 
    {                       // if the values are valid assign them.
        time1.hours = hrs <= 12 ? hrs : 0;  
        time1.minutes = mins <= 59 ? mins : 0;
        time1.seconds = secs <= 59 ? secs : 0;
    }
    else
    {
        std::cout << "Something went wrong.\n";
        return 0;
    }

    std::cout << "Enter time in form ( hh:mm:ss ): "; 
    std::cin >> hrs >> colon >> mins >> colon >> secs;

    if (hrs >= 0 && mins >= 0 && secs >= 0)
    {
                            // if the values are valid assign them.
        time2.hours = hrs <= 12 ? hrs : 0;
        time2.minutes = mins <= 59 ? mins : 0;
        time2.seconds = secs <= 59 ? secs : 0;
    }
    else
    {
        std::cout << "Something went wrong.\n";
        return 0;
    }
                            // convert two clock to seconds.
    unsigned int totalSeconds = time1.hours * 3600 + time1.minutes * 60 + time1.seconds + 
                                time2.hours * 3600 + time2.minutes * 60 + time2.seconds;
                            // get the hours.
    unsigned int hours = totalSeconds / 3600; 
                            // store the rest seconds
    totalSeconds = totalSeconds - hours * 3600; 
                            // get the minutes.
    unsigned int minutes = totalSeconds / 60; 
                            // hold the rest seconds.
    totalSeconds = totalSeconds - minutes * 60; 
    
    if (hours <= 12 && minutes < 60 && totalSeconds < 60)
    {
        std::cout << "Merged two clocks: "
                  << std::setfill('0') << std::setw(2) << hours << ':'
                  << std::setw(2) << minutes << ':' << std::setw(2) << totalSeconds << "\n";
    }
    else
    {
        std::cout << "\fThere is one or more terms out of range.\f";
        return 0;
    }
    
    return 0;
}
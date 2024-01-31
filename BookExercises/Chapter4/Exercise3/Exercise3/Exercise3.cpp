/*
 * Subject: A program to calculate the volume of a room.
 *
 * Date: December 11, 2023
 *
 * Author: Alsayed Aldkhakhni
 */


 // Preprocessor directive that instruct the compiler's preprocessor to 
 // fetch the whole content of that header file, 'iostream', into this source file.
#include <iostream>                     // 'cin', 'cout' declaration.
using namespace std;                    // 'cin', 'cout' definition.

struct Distance                         // inner structure tag.
{
    int feet;                           // members.
    float inches;
};

struct Volume                           // outer structure tag.
{
    Distance length;                    // members.
    Distance width;
    Distance hight;
};


int main()
{
    Volume livingRoom{};                // the room.

    int ft = 0;                         // temporary variables to hold the data until check it.
    float inch = 0;

                                        // set the length of the room.

                                        // Prompt message tells the user what to do.
    cout << "Enter room's length [feet, inches separated by a space]: ";
    cin >> ft >> inch;                  // get the values.

                                        // Check the validation.
    livingRoom.length.feet = ft > 0 ? ft : 0; 
    livingRoom.length.inches = inch >= 0 ? inch : 0;

    if (livingRoom.length.inches >= 12) // every 12 inches = a feet.
    {
        livingRoom.length.feet++; livingRoom.length.inches -= 12;
    }

                                        // set the width of the room.
    cout << "Enter room's width [feet, inches separated by a space]: ";
    cin >> ft >> inch;

    livingRoom.width.feet = ft > 0 ? ft : 0;
    livingRoom.width.inches = inch >= 0 ? inch : 0;

    if (livingRoom.length.inches >= 12)
    {
        livingRoom.length.feet++; livingRoom.length.inches -= 12;
    }

                                        // set the height of the room.
    cout << "Enter room's height [feet, inches separated by a space]: ";
    cin >> ft >> inch;

    livingRoom.hight.feet = ft > 0 ? ft : 0;
    livingRoom.hight.inches = inch >= 0 ? inch : 0;

    if (livingRoom.length.inches >= 12)
    {
        livingRoom.length.feet++; livingRoom.length.inches -= 12;
    }
                                        // get the three lengths in float variables.
    float Ln = livingRoom.length.feet + livingRoom.length.inches / 12;
    float wd = livingRoom.width.feet + livingRoom.width.inches / 12;
    float hg = livingRoom.hight.feet + livingRoom.hight.inches / 12;

                                        // print the volume of the room.
    cout << "Volume of that room is: " << Ln * wd * hg << "\n\n";

    return 0;                           // flag the 'OS' that the program executed successfully.
}
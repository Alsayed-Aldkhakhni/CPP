/*
 * Subject: A program perform the basic arithmetic operations on fractions using a structure.
 *
 * Date: December 13, 2023
 *
 * Author: Alsayed Aldkhakhni
 */

// The preprocessor directive instructs the compiler's preprocessor to 
// fetch the whole content of the iostream header file into the current source file.

#include <iostream>                     // contians the declaration of 'cin', 'cout'.
#include <conio.h>                      // the declaration _getche function.
using namespace std;                    // the definition of cin, cout, _getche.

struct fraction                         // structure definition, tag.
{
    int numerator;                      // members.
    int denominator;
};

int main()
{
    fraction frac1{}, frac2{};          // declare the fractions.

                                        // variables to hold the data entered by the user and check it before assigning.
    int up = 0; int down = 0; char sign = '0';

                                        // declare the variables which will hold the answers.
    fraction sum{}, difference{}, multiplied{}, divided{};

    do
    {                                   // get the first fraction.
        cout << "Enter a fraction in form (x/ y): ";
        cin >> up >> sign >> down;

        if (down != 0 && up != 0 && sign == '/')
        {
            frac1.numerator = up;
            frac1.denominator = down;
        }
        else
        {
            cout << "No division by 0, wrong division sign or 0 numerator.\f\f\f";
            return 0;
        }

        up = 0; down = 0; sign = '0';   // reinitialize the variables.

                                        // get the second fraction.
        cout << "Enter a fraction in form (x/ y): ";
        cin >> up >> sign >> down;

        if (down != 0 && up != 0 && sign == '/')
        {
            frac2.numerator = up;
            frac2.denominator = down;
        }
        else
        {
            std::cout << "No division by 0, wrong division sign or 0 numerator.\f\f\f";
            return 0;
        }
                                        // adding the two entered fractions.
        sum.numerator = frac1.numerator * frac2.denominator + frac1.denominator * frac2.numerator;
        sum.denominator = frac1.denominator * frac2.denominator;

        cout << "\f\fAddition: ";       // display the sum.
        cout << sum.numerator << '/' << sum.denominator << " = " << float(sum.numerator) / float(sum.denominator);

        //*********************************************************************************************************
        
                                        // subtracting the two fractions. 
        difference.numerator = frac1.numerator * frac2.denominator - frac1.denominator * frac2.numerator;
        difference.denominator = frac1.denominator * frac2.denominator;
            
        cout << "\f\fSubtraction: ";    // display the result.
        cout << difference.numerator << '/' << difference.denominator << " = " << float(difference.numerator) / float(difference.denominator);

        //***********************************************************************************************************

                                        // dividing the fractions.

        divided.numerator = frac1.numerator * frac2.denominator;
        divided.denominator = frac1.denominator * frac2.numerator;

        cout << "\f\fDivision: ";       // display the result of the division.
        cout << divided.numerator << '/' << divided.denominator << " = " << float(divided.numerator) / float(divided.denominator);

        //***********************************************************************************************************

                                       // multipling the fractions.

        multiplied.numerator = frac1.numerator * frac2.numerator;
        multiplied.denominator = frac1.denominator * frac2.denominator;

        cout << "\f\fMultiplication: ";// display the product.
        cout << multiplied.numerator << '/' << multiplied.denominator << " = " <<  float(multiplied.numerator) /float( multiplied.denominator);

        //***********************************************************************************************************

        cout << "\n\n";

        cout << "Press 'Esc' to exit: ";// loop again.

    } while (_getche() != 27);          // test the input. If the user pressed the 'esc' key, stop.

    return 0;                           // indicates the operating system that the program executed successfully.
}
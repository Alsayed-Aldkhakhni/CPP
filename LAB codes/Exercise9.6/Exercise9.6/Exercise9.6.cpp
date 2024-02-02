/*
 * Subject: A program that perform four basic arithmetic operations with two fraction operands.
 *
 * Date: December 15, 2023
 *
 * Author: Alsayed Aldkhakhni
 */

// preprocessor directive instructs the preprocessor, a part of the compiler, to
// fetch the whole content of these header files to the current source file.

#include <iostream>         // contains cin, cout declaration.
#include "Rational.h"       // interface of the class.
using namespace std;        // the definition of cout

int main()
{                           // instantiation.
    Rational F0(24, 36), F1(3, -5), F2, F3, F4, F5; 
    
    F2 = F0 + F1;           // four basic arithmetic operations.
    F3 = F0 - F1;
    F4 = F0 * F1;
    F5 = F0 / F1;

    cout << "ADD: ";        // display each result in its own step.
    display(F2);            // friend function.

    cout << "SUB: ";        // subtraction.
    display(F3);

    cout << "MUL: ";        // multiplication.
    display(F4);

    cout << "DIV: ";        // division.
    display(F5);

    cout << "--------------------";

    return 0;               // indicates the operating system that the program executed successfully.
}
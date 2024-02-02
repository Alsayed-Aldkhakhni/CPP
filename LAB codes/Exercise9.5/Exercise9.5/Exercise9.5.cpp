/*
 * Subject: A program that add and subtract two complex numbers.
 *
 * Date: December 15, 2023
 *
 * Author: Alsayed Aldkhakhni
 */

// preprocessor directive instructs the preprocessor, a part of the compiler, to
// fetch the whole content of these header files to the current source file.

#include <iostream>     // contains cin, cout declaration.
#include"Complex.h"     // the class interface.
using namespace std;

int main()
{                       // instantiation.
    Complex Com1(12, 5) ,Com2(12,7), ADD , SUB; 

    display(Com1);      // display the first complex number.
    display(Com2);      // display the second complex number.

    cout << "Sum:  ";

    ADD = Com1 + Com2;  // add two complex and hold the result in 'sum'.
    display(ADD);       // display the sum of two complex numbers.

    cout << "Diff: ";

    SUB = Com1 - Com2;  // subtract 'Comp2' from 'Comp2' and hold the result in 'diff'.
    display(SUB);       // display the difference between two complex numbers.

    return 0;           // indicates the operating system that the program executed successfully.
}
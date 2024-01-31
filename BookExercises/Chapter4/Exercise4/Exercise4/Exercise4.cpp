/*
 * Subject: A small program that handle some of employee's attributes.
 *
 *  Date: December 11, 2023
 *
 * Author: Alsayed Aldkhakhni
 */


// preprocessor directive, instructs the compiler's preprocessor to 
// fetch the whole content of that header file, 'iostream', into this source file.
#include <iostream>             // contains the declaration of 'cin', 'cout'.

struct Employee                 // strucute's defiantion, tag.
{
    unsigned employeeNumber;    // since the number of employee is positive.
    float employeeCompensation; // Compensation may be has fractional part.
};

int main()
{   // it's not necessary.                           
    // struct Employee emp_one{}, emp_two{}, emp_three{}; 

                                // take three variables of type 'Employee'.
    Employee emp_one{}, emp_two{}, emp_three{}; 

    int num = 0;                // these two variables to hold the data before assigning.
    float comp = 0;

                                // prompt message, tells the user what to do.
    std::cout << "Enter employee number: "; 
    std::cin >> num;

                                // check the input's validaiton.
    emp_one.employeeNumber = num > 0 ? num : 0;

    std::cout << "Enter employee compensation: ";
    std::cin >> comp;

                                // check the input's validaiton.
    emp_one.employeeCompensation = comp > 0 ? comp : 0;

    //***************************************************
                                // prompt message, tells the user what to do.
    std::cout << "\n\nEnter employee number: "; 
    std::cin >> num;

                                // check the input's validaiton.
    emp_two.employeeNumber = num > 0 ? num : 0;

    std::cout << "Enter employee compensation: ";
    std::cin >> comp;

                                // check the input's validaiton.
    emp_two.employeeCompensation = comp > 0 ? comp : 0;

    //***************************************************

    std::cout << "\n\nEnter employee number: ";
    std::cin >> num;

    emp_three.employeeNumber = num > 0 ? num : 0;

    std::cout << "Enter employee compensation: ";
    std::cin >> comp;

    emp_three.employeeCompensation = comp > 0 ? comp : 0;

                                // print the data of entered employees.
    std::cout << "\fEmployee number: " << emp_one.employeeNumber << '\f'
              << "Employee compensation: $" << emp_one.employeeCompensation << "\f\f";

    std::cout << "\fEmployee number: " << emp_two.employeeNumber << '\f'
             << "Employee compensation: $" << emp.employeeCompensation << "\f\f";

    std::cout << "\fEmployee number: " << emp_three.employeeNumber << '\f'
              << "Employee compensation: $" << emp_three.employeeCompensation << "\f\f";

    return 0;                    // flag the operating system that the program executed successfully.
}
/*
 * Subject: A program adds two amounts of British monetary system.
 *
 * Date: November 23, 2023
 *
 * Author: Alsayed Aldkhakhni
 */


#include <iostream>             // for the declaration of cin, cout.
#include <iomanip>              // for the declaration of setw, setfill
using namespace std;            // for the definition of cout, setfill and etc.

struct sterling                 // structure tag.
{
    int pounds;                 // members.
    int shillings;
    int pences;
};

                                // functions prototypes.
sterling getMoney();            // function that obtains the amount form the user.

                                // the one adds two amount and return the sum.
sterling ADD(sterling, sterling);
void print(sterling);           // the one that prints the amount.

int main()
{                               // declare two variables of type 'sterling'.
    sterling amount1, amount2, sum;

    amount1 = getMoney();       // get the first amount of money.
    amount2 = getMoney();       // get the second one.
    
    sum = ADD(amount1, amount2);// add the two amount and return the 'sum'.

    cout << '\n';

                                // print the amounts entered by the user.
    print(amount1); cout << '\n';
    print(amount2); cout << '\n';
    
                                // print the sum of them.
    std::cout << "Total:\n"; print(sum); cout << '\n';

    return 0;                   // flags the operating system that the program executed successfully.
}


sterling getMoney()             // the definition of the function that will get the amount from the user.
{
    sterling money;             // declare a variable 'money' of type 'sterling'.

                                // initialize with 0 to avoid garbge values.
    money.pounds = 0; money.shillings = 0; money.pences = 0; 

                                // temporary variables to check the values before assigning.
    int aPound, aShilling, aPence;
    char dotChar;

                                // ask the user to enter the amount of money.
    cout << "Enter an amount of money in the old system (9.19.11): ";

                                // get the amount from him.
    cin >> aPound >> dotChar >> aShilling >> dotChar >> aPence;

                                // check the validation.
    if(aPence >= 0 && aShilling >= 0 && aPence >= 0)
    {
        if(aShilling < 20 && aPence < 12)
        {                       // if the values are valid, assign them to the variable 'money'.
            money.pounds = aPound;
            money.shillings = aShilling;
            money.pences = aPence;
        }
        else
        {                       // otherwise print an error message and stop.
            cout << "Exceeded the range of shillings or pences.\n";
            exit(1);            // stop immediately.
        }
    }
    else
    {                           // other problems arise.
        cout << "Invalid value(s).\n";
        exit(1);
    }
    
    return sterling(money);     // return the amount to the caller program.
}


                                // the definition of the function that adds two amount of money and return the sum.
sterling ADD(sterling amount1, sterling amount2)
{
    sterling sum;               // declare the variables wanted throughout the addition.
    int pd, sh, pc;             // for check the validation before addition.

    pd = amount1.pounds + amount2.pounds;
    sh = amount1.shillings + amount2.shillings;
    pc = amount1.pences + amount2.pences;


    if(pc >= 12)                // since every 12 pence = 1 shilling.
    {
        pc -= 12;               // decrement the pence by 12.
        sh++;                   // increment the shillings by 1.
    }

    if(sh >= 20)                // every 20 shillins = 1 pound.
    {
        sh -= 20;               // decrement the shillings by 20.
        pd++;                   // increment the pounds by 1.
    }

    sum.pounds = pd;            // assign the values to the sum.
    sum.shillings = sh;
    sum.pences = pc;

    return sum;                 // return the sum.
}


void print(sterling M)          // the definition of the function which will print the amount.
{
    cout << "The amount:  "
         << "\x9c" << M.pounds << '.' << setfill('0') << setw(2) << M.shillings << '.' << setw(2) << M.pences << "\n";
}
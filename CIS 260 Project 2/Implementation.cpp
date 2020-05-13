#include "empInfo.h"
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main()
{   Department <float> dept1("CIS"); // a department
    char choice, answer; // handles input from menu and controls loop
    bool success;
    do
    {
        //system("CLS"); // clears the screen
        cout << right << setw(30) << "Main Menu\n\n\n" // menu of options to add/remove or clear
             << left  << setw(10) << "(1)- (A)dd\n"    << endl // data is enterd from within Add
             << left  << setw(13) << "(2)- (R)emove\n" << endl // the id to remove is entered in Remove.
             << left  << setw(14) << "(3)- (C)lear\n"  << endl
             << left  << setw(12) << "Enter Choice: "; cin >> choice;
        
        cout << endl;
    
        choice = toupper(choice);
        switch (choice)
        {
            case '1':
            case 'A':
                    success = dept1.add();
                    if (success) // call to the add method
                        cout << "Added\n";
                    else
                        cout << "Could not add\n";
                    break;
            case '2':
            case 'R':
                    success = dept1.remove();
                    if(success) // call to the remove method
                        cout << "Removed\n";
                    else
                        cout << "Could not Remove\n";
                    break;
            case '3':
            case 'C':
                    dept1.clear(); // call to the clear method
                    break;
         }
        cout << "\nAnother Operation (Y/N): "; cin >> answer; answer = toupper(answer);
        cout << endl << endl;
        
    } while (answer == 'Y');

    return 0;
}


/* Test ---------------------------------------------------------------------------------
                Main Menu
         
         
         (1)- (A)dd
         
         (2)- (R)emove
         
         (3)- (C)lear
         
         Enter Choice: 1
         
         Enter the ID # of the employee: 12345
         Enter the salary of the employee: 65000
         
         Added
         
         Another Operation (Y/N): y
         
         
                Main Menu
         
         
         (1)- (A)dd
         
         (2)- (R)emove
         
         (3)- (C)lear
         
         Enter Choice: 1
         
         Enter the ID # of the employee: 23456
         Enter the salary of the employee: 63450
         
         Added
         
         Another Operation (Y/N): y
         
         
                Main Menu
         
         
         (1)- (A)dd
         
         (2)- (R)emove
         
         (3)- (C)lear
         
         Enter Choice: 1
         
         Enter the ID # of the employee: 34567
         Enter the salary of the employee: 78000
         
         Added
         
         Another Operation (Y/N): y
         
         
                Main Menu
         
         
         (1)- (A)dd
         
         (2)- (R)emove
         
         (3)- (C)lear
         
         Enter Choice: 1
         
         Enter the ID # of the employee: 45678
         Enter the salary of the employee: 65200
         
         Added
         
         Another Operation (Y/N): y
         
         
                Main Menu
         
         
         (1)- (A)dd
         
         (2)- (R)emove
         
         (3)- (C)lear
         
         Enter Choice: a
         
         Enter the ID # of the employee: 56789
         Enter the salary of the employee: 100000
         
         Added
         
         Another Operation (Y/N): y
         
         
                Main Menu
         
         
         (1)- (A)dd
         
         (2)- (R)emove
         
         (3)- (C)lear
         
         Enter Choice: 1
         
         Could not add
         
         Another Operation (Y/N): y
         
         
                Main Menu
         
         
         (1)- (A)dd
         
         (2)- (R)emove
         
         (3)- (C)lear
         
         Enter Choice: 2
         
         Enter the ID # of the Employee to be Removed: 3456
         
         Incorrect ID # !!!
         Would You To Try Again (Y/N): y
         
         Enter the ID # of the Employee to be Removed: 34567
         Removed
         
         Another Operation (Y/N): y
         
         
                Main Menu
         
         
         (1)- (A)dd
         
         (2)- (R)emove
         
         (3)- (C)lear
         
         Enter Choice: 3
         
         Cleared
         
         Another Operation (Y/N): y
         
         
                Main Menu
         
         
         (1)- (A)dd
         
         (2)- (R)emove
         
         (3)- (C)lear
         
         Enter Choice: 3
         
         There are currently no Employees.
         
         Another Operation (Y/N): y
         
         
                Main Menu
         
         
         (1)- (A)dd
         
         (2)- (R)emove
         
         (3)- (C)lear
         
         Enter Choice: 2
         
         Could not Remove
         
         Another Operation (Y/N): y
         
         
                Main Menu
         
         
         (1)- (A)dd
         
         (2)- (R)emove
         
         (3)- (C)lear
         
         Enter Choice: 3
         
         There are currently no Employees.
         
         Another Operation (Y/N): n
         
         
         Program ended with exit code: 0
 Test ---------------------------------------------------------------------------------*/

/*
     Authors: Brandon Trastoy and Tim Schutte
     Class: CIS - 260
     Date: May 7, 2018
     Program: Classes and Linked Lists
 
     Description: This program has a interface which allows the user to interact with the program.
            The options to choose are add, print, look, remove and clear. When the user selects add,
            they are then prompted to choose the a file in which to add data, once that is done all
            information on file is then transfered to a list. When the user selects print, the
            program will then display the list back to the user with the addition of a few calculated
            fields. When the user selects look, they are then prompted to enter the name of the
            employee they are looking, if the person exists the program will return all info on that
            person. When remove is selected, the program prompts the user to enter the id of the
            person to be removed, if they exist they will be removed from the list, otherwise the
            will prompt you the i cannot remove. Last when selecting clear, the program will ask
            the user to enter the name of the file they would like the information to be printed to,
            and then it removes all information from the list.
 */

#include <iostream>
#include <iomanip>
#include "List.h"

using namespace std;



int main() {
    
    //Instance of List
    List<float> employeeInformation;
    
    char choice, answer; // handles input from menu and controls loop
    bool success;
    do
    {
        cout << right << setw(30) << "Main Menu\n\n\n" // menu of options to add/remove or clear
             << left  << setw(10) << "(1)- (A)dd"    << endl // data is enterd from within Add
             << left  << setw(13) << "(2)- (P)rint"  << endl
             << left  << setw(13) << "(3)- (L)ook" << endl
             << left  << setw(13) << "(4)- (R)emove" << endl // the id to remove is entered in Remove.
             << left  << setw(14) << "(5)- (C)lear"  << endl
             << left  << setw(12) << "Enter Choice: "; cin >> choice;
        
        cout << endl;
        
        choice = toupper(choice);
        switch (choice)
        {
            case '1':
            case 'A':
                employeeInformation.add(); // call to the add method
                break;
            case '2':
            case 'P':
                employeeInformation.print(2); // call to the print method
                break;
            case '3':
            case 'L':
                employeeInformation.peek(); // call to the peek method
                break;
            case '4':
            case 'R':
                success = employeeInformation.remove(); // call to the remove method
                if (success)
                    cout << "Employee Removed.\n";
                else
                    cout << "Could not Remove Employee.\n";
                
                break;
            case '5':
            case 'C':
                employeeInformation.clear(); // call to the clear method
                break;
        }
        cout << "\nAnother Operation (Y/N): "; cin >> answer; answer = toupper(answer);
        cout << endl << endl;
        
    } while (answer == 'Y');
    
    
    
    
    return 0;
}

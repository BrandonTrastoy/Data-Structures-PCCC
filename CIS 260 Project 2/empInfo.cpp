#include "empInfo.h"
#include <iomanip>
#include <string>
#include <fstream>

template <> Department <float> :: Department(string departName)
{
    departmentName = departName;
    
    if (departmentName == "")
    {
        cout << "Please Enter The Name Of The Deparment: "; cin >> departmentName;
    }
    
    index = 0;
    
    for(int i = 0; i < maxEmps; i++)
    {
        employeeID[i] = "";
        employeeSalary[i] = 0;
    }
}

template <> Department <float>:: ~Department()
{
    
}

template<> bool Department <float> :: search(string id)
{
    bool found = false;
    
    for (int i = 0; i < maxEmps; i++)
    {
        if (employeeID[i] == id)
        {
            index = i;
            found = true;
            break;
        }
    }
    
    return found;
}

//Checks if the array is empty, im sure this works
template <> bool Department <float> :: isEmpty()
{
    int elementsInArray = 0;
    
    for(int i = 0; i < maxEmps; i++)
    {
        if (employeeID[i] != "")
        {
            elementsInArray += 1;
        }
    }
    
    if (elementsInArray > 0)
    {
        return false;
    }
    
    else
    {
        return true;
    }
}

//Checks if the array is full, im sure this works
template<> bool Department <float> :: isFull()
{
    int elementsInArray = 0;
    
    for(int i = 0; i < maxEmps; i++)
    {
        if (employeeID[i] != "")
        {
            elementsInArray += 1;
        }
    }
    
    if (elementsInArray == maxEmps)
    {
        return true;
    }
    
    else
    {
        return false;
    }
}




template <> bool Department <float> :: add()
{
    if (isFull() == true)
    {
        return false;
    }
    
    else
    {
        search("");
        cout << "Enter the ID # of the employee: "; cin >> employeeID[index];
        cout << "Enter the salary of the employee: "; cin >> employeeSalary[index];
        cout << endl;
        
        return true;
    }
}

template <> bool Department <float> :: remove()
{
    bool removed = false;
    char choice = ' ';
    string id = "";
    
    if (isEmpty() == true)
    {
        return false;
    }
    
    do
    {
        cout << "Enter the ID # of the Employee to be Removed: "; cin >> id;
        
        if (search(id) == true)
        {
            employeeID[index] = "";
            employeeSalary[index] = 0;
            choice = ' ';
            removed = true;
        }
        
        else {
            cout << endl << "Incorrect ID # !!!" << endl;
            cout << "Would You To Try Again (Y/N): "; cin >> choice; choice = toupper(choice);
            cout << endl;
        }
        
    } while (choice == 'Y');
    
    return removed;
}

//This is going to first check if the arrays are empty,
// if so say "No Elements", otherwise print them to a file,
// then use the remove function to delete all values

template <> void Department <float> :: clear()
{
    if (isEmpty() == true)
    {
        cout << "There are currently no Employees." << endl;
    }
    
    else
    {
        ofstream fout("EmployeeInfo.txt");
        
        fout << right << setw(30) << departmentName << " Department" << endl << endl;
        
        fout << left << setw(13) << "Employee ID"
             << left << setw(17) << "Employee Salary"
             << endl
             << left << setw(13) << "-----------"
             << left << setw(17) << "---------------"
             << endl;
        
        for(int i = 0; i < maxEmps; i++)
        {
            if (employeeID[i] != "")
            {
                fout << left << setw(13) << employeeID[i]
                     << left << setw(17)
                     << fixed << showpoint << setprecision(2)
                     << employeeSalary[i]
                     << noshowpoint<< endl;
            }
        }
        
        fout.close();
        
        departmentName = "";
        
        for (int i = 0; i < maxEmps; i++)
        {
            employeeID[i] = "";
            employeeSalary[i] = 0;
        }
        
        cout << "Cleared" << endl;
    }
}

#include <iostream>
#include <string>

using namespace std;

#ifndef EMPINFO_h
#define EMPINFO_h

template <class T>

class Department {
    
public:
    
    //Default Contructor
    Department(string);
    //Default Destructor
    ~Department();
    
    //Constant Static Integer, used to initialize arrays througout class
    const static int maxEmps = 5;
    //String for the Department Name, is called within default constructor
    string departmentName;
    //
    int index;
    
    //
    bool add();
    //
    bool remove();
    //
    void clear();
    
private:
    
    //Array for employee ID
    string employeeID[maxEmps];
    //This is supposed to accept int, float, double; needs a template
    T employeeSalary[maxEmps];
    
    //This function searches through the id array and looks for the values
    // needed by the function calling it. It sets the global iterator to
    // the value of the found id and returns either true or false to
    // confirm that the id exists.
    bool search(string);
    //This method checks if the array is full, it is a sub-function of
    // the add function. If this method returns true, then the array
    // is full. However, if this function returns false, then the array
    // is not full and employees are allowed to be added.
    bool isFull();
    //This method checks if the array is empty, it is a sub-function of
    // the remove function. If this method returns true, then the array
    // is empty. However, if this function returns false, then the array
    // is not empty and employees are allowed to be removed.
    bool isEmpty();
    
};

#endif/*  EMPINFO_h */


#ifndef Node_h
#define Node_h

#include <iostream>
#include <string>

using namespace std;

template <class T>

class Node {
    
private:
    
    //Int for idNumber
    int idNumber;
    //String for employee name
    string employeeName;
    //These value can accept a int, float, or double
    T hours, rate;
    //Const float for tax rate
    const float TAX_RATE = 0.2;
    
    //This returns the net pay
    //@pre getGross must return value
    //@post net pay is returned
    //@param None
    //@return int, float or double
    T getNet();
        //This returns the gross pay
        //@pre print must be called
        //@post returns gross pay
        //@param None
        //@return int, float or double
        T getGross();
    
    
public:
    
    //Constructor
    Node();
    //Default Destructor
    ~Node();
    
    //Pointer to next node
    Node * next;
    
    //This function sets employee info from file
    //@pre must be given file
    //@post info is set
    //@param ifstream
    //@return ifstream by reference
    void setInfo(ifstream &);
    //Prints employee info
    //@pre print must be called
    //@post prints user info
    //@param None
    //@return None
    void getInfo();
    //Overided getInfo
    //@pre clear must be called
    //@post info printed to file
    //@param ofstream
    //@return ofstream by reference
    void getInfo(ofstream &);
    
    //Returns the id
    //@pre insert must be called
    //@post returns id
    //@param None
    //@return int
    int getID();
    //Returns id number
    //@pre location must be called
    //@post returns name
    //@param None
    //@return string
    string getName();
    
};

#endif /* Node_h */

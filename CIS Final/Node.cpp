#include "List.h"
#include "Node.h"
#include <fstream>
#include <iomanip>

template <class T>
//Constructor
Node<T> :: Node()
{
    next = NULL;
}

template <class T>
//Constructor
Node<T> :: ~Node()
{
    
}

template <class T>
//Function definition for setInfo
void Node<T> :: setInfo(ifstream & fin)
{
    if (fin){
        string firstName, lastName, temp;
        
        fin >> idNumber;
        fin.ignore();
        getline(fin, lastName, ',');
        getline(fin, firstName);
        fin >> hours >> rate;
        
        firstName.erase(firstName.begin(), find_if(firstName.begin(), firstName.end(), bind1st(not_equal_to<char>(), ' ')));
        
        employeeName = (lastName + " " + firstName);
        
    }
    else
        cout << "File not found" << endl;
    
}

template <class T>
//Function definition for getInfo
void Node<T> :: getInfo()
{
    cout << "ID Number: " << idNumber << endl
         << "Employee Name: " << employeeName << endl
         << "Hours: " << hours << endl
         << "Rate: " << rate << endl
         << "Gross Pay: " << getGross() << endl
         << "Net Pay: " << getNet() << endl << endl;
}

template <class T>
//Function definition for overloaded getInfo
void Node<T> :: getInfo(ofstream & fout)
{
    fout << "ID Number: " << this->idNumber << endl
         << left << setw(10) << "Employee Name: " << this->employeeName << endl
         << "Hours: " << this->hours << endl
         << "Rate: " << this->rate << endl
         << "Gross Pay: " << this->getGross() << endl
         << "Net Pay: " << this->getNet() << endl << endl;
}

template <class T>
//Function definition for getID
int Node<T>:: getID()
{
    return idNumber;
}

template <class T>
//Function definition for getName
string Node<T> :: getName()
{
    return employeeName;
}

template <class T>
//Function definition for getGross
T Node<T> :: getGross()
{
    return (hours * rate);
}

template <class T>
//Function definition for getNet
T Node<T> :: getNet()
{
    return (getGross() * (1-TAX_RATE));
}

template class Node<int>;
template class Node<double>;
template class Node<float>;



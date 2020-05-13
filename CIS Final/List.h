#include "Node.h"

#ifndef List_h
#define List_h

template <class T>

class List {
    
private:
  
    //Pointer to head
    Node<T> * head;
    
    //Will hold the number of active nodes
    static int amountOfNodes;
    
public:
    
    //Constructor
    List();
    // Destructor
    virtual ~List();
    
    
    //This function add a node to the correct position array
    //@pre User enters 1 or P on input menu
    //@post Adds all information from file into linked list
    //@param None
    //@return None
    void add();
        //This function is called within add and is used to put nodes at the correct position
        //@pre Add must be called
        //@post put node in position
        //@param node pointer and ifstream
        //@return node pointer and ifstream by reference
        void insert(Node<T>* &hd, ifstream &);
            //This function is called within insert, sets userInfo and next node to NULL
            //@pre Insert must be called
            //@post adds user information to node
            //@param ifstream
            //@return node pointer and ifstream by reference
            Node<T>* setNode(ifstream &);
    
    //This function removes a node from the linked list
    //@pre User enters 4 or R on input menu
    //@post returns true if data removed successfully
    //@param None
    //@return bool
    bool remove();
    
    //This function outputs all info in list to a file and removes all nodes from linked list
    //@pre User enters 5 or C on input menu
    //@post list is cleared and output file created
    //@param None
    //@return None
    void clear();
    
    //This function allows the user to see all information about individual person
    //@pre User enters 3 or L on input menu, must be give name of person
    //@post displays employee Info
    //@param None
    //@return None
    void peek() const;
        //This function prints the info of the given name, called recursively
        //@pre peek must be called
        //@post prints employee info
        //@param Node pointer, and string
        //@return None
        void location(Node<T> * current, string search) const;
    
    //This function prints information to file or console depending in input
    //@pre User enters 2 or P on input menu, or user selects clear
    //@post link list is printed
    //@param int
    //@return None
    void print(int) const;
    
    //This function checks if list is empty
    //@pre add, remove, clear, peek, print must be called
    //@post returns true if is empty
    //@param None
    //@return bool
    bool isEmpty() const;
     
    
};

#endif /* List_h */

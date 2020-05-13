#include "Node.h"
#include "List.h"
#include <fstream>

template <class T>
//Sets amount of nodes to 0
int List<T> :: amountOfNodes = 0;

template <class T>
//Constructor
List<T> :: List()
{
    head = NULL;
}

template <class T>
//Destructor
List<T> :: ~List()
{
    
    
}

template <class T>
//Function definition for add
void List<T> :: add()
{
    if (isEmpty()) {
        string dataSet1 = "data1.txt", dataSet2 = "data2.txt", temp = "";
        int choice;
        
        do {
            cout << "Which file do you want to use? " << endl
                 << "1) data1.txt" << endl
                 << "2) data2.txt" << endl
                 << "Enter your Choice: "; cin >> choice;
            
            if (choice == 1)
                temp = dataSet1;
            else if (choice == 2)
                temp = dataSet2;
            else
                cout << "Invalid Choice!!!" << endl << endl;
            
        } while(temp == "");
        
        ifstream fin(temp); 
        
        List();
        
        for (int i = 0; i < 15; i++)
        {
            insert(head, fin);
            amountOfNodes++;
        }
        
        cout << "File Data Tranfered." << endl;
        
        fin.close();
    }
    
    else
    {
        cout << "You Cannot Add Employees From File Until You Clear The List." << endl;
    }
}

template <class T>
//Function definition for insert
void List<T> :: insert(Node<T>* & hd, ifstream & fin)
{  
    Node<T> * prev = new Node<T>; prev = hd;
    Node<T> * curr = new Node<T>; curr = hd;
    Node<T> * newnode = new Node<T>; newnode = setNode(fin);
 
 	if (hd == NULL) {
        
		hd = newnode;
	}
    else {
        
        if (newnode->getID() > hd->getID()) {
            
		  newnode->next = hd;
		  hd = newnode;	
	   	}
    
    	else {
            
			while (newnode->getID()  < curr->getID() && curr->next != NULL) {
                
				prev = curr;
		    	curr = curr->next;
			}
    
			if (curr->next == NULL) {
                
				if (newnode->getID() > curr->getID()) {
                    
					newnode->next = curr;
			  	  	prev->next = newnode;
				}
                
				else {
				    curr->next = newnode;
				}
		    }
            
			else {
			   newnode->next =curr;
			   prev->next = newnode	;
		    }
		}
	}
}

template <class T>
//Function definition for setNode
Node<T>* List<T> :: setNode(ifstream & fin)
{ 
	Node<T>* node = new Node<T>;
    node->setInfo(fin);
    node->next = NULL;
    return node;
}

template <class T>
//Function definition for remove
bool List<T> :: remove()
{
	bool removed = false;
    
    if (isEmpty() == true)
    {
        return false;
    }
    
    else {
        
        Node<T> * current = new Node<T>; current = head;
        Node<T> * nxt = new Node<T>; nxt = head->next;
        int idSearch;
        
        cout << "Enter the ID # of the Employee to be Removed: "; cin >> idSearch;
        
        if (current->getID() == idSearch){
            delete current;
            current = nxt;
            nxt = current -> next;
            removed = true;
        }
        
        else {
            
            head = current;
            
            while (nxt != NULL) {
                
                if(nxt->getID() == idSearch){
                    current->next = nxt->next;
                    delete nxt;
                    nxt=current->next;
                    removed = true;
                }
                else {
                    current = nxt;
                    nxt=nxt->next;
                }
            }
            amountOfNodes--;
        }
        return removed;
    }
}

template <class T>
//Function definition for clear
void List<T> :: clear()
{
	if (isEmpty())
    {
        cout << "There are currently no Employees." << endl;
    }
    
    else
    {
        Node<T> * previous = new Node<T>;
		Node<T> * current = new Node<T>; current = head;
		
        print(1);
        
		//head->next = NULL;
		while (current != NULL)
    	{
        	previous = current;
        	current = current->next;
        	delete previous;
    	}
        
        head = NULL;
        amountOfNodes = 0;
	}
}

template <class T>
//Function definition for peek
void List<T> :: peek() const{
    if(isEmpty())
        cout << "There are currently no Employees." << endl;
    
    else
    {
        Node<T> * current = new Node<T>; current = head;
        string nameSearch;
        cout << "Enter the Name of the Employee to be Searched: "; cin.get(); getline(cin, nameSearch);
        
        location(current, nameSearch);
    }
}

template <class T>
//Function definition for location
void List<T> :: location(Node<T> * current, string search) const
{
    if(current != NULL)
    {
    	if(current->getName() == search)
        {
			current->getInfo();
            cout << "Found" << endl;
		}
		else
        {
			location(current->next, search);
            cout << "Not Found" << endl;
        }
	}
}

template <class T>
//Function definition for isEmpty
bool List<T> :: isEmpty() const
{
    if (amountOfNodes <= 0)
        return true;
    else
        return false;
}

template <class T>
//Function definition for print
void List<T> :: print(int operationValue) const
{
    
    Node<T> * current = new Node<T>;
    current = head;
    
    if(isEmpty())
        cout << "No Employees To Display" << endl;
    
    else
    {
        if (operationValue == 1) {
            string fileName;
            
            cout << "Enter File Name: "; cin >> fileName;
            fileName = fileName + ".txt";
            
            cout << fileName << " created." << endl;
            
            ofstream fout(fileName);
            
            while (current != NULL)
            {
                current->getInfo(fout);
                current = current->next;
            }
            
            fout.close();
        }
        else
        {
            while (current != NULL)
            {
                current->getInfo();
                current = current->next;
            }
            
        }
        
        cout << "Number of Employees in List: " << amountOfNodes << endl;
    }
}

template class List<int>;
template class List<double>;
template class List<float>;

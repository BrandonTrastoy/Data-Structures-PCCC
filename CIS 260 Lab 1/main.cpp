/*
 Authors: Brandon Trastoy
 Class: CIS - 260
 Date: February 21, 2018
 Program: Pointers, Structures and Structure Composition
 Description:
 */

#include <iostream>
#include <string>
using namespace std;

typedef struct student{
    
    string nameOfStudent;
    int studentIdNum, numOfCourses;
    
}studInfo;

typedef struct course{
    string courseName;
    int courseCredit;
    char grade;
    int totalCredits;
    float gpa;
    
    course * next;
} *courseInfo;

void insert(courseInfo &);
    courseInfo setnode();

void print(course *);

int main() {
    
    studInfo studentArr[10];
    cout << "Name: "; getline(cin, studentArr[1].nameOfStudent);
    cout << "ID: "; cin >> studentArr[1].studentIdNum;
    cout << "Num of Courses: "; cin >> studentArr[1].numOfCourses;
    
    courseInfo head = NULL;
    for(int i = 0; i < studentArr[1].numOfCourses; i++)  {
        insert(head);
    }
    
    print(head);
    return 0;
}

void insert(courseInfo & hd) {
    if (hd == NULL) {
        
        hd = setnode();
    }
    
    else {
        courseInfo temp = hd;
        while (temp->next != NULL) {
            
            temp = temp->next;
        }
        
        temp->next = setnode();
    }
}

    courseInfo setnode() {
        
        courseInfo node = new course;
        
        cin.get();
        cout << "Course ID: "; getline(cin,(node->courseName));
        cout << "Credits: "; cin >> node->courseCredit;
        cout << "Grade: "; cin >> node->grade;
        
        //node->totalCredits += node->courseCredit;
        node->next = NULL;
        return node;
    }

void print(course *pt) {
    
    if (pt == NULL) {
        cout << "NULL"<<endl;
    }
    
    else {
        cout << "Course: " << pt->courseName
             << "Credits: " << pt->courseCredit
             << "Grade: " << pt->grade
             << "Total Credits: " << pt->totalCredits << endl;
        
        print(pt->next);   // recursive
    }
}

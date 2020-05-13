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

void insert(courseInfo &, courseInfo);
courseInfo setnode(courseInfo);

void print(course *);

int main() {
    
    int i = 10;
    
    studInfo studentArr[i];
    courseInfo courseArr[i];
    /*cout << "Name: "; getline(cin, studentArr[1].nameOfStudent);
    cout << "ID: "; cin >> studentArr[1].studentIdNum;
    cout << "Num of Courses: "; cin >> studentArr[1].numOfCourses;*/
    
    courseInfo head = NULL;
    for(int i = 0; i < studentArr[1].numOfCourses; i++)  {
        
        insert(head, courseArr[i]);
    }
    
    print(head);
    return 0;
}

void insert(courseInfo & hd, courseInfo courseArr) {
    if (hd == NULL) {
        
        hd = setnode(courseArr);
    }
    
    else {
        courseInfo temp = hd;
        while (temp->next != NULL) {
            
            temp = temp->next;
        }
        
        temp->next = setnode(courseArr);
    }
}

courseInfo setnode(courseInfo s) {
    
    courseInfo node = new course;
    
    cin.get();
    cout << "Course ID: "; getline(cin,(node->courseName));
    cout << "Credits: "; cin >> node->courseCredit;
    cout << "Grade: "; cin >> node->grade;
    
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
        << "Grade: " << pt->grade << endl;
        
        print(pt->next);   // recursive
    }
}


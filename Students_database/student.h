#pragma once
#include <iostream>

using namespace std;

struct student{
    int id ;
    string name ;
    float gpa;
    string dep ;

    friend ostream & operator<<(ostream& os, student& stud){
        cout << stud.id << endl;
        cout << stud.name << endl;
        cout << stud.gpa << endl;
        cout << stud.dep << endl;
        cout << "============================\n";
        return os;
    }
    friend istream & operator>>(istream& in, student& stud){
            cout << "id: ";
            in >> stud.id;

            cout << "Name: ";
            in >> stud.name;

            cout << "GPA: ";
            in >> stud.gpa;

            cout << "Department: ";
            in >> stud.dep;
            cout << "============================\n";

            return in;
    }
};
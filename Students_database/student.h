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
        in >> stud.id ;
        in.ignore();

        cout << "Name: ";
        string line;
        getline(in, line);
        stud.name = line;

        cout << "GPA: ";
        in >> stud.gpa;
        in.ignore();

        cout << "Department: ";
        in >> stud.dep;
        in.ignore();
        
        cout << "============================\n";

        return in;
    }


};
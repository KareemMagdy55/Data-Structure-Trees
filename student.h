#pragma once
#include <iostream>

using namespace std;

struct student{
    string id ;
    string name ;
    string gpa;
    string dep ;

    friend ostream & operator<<(ostream& os, student& stud){
        cout << stud.id << endl;
        cout << stud.name << endl;
        cout << stud.gpa << endl;
        cout << stud.dep << endl;
        cout << "============================\n";
        return os;
    }
};
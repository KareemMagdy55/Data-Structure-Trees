#pragma once

#include "student.h"


ostream &operator<<(ostream &out, student &stud) {
    out << stud.id << endl;
    out << stud.name << endl;
    out << stud.gpa << endl;
    out << stud.dep << endl;
    out << "============================\n";
    return out;
}

istream &operator>>(istream &in, student &stud) {

    cout << "id: ";
    in >> stud.id;
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


#pragma once
#include <iostream>
#include <fstream>
#include "student.cpp"
using namespace std;


// extern denotes a global variable that can be accessed from a different cpp file.
extern student* students = NULL; // must be initialized.
extern int nStudents = 0 ; // must be initialized.


extern void loadTxtFile (){
    // open Stud_db.txt.
    fstream students_DB ;
    students_DB.open("Stud_db.txt");

    // Get the number of students in the first line of the txt file.
    string nStud ;
    getline(students_DB, nStud);
    nStudents = stoi(nStud);

    //Initialize the student array "students" with the new size.
    students = new student[nStudents];

    // Load the desired information from the txt file into the students array.
    for (int i = 0; i < nStudents; ++i) {
        // Get student's ID.
        string tempID;
        getline(students_DB, tempID);
        students[i].id = stoi(tempID);

        // Get student's name.
        getline(students_DB, students[i].name);

        // Get student's GPA.
        string tempGPA ;
        getline(students_DB, tempGPA);
        students[i].gpa = stof(tempGPA);

        // Get student's department.
        getline(students_DB, students[i].dep);
    }


}

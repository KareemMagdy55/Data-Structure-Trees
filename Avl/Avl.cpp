#pragma once
#include "students_DB.cpp"

struct Node {
    student data;
    int height;
    Node* left;
    Node* right;

    Node(student stud): data(stud), height(1), left(nullptr), right(nullptr) {}
};


class AVLTree {
    Node *root;
public:
    AVLTree() : root(nullptr) {
        loadTxtFile();
        for (int i = 0; i < nStudents; ++i) {
            student stud;
            stud.id = students[i].id;
            stud.name = students[i].name;
            stud.gpa = students[i].gpa;
            stud.dep = students[i].dep;
//            addStudent(stud);
        }
    }
};

int main(){
    AVLTree tree;
    student s1 = {1, "Mohamed", 3.5, "Cs"};
    student s2 = {2, "Omar", 2.7, "Ds"};
//    cout << "\nTEST AVL FILE\n";
//    cout << students[0];
}
#pragma once
#include "students_DB.cpp"
#include <unordered_map>

#ifndef DATA_STRUCTURES_TREES_AVL_H
#define DATA_STRUCTURES_TREES_AVL_H

struct Node {
    student data; // to hold student data in the node
    int height;
    Node* left;
    Node* right;

    Node(student stud);
};

class AVLTree{
    Node *root;
public:
    AVLTree();

    void addStudent(student stud);

    void removeStudent(int id);

    void searchStudent(int id);

    void printAll();

    void printDepartmentReport();

    int getHeight(Node *node);

    int getBalance(Node *node);

    Node *rotateLeft(Node *x);

    Node *rotateRight(Node *x);

    Node *insert(Node *node, student stud);

    Node *search(Node *node, int id);

    Node *getMinimumNode(Node *node);

    Node *remove(Node *node, int id);

    void inorderTraversal(Node *node);

    void countStudentsPerDepartment(Node *node, unordered_map<string, int> &counts);
};

#endif //DATA_STRUCTURES_TREES_AVL_H

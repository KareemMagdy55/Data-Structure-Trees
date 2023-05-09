/*
 Author: Hend
 Date: 6, May 2023
 Topic: Binary Search Tree
*/

#ifndef STUDENTAPPLICATION_BST_H
#define STUDENTAPPLICATION_BST_H

class Node {
public:
    student data;
    Node *left, *right;

    Node() {
        left = nullptr;
        right = nullptr;
    }
};

class BST {
public:
    Node *root;
    int CS = 0, IT = 0, DS = 0, IS = 0;
public:
    BST();

    Node *Insert(Node *r, student s);

    Node *getRoot();

    Node *Search(Node *r, int key);

    Node *findMax(Node *r);

    Node *Remove(Node *r, int key);

    void insert(student s);

    void printStudents(Node *r);

    void printDepartments() const;

    void print(Node *r);

    void remove(Node* r, int key);

    void increaseDep(std::string dep);

    void decreaseDep(std::string dep);

    bool search(int key);
};

#endif //STUDENTAPPLICATION_BST_H

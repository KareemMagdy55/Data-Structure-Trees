/*
 Author: Hend
 Date: 6, May 2023
 Topic: Binary Search Tree
*/
#pragma once

#include "students_DB.cpp"

class BstNode {
public:
    student data;
    BstNode *left, *right;

    BstNode() {
        left = nullptr;
        right = nullptr;
    }
};

class BST {
public:
    BstNode *root;
    int CS = 0, IT = 0, DS = 0, IS = 0;
public:
    BST();

    BstNode *Insert(BstNode *r, student s);

    BstNode *getRoot();

    BstNode *Search(BstNode *r, int key);

    BstNode *findMax(BstNode *r);

    BstNode *Remove(BstNode *r, int key);

    void insert(student s);

    void printStudents(BstNode *r);

    void printDepartments() const;

    void print(BstNode *r);

    void remove(BstNode* r, int key);

    void increaseDep(std::string dep);

    void decreaseDep(std::string dep);

    bool search(int key);
};


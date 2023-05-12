#pragma once
#include "BST.h"
#include <utility>

BST::BST() {
    root = nullptr;
    // Load some student from an existing text file database
    loadTxtFile();
    for (int i = 0; i < nStudents; ++i) {
        student s;
        s.id = students[i].id;
        s.name = students[i].name;
        s.gpa = students[i].gpa;
        s.dep = students[i].dep;
        insert(s);
    }
}

// getter for the root to access in the main
BstNode *BST::getRoot() {
    return root;
}

// insert student in the tree according to their IDs
BstNode *BST::Insert(BstNode *r, student s) {
    if (r == nullptr) {
        BstNode *newNode = new BstNode;
        newNode->data = s;
        r = newNode;
    } else if (s.id < r->data.id) {
        r->left = Insert(r->left, s);
    } else {
        r->right = Insert(r->right, s);
    }
    return r;
}

void BST::insert(student s) {
    increaseDep(s.dep);
    root = Insert(root, std::move(s));
}

// returns a pointer to the node that contains the ID when found
BstNode *BST::Search(BstNode *r, int key) {
    if (r == nullptr) {
        return nullptr;
    } else if (r->data.id == key) {
        return r;
    } else if (key < r->data.id) {
        return Search(r->left, key);
    } else {
        return Search(r->right, key);
    }
}

// Returns if the ID is found or not
bool BST::search(int key) {
    BstNode *result = Search(root, key);
    if (result == nullptr) {
//        cout << "Student is not found\n";
        return false;
    } else {
//        cout << "id: " << key << endl <<
//             "Student is found\n" <<
//             "[" << result->data.id << ", " << result->data.name << ", " << result->data.gpa << ", " << result->data.dep
//             << "]" << endl;
        return true;
    }
}

// return the node with the maximum ID
BstNode *BST::findMax(BstNode *r) {
    if (r == nullptr) {
        return nullptr;
    }
    if (r->right == nullptr) {
        return r;
    }
    return findMax(r->right);
}

// remove the node with the given ID
BstNode* BST::Remove(BstNode *r, int key) {
    // check if key exists in the tree
    if (!search(key)) {
        return r;
    }
    // the tree is empty
    if (r == nullptr) {
        return nullptr;
    }
    // item is on the left subtree
    if (key < r->data.id) {
        r->left = Remove(r->left, key);
    }
    // item is on the right subtree
    else if (key > r->data.id) {
        r->right = Remove(r->right, key);
    }
    else {
        if (r->left == nullptr) {
            BstNode *temp = r->right;
            delete r;
            return temp;
        }
        else if (r->right == nullptr) {
            BstNode *temp = r->left;
            delete r;
            return temp;
        }
        // node has two children
        BstNode *temp = findMax(r->left);
        r->data = temp->data;
        r->left = Remove(r->left, temp->data.id);
    }
    return r;
}

// setting the root to the new root after removing the node
void BST::remove(BstNode *r, int key) {
    root = Remove(r, key);
    if (root != nullptr) {
        for (int i = 0; i < nStudents; ++i) {
            if (students[i].id == key) {
                decreaseDep(students[i].dep);
                break;
            }
        }
    }
}

// Print all students data in the tree sorted by ID, inorder traversal
void BST::printStudents(BstNode *r) {
    if (r == nullptr) {
        return;
    } else {
        printStudents(r->left);
        cout << "[" << r->data.id << ", " << r->data.name << ", " << r->data.gpa << ", " << r->data.dep << "]" << endl;
        printStudents(r->right);
    }
}

// Print the number of students in each department
void BST::printDepartments() const {
    cout << "Students per department: " << endl;
    cout << "CS: " << CS << endl;
    cout << "IT: " << IT << endl;
    cout << "DS: " << DS << endl;
    cout << "IS: " << IS << endl;
}

// Print all students data in the tree sorted by ID and the number of students in each department
void BST::print(BstNode *r) {
    printStudents(r);
    cout << endl;
    printDepartments();
}

// increase the number of students in the department when inserting
void BST::increaseDep(string dep) {
    if (dep == "CS") { CS++; }
    else if (dep == "IT") { IT++; }
    else if (dep == "DS") { DS++; }
    else if (dep == "IS") { IS++; }
}

// decrease the number of students in the department when removing
void BST::decreaseDep(std::string dep) {
    if (dep == "CS") { CS--; }
    else if (dep == "IT") { IT--; }
    else if (dep == "DS") { DS--; }
    else if (dep == "IS") { IS--; }
}




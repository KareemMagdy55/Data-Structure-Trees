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
Node *BST::getRoot() {
    return root;
}

// insert student in the tree according to their IDs
Node *BST::Insert(Node *r, student s) {
    if (r == nullptr) {
        Node *newNode = new Node;
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
Node *BST::Search(Node *r, int key) {
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
    Node *result = Search(root, key);
    if (result == nullptr) {
        cout << "Student is not found\n";
        return false;
    } else {
        cout << "id: " << key << endl <<
             "Student is found\n" <<
             "[" << result->data.id << ", " << result->data.name << ", " << result->data.gpa << ", " << result->data.dep
             << "]" << endl;
        return true;
    }
}

// return the node with the maximum ID
Node *BST::findMax(Node *r) {
    if (r == nullptr) {
        return nullptr;
    }
    if (r->right == nullptr) {
        return r;
    }
    return findMax(r->right);
}

// remove the node with the given ID
Node* BST::Remove(Node *r, int key) {
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
            Node *temp = r->right;
            delete r;
            return temp;
        }
        else if (r->right == nullptr) {
            Node *temp = r->left;
            delete r;
            return temp;
        }
        // node has two children
        Node *temp = findMax(r->left);
        r->data = temp->data;
        r->left = Remove(r->left, temp->data.id);
    }
    return r;
}

// setting the root to the new root after removing the node
void BST::remove(Node *r, int key) {
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
void BST::printStudents(Node *r) {
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
void BST::print(Node *r) {
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




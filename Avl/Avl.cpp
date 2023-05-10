#pragma once
#include "Avl.h"
using namespace std;

Node::Node(student stud): data(stud), height(1), left(nullptr), right(nullptr) {}


    // loading the file and adding the students to the tree
    AVLTree::AVLTree() : root(nullptr) {
        loadTxtFile();
        for (int i = 0; i < nStudents; ++i) {
            student stud;
            stud.id = students[i].id;
            stud.name = students[i].name;
            stud.gpa = students[i].gpa;
            stud.dep = students[i].dep;
            addStudent(stud);
        }
    }


    void AVLTree::addStudent(student stud) {
        root = insert(root, stud);
    }

    bool AVLTree::removeStudent(int id) {
        root = remove(root, id);
        if(root == nullptr){
            return false;
        }
        return true;
    }

    bool AVLTree::searchStudent(int id) {
        Node *node = search(root, id);
        if (node != nullptr) {
            cout << "Student is found." << endl;
            cout << node->data;
        } else {
            cout << "Student is not found." << endl;
        }
    }

    void AVLTree::printAll() {
        inorderTraversal(root);
        cout << "Department Report:" << endl;
        printDepartmentReport();
    }

    void AVLTree::printDepartmentReport() {
        // map to count number of students in each department, the key is dep name
        unordered_map<string, int> counts;
        countStudentsPerDepartment(root, counts);

        // printing the map
        for (auto const&[department, count]: counts) {
            cout << department << ": " << count << endl;
        }
    }


    int AVLTree::getHeight(Node *node) {
        if (node == nullptr) {
            return 0;
        } else {
            return node->height;
        }
    }

    int AVLTree::getBalance(Node *node) {
        if (node == nullptr) {
            return 0;
        } else {
            return getHeight(node->left) - getHeight(node->right);
        }
    }

    Node* AVLTree::rotateLeft(Node *x) {
        Node *y = x->right;
        Node *z = y->left;

        y->left = x;
        x->right = z;

        x->height = 1 + max(getHeight(x->left), getHeight(x->right));
        y->height = 1 + max(getHeight(y->left), getHeight(y->right));

        return y;
    }

    Node* AVLTree::rotateRight(Node *x) {
        Node *y = x->left;
        Node *z = y->right;

        y->right = x;
        x->left = z;

        x->height = 1 + max(getHeight(x->left), getHeight(x->right));
        y->height = 1 + max(getHeight(y->left), getHeight(y->right));

        return y;
    }

    Node* AVLTree::insert(Node *node, student stud) {
        if (node == nullptr) {
            return new Node(stud);
        }
        // If the student's ID is less than the current node's ID,
        // it means the student should be inserted in the left subtree
        if (stud.id < node->data.id) {
            node->left = insert(node->left, stud);
        }
        //If the student's ID is greater than or equal to the current node's ID,
        // it means the student should be inserted in the right subtree
        else {
            node->right = insert(node->right, stud);
        }
        //the height of the current node is updated based on
        // the maximum height between its left and right subtrees + 1
        node->height = 1 + max(getHeight(node->left), getHeight(node->right));

        // rotations conditions
        int balance = getBalance(node);

        //the tree is left-heavy and the student should be inserted in the left subtree of the left child.
        // This requires a right rotation
        if (balance > 1 && stud.id < node->data.id) {
            return rotateRight(node);
        }

        // the tree is right-heavy and the student should be inserted in the right subtree of the right child.
        // This requires a left rotation
        if (balance < -1 && stud.id > node->right->data.id) {
            return rotateLeft(node);
        }

        //the tree is left-heavy and the student should be inserted in the right subtree of the left child
        //This requires a left rotation on the left child followed by a right rotation on the current node
        if (balance > 1 && stud.id > node->left->data.id) {
            node->left = rotateLeft(node->left);
            return rotateRight(node);
        }

        // the tree is right-heavy and the student should be inserted in the left subtree of the right child.
        // This requires a right rotation on the right child followed by a left rotation on the current node
        if (balance < -1 && stud.id < node->right->data.id) {
            node->right = rotateRight(node->right);
            return rotateLeft(node);
        }

        return node;
    }

    Node* AVLTree::search(Node *node, int id) {
        //the node is found or null
        if (node == nullptr || node->data.id == id) {
            return node;
        }

        if (id < node->data.id) {
            return search(node->left, id);
        } else {
            return search(node->right, id);
        }
    }

    Node* AVLTree::getMinimumNode(Node *node) {
        Node *current = node;
        // loop to reach the last left node
        while (current->left != nullptr) {
            current = current->left;
        }

        return current;
    }

    Node* AVLTree::remove(Node *node, int id) {
        if (node == nullptr) {
            return nullptr;
        }
        // If the ID of the student to be removed is less than the current node's ID,
        // it means the student should be in the left subtree
        if (id < node->data.id){
            node->left = remove(node->left, id);
        }
        // If the ID of the student to be removed is greater than the current node's ID,
        // it means the student should be in the right subtree
        else if (id > node->data.id){
            node->right = remove(node->right, id);
        }
        // the current node has the student to be removed
        else {
//            cout << "[ " << node->data.id << ", " << node->data.name << ", "
//                 << node->data.gpa << ", " << node->data.dep << " ]" << endl;

            //If the student to be removed has at most one child
            if (node->left == nullptr || node->right == nullptr) {
                Node *temp = node->left ? node->left : node->right;

                //the current node is a leaf node
                if (temp == nullptr) {
                    temp = node;
                    node = nullptr;
                }
                else { // replacing the current node with temp
                    *node = *temp;
                }
                delete temp;
            }
            //If the student to be removed has two children
            else {
                //find the minimum node in the right subtree of the current node
                Node *temp = getMinimumNode(node->right);
                //replacing the current node with the minimum node
                node->data = temp->data;
                // remove the minimum node from its original location
                node->right = remove(node->right, temp->data.id);
            }
        }
        // if the removed node is a leaf
        if (node == nullptr) {
            return nullptr;
        }

        node->height = 1 + max(getHeight(node->left), getHeight(node->right));

        int balance = getBalance(node);
        // imbalance cases
        if (balance > 1 && getBalance(node->left) >= 0) {
            return rotateRight(node);
        }

        if (balance > 1 && getBalance(node->left) < 0) {
            node->left = rotateLeft(node->left);
            return rotateRight(node);
        }

        if (balance < -1 && getBalance(node->right) <= 0) {
            return rotateLeft(node);
        }

        if (balance < -1 && getBalance(node->right) > 0) {
            node->right = rotateRight(node->right);
            return rotateLeft(node);
        }
        return node;
    }

    void AVLTree::inorderTraversal(Node *node) {
        if (node == nullptr) {
            return;
        }

        inorderTraversal(node->left);
        cout << node->data;
        inorderTraversal(node->right);
    }

    void AVLTree::countStudentsPerDepartment(Node *node, unordered_map<string, int> &counts) {
        if (node == nullptr) {
            return;
        }

        countStudentsPerDepartment(node->left, counts);

        //If the department name is not yet present
        if (counts.find(node->data.dep) == counts.end()) {
            counts[node->data.dep] = 1;
        } else { //If the department name is already present in the map
            counts[node->data.dep]++;
        }

        countStudentsPerDepartment(node->right, counts);
    }



//int main(){
//    AVLTree tree;
//
//    student s1;
//    student s2;
//    int id;
//    cin >> s1;
//    cin >> s2;
//
//    tree.addStudent(s1);
//    tree.addStudent(s2);
//
//    cout << "All Students:" << endl;
//    tree.printAll();
//    cout << endl;
//
//    cout << "Enter student id to be removed..." << endl;
//    cin >> id;
//    tree.removeStudent(id);
//    cout << endl;
//
//    cout << "All Students:" << endl;
//    tree.printAll();
//    cout << endl;
//
//    cout << "Enter student id to search for..." << endl;
//    cin >> id;
//    tree.searchStudent(id);
//    cout << endl;
//
//    cout << "Enter student id to search for..." << endl;
//    cin >> id;
//    tree.searchStudent(id);
//    cout << endl;
//}
#pragma once

#include <cstdlib>
#include "BST.cpp"
#include "Avl.cpp"
#include "min_heap.cpp"
#include "max_heap.cpp"

class mainApp {
private:
    int userChoice;
    student stud;
    BST bst;
    AVLTree avlTree;
    MinHeap minHeap;
    MaxHeap maxHeap;

public:
    mainApp() { userChoice = -1; }

    void start();

    void bstChoice();

    void avlChoice();

    void minHeapChoice();

    void maxHeapChoice();
};

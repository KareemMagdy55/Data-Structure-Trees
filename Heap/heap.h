#pragma once

#include <iostream>
#include <vector>

using namespace std;

// Heap is a superclass that should be inherited by MIN/MAX heap classes
// to reduce code redundancy and inefficiency as much as possible.
template<typename T>
class Heap {
protected:
    vector<T> heap;
    int size;

    void eraseRoot() ;

public:
    void getTxtFile();
    virtual void insert(T element) = 0;

    virtual void heapify(int index) = 0;

    void heapSort();

    void constructHeap();

    void printHeap();
};



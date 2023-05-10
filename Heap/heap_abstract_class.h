#pragma once
#include <iostream>
#include <vector>
using namespace std;

template<typename T>
class Heap{
protected:
    vector<T> heap;
    int size ;
    virtual void eraseRoot() = 0 ;

public:

    virtual void insert(T element) = 0;
    virtual void heapify(int index) = 0 ;
    virtual void heapSort() = 0 ;
    void constructHeap() {
        for (int i = size / 2 - 1; i >= 0; --i)
            heapify(i);
    }
    void printHeap(){
        for(int i = 0 ; i < size ; i ++)
            cout << heap[i] << ' ';
        cout << '\n';
    }
};
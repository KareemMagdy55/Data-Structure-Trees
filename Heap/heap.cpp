#pragma once

#include "heap.h"
#include "students_DB.cpp"


template<typename T>
void Heap<T>::getTxtFile() {
    loadTxtFile();
    size = nStudents;

    for (int i = 0; i < size; ++i) {
        heap.push_back(students[i]);
    }
    constructHeap();
}

template<typename T>
void Heap<T>::constructHeap() {
    for (int i = size / 2 - 1; i >= 0; --i)
        heapify(i);
}

template<typename T>
void Heap<T>::printHeap() {
    for (int i = 0; i < size; i++)
        cout << heap[i] << ' ';
    cout << '\n';
}

template<typename T>
void Heap<T>::heapSort() {
    // Initialize a temp variable to save size
    int sz = size;
    constructHeap();

    // erase root until heap is empty , each iteration make the smallest number (ROOT) pushed back in heap;
    // so it will be sorted in descending order in Min Heap or in Ascending order in Max heap at the end of the while loop.
    while (size > 0) {
        eraseRoot();
    }
    // Revert to the previous size to access all sorted elements
    size = sz;
}

template<typename T>
void Heap<T>::eraseRoot() {
    // swap between root node and last element node
    swap(heap[0], heap[size - 1]);
    size--;
    // heapify from the root node .
    heapify(0);
}

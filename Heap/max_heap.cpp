#pragma once

#include "max_heap.h"

MaxHeap::MaxHeap() {
    // call loadTxtFile() to load all students in DB txt file to the heap
    loadTxtFile();
    size = nStudents;

    for (int i = 0; i < size; ++i) {
        heap.push_back(students[i]);
    }
    constructHeap();
}

void MaxHeap::insert(student stud) {
    // insert new student at last node (index)
    heap.push_back(stud);
    size++;
    int idx = size - 1;
    int studIdx = idx;

    // compare parents to new node that was inserted
    while (idx > 0) {
        if (heap[studIdx].gpa > heap[idx].gpa) {// if child > parent , then swap them.
            swap(heap[studIdx], heap[idx]);
            studIdx = idx;
        }
        idx /= 2;
    }
    if (heap[studIdx].gpa > heap[0].gpa) {
        swap(heap[studIdx], heap[0]);
    }

}

void MaxHeap::heapify(int index) {
    int max = index;

    int left = 2 * index + 1;
    int right = left + 1;

    if (heap[left].gpa > heap[max].gpa and left < size)
        max = left;

    if (heap[right].gpa > heap[max].gpa and right < size)
        max = right;

    if (max != index) {
        swap(heap[max], heap[index]);
        heapify(max);
    }
}

void MaxHeap::eraseRoot() {
    swap(heap[0], heap[size - 1]);
    size--;
    heapify(0);
}

void MaxHeap::heapSort() {
    // Initialize a temp variable to save size
    int sz = size;
    constructHeap();

    while (size > 0) {
        eraseRoot();
    }
    // Revert to the previous size to access all sorted elements
    size = sz;
}


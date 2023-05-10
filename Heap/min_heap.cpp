#pragma once
#include "min_heap.h"

MinHeap::MinHeap() {
    loadTxtFile();
    size = nStudents;

    for (int i = 0; i < size; ++i) {
        heap.push_back(students[i]);
    }
    constructHeap();
}

void MinHeap::insert(student stud){
    // insert new student at last node (index)
    heap.push_back(stud);
    size ++ ;
    int idx = size -1 ;
    int studIdx = idx ;

    // compare parents to new node that was inserted
    while (idx > 0){
        if (heap[studIdx].gpa < heap[idx].gpa) {// if child > parent , then swap them.
            swap(heap[studIdx], heap[idx]);
            studIdx = idx ;
        }
        idx /= 2;
    }
    if (heap[studIdx].gpa < heap[0].gpa){
        swap ( heap[studIdx], heap[0]);
    }

}
void MinHeap::heapify(int index){
    int minIdx = index;

    int left  = 2 * index + 1 ;
    int right = left + 1 ;

    if (left < size && heap[left].gpa < heap[minIdx].gpa)
        minIdx = left ;

    if (right < size && heap[right].gpa < heap[minIdx].gpa)
        minIdx = right;

    if (minIdx != index){
        swap (heap[minIdx] , heap[index]);
        heapify(minIdx);
    }
}

void MinHeap::eraseRoot() {
    swap(heap[0] , heap[size - 1]);
    size -- ;
    heapify(0 );
}
void MinHeap::heapSort() {
    int sz = size;
    constructHeap();

    while (size > 0) {
        eraseRoot();
    }

    size = sz;
}


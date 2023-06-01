#pragma once

#include "min_heap.h"

void MinHeap::insert(student stud) {
    // Insert new student at last node (index), then increase the size of heap.
    heap.push_back(stud);
    size++;

    int idx = size - 1;
    int studIdx = idx;

    // compare parents to new node that was inserted
    while (idx > 0) {
        if (heap[studIdx].gpa < heap[idx].gpa) {// if child > parent , then swap them.
            swap(heap[studIdx], heap[idx]);
            // New student index = current parent index cause parent.gpa < student.gpa
            studIdx = idx;
        }
        // Go to the next parent by divide current index by 2 .
        idx /= 2;
    }
    // Last compare to the root , it cannot be handled by while loop above
    if (heap[studIdx].gpa < heap[0].gpa) {
        swap(heap[studIdx], heap[0]);
    }

}

void MinHeap::heapify(int index) {
    int minIdx = index;

    int left = 2 * index + 1;
    int right = left + 1;

    // check if left node < current index node
    if (left < size && heap[left].gpa < heap[minIdx].gpa) {
        minIdx = left;
    }

    // check if right node < current index node
    if (right < size && heap[right].gpa < heap[minIdx].gpa)
        minIdx = right;

    // if current node index changed by the two if statements above then swap nodes
    // then heapify the min index obtained by two if statements, because the node's left or right children may be larger than it.

    if (minIdx != index) {
        swap(heap[minIdx], heap[index]);
        heapify(minIdx);
    }
}

MinHeap::MinHeap() {
    this->getTxtFile();

}


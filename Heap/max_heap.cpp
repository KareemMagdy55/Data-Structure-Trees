#pragma once

#include "max_heap.h"

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

    // check if left node > current index node
    if (heap[left].gpa > heap[max].gpa and left < size)
        max = left;

    // check if right node > current index node
    if (heap[right].gpa > heap[max].gpa and right < size)
        max = right;

    // if current node index changed by the two if statements above then swap nodes
    // then heapify the max index obtained by two if statements, because the node's left or right children may be smaller than it.
    if (max != index) {
        swap(heap[max], heap[index]);
        heapify(max);
    }
}

MaxHeap::MaxHeap() {
    this->getTxtFile();

}


#pragma once
#include "heap.cpp"
#include "student.cpp"

class MaxHeap : public Heap<student>{
public:
    void insert(student stud) override;
    void heapify(int index) override;
    MaxHeap();
};
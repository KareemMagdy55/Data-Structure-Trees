#pragma once
#include "heap_abstract_class.h"
#include "students_DB.cpp"

class MinHeap : public Heap<student>{
public:
    void insert(student stud) override;
    void heapify(int index) override;
    void heapSort() override;
    void eraseRoot() override;
    void seeGpa(){
        for (int i = 0; i < size; ++i) {
            cout << heap[i].gpa << ", ";
        }
        cout << endl;
    }
    MinHeap();
};
#ifndef HEAPSORT_HPP
#define HEAPSORT_HPP

#include <iostream>
using namespace std;

class Heap {
    public:
        Heap(int capacity);
        Heap(int capacity, int *arr);
        void push(int x); //insert
        int pop();
        int peek(){ return heap[0]; }
        void sort();
        int search(int x);
        void displayHeap();
    private:
        int *heap; //Heap elements
        int Capacity; //Max size
        int size; //current size
        void heapify(int index);
        int parent(int i){ return floor((i-1)/2); }
        int leftChild(int i){ return (2*i + 1); }
        int rightChild(int i){ return (2*i + 2); }
        void swap(int &x, int &y);
};

#endif
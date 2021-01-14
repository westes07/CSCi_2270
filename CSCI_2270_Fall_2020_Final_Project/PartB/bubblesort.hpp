#ifndef BUBBLESORT_HPP
#define BUBBLESORT_HPP

#include <iostream>

using namespace std;

class BubbleSorter {
    public:
        BubbleSorter(int capacity);
        BubbleSorter(int* arr, int capacity);
        void sort();
        void insert(int x);
        int search(int x);
        void display();
    private:
        int Capacity;
        int size;
        int *list;
        void swap(int &x, int &y);
};

#endif
#include "bubblesort.hpp"

BubbleSorter::BubbleSorter(int capacity){
    list = new int[capacity];
    Capacity = capacity;
    size = 0;
}

BubbleSorter::BubbleSorter(int *arr, int capacity){
    list = arr;
    Capacity = capacity;
    size = capacity;
}

void BubbleSorter::sort(){
    bool swapped = true;
    while (swapped){
        swapped = false;
        for (int j = 0; j < size-1; j++){
            if (list[j] > list[j+1]){
                swap(list[j], list[j+1]);
                swapped = true;
            }
        }
    }
}

void BubbleSorter::swap(int &x, int &y){
    int temp = x;
    x = y;
    y = temp;
}

void BubbleSorter::insert(int x){
    if(size < Capacity){
        list[size-1] = x;
    } else {
        cout << "List is full, cannot insert new element" << endl;
    }
}

int BubbleSorter::search(int x){
    for(int i = 0; i < size; i++){
        if (list[i] == x){
            return i;
        }
    }
    return -1;
}

void BubbleSorter::display(){
    for (int i = 0; i < size; i++){
        cout << list[i] << ", ";
    }
    cout << "END" << endl;
}
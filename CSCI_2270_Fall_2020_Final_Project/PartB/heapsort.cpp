#include "heapsort.hpp"

Heap::Heap(int capacity){
    Capacity = capacity;
    heap = new int[capacity];
    size = 0;
}

Heap::Heap(int capacity, int *arr){
    Capacity = capacity;
    heap = arr;
    size = capacity;
    for (int i = size/2 - 1; i >= 0; i--){
        heapify(i);
    }
}

void Heap::push(int x){
    if (size == Capacity){
        cout << "Heap is full cannot insert a new element." << endl;
        return;
    }
    size++;
    int index;
    heap[size] = x;
    int parentIndex = parent(index);
    while (heap[parentIndex] > x){
        swap(x, heap[parentIndex]);
        parentIndex = parent(parentIndex);
    }
} 

int Heap::pop(){
    int ret = heap[size-1];
    size--;
    return ret;
}

void Heap::heapify(int index){
    int current = index;
    int left = leftChild(index);
    int right = rightChild(index);
    
    if (left < size){
        if (heap[left] < heap[current]){
            current = left;
        }
    }
    
    if (right < size){
        if (heap[right] < heap[current]){
            current = right;
        }
    }
    
    if (current != index){
        swap(heap[index], heap[current]);
        heapify(current);
    }
    
}

void Heap::swap(int &x, int &y){
    int temp = y;
    y = x;
    x = temp;
}

void Heap::sort(){
    int oldSize = size;
    int count = 0;
    while (size > 1){
        swap(heap[0], heap[size-1]);
        pop();
        heapify(0);
        count++;
    }
    size = oldSize;
}

int Heap::search(int x){
    for (int i = 0; i < size; i++){
        if (heap[i] == x){
            return i;
        }
    }
    return -1;
}

void Heap::displayHeap(){
    for (int i = 0; i < size; i++){
        cout << heap[i] << ": (" << heap[leftChild(i)] << ", " << heap[rightChild(i)] << ")" << endl; 
    }
}
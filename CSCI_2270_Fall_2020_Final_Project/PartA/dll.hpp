#ifndef DLL_HPP
#define DLL_HPP

#include <iostream>

using namespace std;

struct Node{
    int key;
    Node * next;
    Node * last;
};

class DoubleLL{
private:
    Node* head;
    Node* tail;
public:
    DoubleLL();
    ~DoubleLL();
    void insert(int key);
    Node* search(int key);
    void display();
};

#endif
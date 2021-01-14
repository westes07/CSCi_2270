#include <iostream>
#include "LinkedList.hpp"

using namespace std;

/* ----------------------------------------
TODO: Complete the method below.
      You may add helpers, headers (if necessary)
      Helper functions should not be part of the class.
*/

void LinkedList::moveEvens()
{
    // YOUR CODE HERE
    return;
}

// ----------------------------------------

LinkedList::LinkedList()
{
    head = nullptr;
}


LinkedList::~LinkedList()
{
    Node* temp = head;
    while(head) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}


void LinkedList::append(int key)
{
    // Function: Creates and inserts a new node at the END of list
    Node* newNode = new Node({key, nullptr});
    if (!head) {
        head = newNode;
    }
    else {
        Node* temp = head;
        while(temp->next) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}


string LinkedList::print()
{
    // Returns the same output as string for testcase verification
    Node* temp = head;
    string s = "";
    while(temp) {
        s = s + to_string(temp->key) + " -> ";
        temp = temp->next;
    }
    s = s + "NULL\n";

    cout << s;
    return s;
}
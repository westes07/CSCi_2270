#include "dll.hpp"

DoubleLL::DoubleLL(){
    head = NULL;
}

void deleteNode(Node* node){
    if (node == NULL){
        return;
    }
    
    deleteNode(node->next);
    delete node;
}

DoubleLL::~DoubleLL(){
    deleteNode(head);
}

void DoubleLL::insert(int key){
    Node* newNode = new Node;
    newNode->key = key;
    newNode->next = NULL;
    
    if (head == NULL){
        head = newNode;
        head->last = NULL;
        tail = newNode;
        return;
    }
    
    newNode->last = tail;
    tail->next = newNode;
    tail = newNode;
}

Node* DoubleLL::search(int key){
    if (head == NULL){
        return NULL;
    }
    
    Node* crawler = head;
    Node* backCrawler = tail;
    while (crawler != NULL){
        if (crawler->key == key){
            return crawler;
        }
        crawler = crawler->next;
    }
    return NULL;
}

void displayHelper(Node* n){
    if(n == NULL){
        cout << endl;
        return;
    }
    cout << n->key << " -> ";
    displayHelper(n->next);
}

void DoubleLL::display(){
    cout << "HEAD: ";
    displayHelper(head);
}
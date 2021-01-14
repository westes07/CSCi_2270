// CPP program to implement hashing with chaining
#include<iostream>
#include "hash.hpp"


using namespace std;

node* HashTable::createNode(int key, node* next)
{
    node* nw = new node;
    nw->key = key;
    nw->next = next;
    return nw;
}

HashTable::HashTable(int bsize)
{
    this->tableSize= bsize;
    table = new node*[tableSize];
    for(int i=0;i<bsize;i++)
        table[i] = nullptr;
}

//function to calculate hash value
unsigned int HashTable::hashFunction(int key)
{
    return (key % tableSize);
}

// TODO Complete this function
//function to search
node* HashTable::searchItem(int key)
{
    //Compute the index by using the hash function
    int index = hashFunction(key);
    if (table[index] == NULL){
        return NULL;
    }
    node* crawler = table[index];
    //TODO: Search the list at that specific index and return the node if found
    while (crawler != NULL){
        if (crawler->key == key){
            return crawler;
        }
        crawler = crawler->next;
    }
    return NULL;
}

//TODO Complete this function
//function to insert
bool HashTable::insertItem(int key){
    node* newNode = new node;
    newNode->key = key;
    newNode->next = NULL;
    if(!searchItem(key)){
        // TODO :
        // Use the hash function on the key to get the index/slot,
        // create a new node with the key and insert it in this slot's list
        node* head = table[hashFunction(key)];
        if(head == NULL){
            table[hashFunction(key)] = newNode;
            return true;
        }

        while (head->next != NULL){
            head = head->next;
        }
        head->next = newNode;
        return true;
    }
    else{
        cout<<"duplicate entry: "<<key<<endl;
        return false;
    }
}

//TODO Complete this function
// function to display hash table
void HashTable::printTable(){
    for (int i = 0; i < tableSize; i++) {
        cout << i <<"|| ";
        node* crawler = table[i];
        //TODO
        while (crawler != NULL){
            cout << crawler->key << " -> ";
            crawler = crawler->next;
        }
        cout << "NULL" << endl;
    }
}

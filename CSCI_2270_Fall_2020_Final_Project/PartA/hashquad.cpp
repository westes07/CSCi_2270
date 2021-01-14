#include "hashquad.hpp"

HashTable::HashTable(int size){
    tablesize = size;
    table = new int[size];
    for (int i = 0; i < size; i++){
        table[i] = -1;
    }
    
}

void HashTable::insertItem(int key){
    unsigned int hash = hashFunction(key);
    //Check for collision
    if (table[hash] == -1){
        table[hash] = key;
    } else {
        collisions++;
        for (int i = 0; i < tablesize; i++){
            //Check for additional collisions and quadratic probing
            if (table[hash] == -1){
                table[hash] = key;
                break;
            } else {
                hash = (hash + i*i) % tablesize;
            }
        }
    }
}

unsigned int HashTable::hashFunction(int key){
    return key % tablesize;
}

void HashTable::printTable(){
    for (int i = 0; i < tablesize; i++){
        cout << "(" << i << ": " << table[i] << "), ";
    }
    cout << endl;
}

int HashTable::getNumCollisions(){
    return collisions;
}

int HashTable::searchItem(int key){
    int hash = hashFunction(key);
    int check;
    for (int i = 0; i < tablesize; i++){
        check = (hash + (i*i)) % tablesize;
        if (table[check] == key){
            return check;
        }
        if (table[check] == -1){
            return -1;
        }
    }
    return -1;
}
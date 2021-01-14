#ifndef HASHQUAD_HPP
#define HASHQUAD_HPP

#include <iostream>
#include <string>

using namespace std;

class HashTable {
private:
    int tablesize;
    int *table;
    int collisions = 0;
public:
    HashTable(int size);

    void insertItem(int key);

    unsigned int hashFunction(int key);

    void printTable();
    int getNumCollisions();

    int searchItem(int key);
};

#endif
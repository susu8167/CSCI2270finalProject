#ifndef HASHQUADRATIC_HPP
#define HASHQUADRATIC_HPP
#pragma once

using namespace std;

class HashTable
{
    int tableSize;
    int currentSize;
    int* table;
    int numOfcollision = 0;
public:
    HashTable(int bsize);  // Constructor

    // inserts a key into hash table
    bool insertItem(int key);

    // hash function to map values to key
    unsigned int hashFunction(int key);

    void printTable();
    int getNumOfCollision();
    int getSizeOfTable(); // getter function
    int searchItem(int key); //return index
    ~HashTable(); // Destructor
};

#endif
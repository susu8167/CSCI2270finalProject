#ifndef HASHCHAINING_HPP
#define HASHCHAINING_HPP

#include <string>
#include <list>

#pragma once

using namespace std;

struct Node
{
    int key;
    struct Node* next;
};  

class HashTable
{
    int tableSize;  // No. of buckets (linked lists)
    int currentSize;
    // Pointer to an array containing buckets
    Node* *table;
    int numOfcollision =0;
    Node* createNode(int key, Node* next);
public:
    HashTable(int bsize);  // Constructor

    // inserts a key into hash table
    bool insertItem(int key);

    // hash function to map values to key
    unsigned int hashFunction(int key);

    void printTable();
    int getNumOfCollision();
    int getSizeOfTable(); // getter function
    Node* searchItem(int key);
    ~HashTable(); // Destructor
};

#endif

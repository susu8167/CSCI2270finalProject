#ifndef HASHCHAINING_HPP
#define HASHCHAINING_HPP
#pragma once

using namespace std;

struct HashNode
{
    int key;
    struct HashNode* next;
};  

class HashTable
{
    int tableSize;  // No. of buckets (linked lists)
    int currentSize;
    // Pointer to an array containing buckets
    HashNode* *table;
    int numOfCollision =0;  // num of collisions while inserting
    int numOfSearchCollision=0; // num of collisions while searching
    HashNode* createNode(int key, HashNode* next);
public:
    HashTable(int bsize);  // Constructor

    // inserts a key into hash table
    bool insertItem(int key);

    // hash function to map values to key
    unsigned int hashFunction(int key);

    void printTable();

    //functions to get and reset collision count
    int getNumOfCollision();
    void resetNumCollision();
    void resetNumSearchCollision();
    int getNumOfSearchCollision();

    int getSizeOfTable(); // getter function
    HashNode* searchItem(int key);
    ~HashTable(); // Destructor
};

#endif

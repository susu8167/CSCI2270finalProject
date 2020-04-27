#ifndef HASHQUADRATIC_HPP
#define HASHQUADRATIC_HPP
#pragma once

using namespace std;

class HashLinear
{
    int tableSize;
    int currentSize;
    int* table;
    int numOfCollision =0;  // num of collisions while inserting
    int numOfSearchCollision=0; // num of collisions while searching
public:
    HashLinear(int bsize);  // Constructor

    // inserts a key into hash table
    bool insertItem(int key);

    // hash function to map values to key
    unsigned int hashFunction(int key);

    void printTable();
    //functions to get and reset collision count
    void resetNumCollision();
    int getNumOfCollision();
    void resetNumSearchCollision();
    int getNumOfSearchCollision();
    int getSizeOfTable(); // getter function
    int searchItem(int key); //return index
    ~HashLinear(); // Destructor
};

#endif
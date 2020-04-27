#pragma once

using namespace std;

class HashQuadratic
{
    int tableSize;
    int currentSize;
    int* table;
    int numOfCollision =0;  // num of collisions while inserting
    int numOfSearchCollision=0; // num of collisions while searching
public:
    HashQuadratic(int bsize);  // Constructor

    // inserts a key into hash table
    bool insertItem(int key);

    // hash function to map values to key
    unsigned int hashFunction(int key);
    
    // functions to get and reset num of collisions
    void resetNumCollision();
    int getNumOfCollision();
    void resetNumSearchCollision();
    int getNumOfSearchCollision();

    void printTable();
    int getSizeOfTable(); // getter function
    int searchItem(int key); //return index
    ~HashQuadratic(); // Destructor
};

#include "hashQuadratic.hpp"
#include <iostream>

//HASHTABLE WITH QUADRATIC
HashTable::HashTable(int bsize){
    tableSize = bsize;
    currentSize = 0;
    table = new int[bsize];
    for(int i=0; i<bsize; i++){
        table[i] = NULL;
    }
} // Constructor                        

int HashTable::getSizeOfTable(){
    return this->currentSize;
}

    // inserts a key into hash table
bool HashTable::insertItem(int key){
    if(currentSize != tableSize){
        int index = hashFunction(key);

        int i = 1;
        while(table[index]){ //quadratic probing
            index += i*i;
            i++;
            numOfcollision++;
        }
        table[index] = key;
        currentSize++;
        return true;
    }
    else{
        return false;
    }
}

    // hash function to map values to key
unsigned int HashTable::hashFunction(int key){
    return key%tableSize;
}

void HashTable::printTable(){
    for(int i=0; i<tableSize; i++){ //traverse each node in the table
        if(table[i]){
            std::cout<<table[i]<<" ";
        }
    }
}

int HashTable::getNumOfCollision(){
    return this->numOfcollision;
}

int HashTable::searchItem(int key){ // return index
    int index = hashFunction(key);
    int i = 1;
    while(table[index] && table[index] != key){
        index = index + i*i;
    }

    if(table[index] == NULL){
        return -1; //not found
    }
    else{
        return index; //found
    }
}

HashTable::~HashTable(){
    delete[] table;
};
#include "hashQuadratic.hpp"
#include <iostream>

//HASHTABLE WITH QUADRATIC
HashQuadratic::HashQuadratic(int bsize){
    tableSize = bsize;
    currentSize = 0;
    table = new int[bsize];
    for(int i=0; i<bsize; i++){
        table[i] = NULL;
    }
    this->numOfCollision =0; 
    this->numOfSearchCollision=0;
} // Constructor                        

int HashQuadratic::getSizeOfTable(){
    return this->currentSize;
}

    // inserts a key into hash table
bool HashQuadratic::insertItem(int key){
    if(currentSize != tableSize){
        int index = hashFunction(key);

        int i = 1;
        while(table[index]){ //quadratic probing
            index = (index + i*i) % tableSize;
            i++;
            this->numOfCollision++;
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
unsigned int HashQuadratic::hashFunction(int key){
    return key%tableSize;
}

void HashQuadratic::printTable(){
    for(int i=0; i<tableSize; i++){ //traverse each node in the table
        if(table[i]){
            std::cout<<table[i]<<" ";
        }
    }
}

int HashQuadratic::getNumOfCollision(){
    return this->numOfCollision;
}
int HashQuadratic::getNumOfSearchCollision(){
    return this->numOfSearchCollision;
}
void HashQuadratic::resetNumCollision(){
    this->numOfCollision=0;
}
void HashQuadratic::resetNumSearchCollision(){
    this->numOfSearchCollision=0;
}

int HashQuadratic::searchItem(int key){ // return index
    int index = hashFunction(key);
    int i = 1;
    while(table[index] && table[index] != key){
        index = (index + i*i) % tableSize;
        i++;
        this->numOfSearchCollision++;
    }

    if(table[index] == NULL){
        return -1; //not found
    }
    else{
        return index; //found
    }
}

HashQuadratic::~HashQuadratic(){
    delete[] table;
};
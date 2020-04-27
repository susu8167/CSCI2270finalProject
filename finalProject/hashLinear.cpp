#include "hashLinear.hpp"
#include <iostream>

//HASHTABLE WITH QUADRATIC
HashLinear::HashLinear(int bsize){
    tableSize = bsize;
    currentSize = 0;
    table = new int[bsize];
    for(int i=0; i<bsize; i++){
        table[i] = NULL;
    }
    this->numOfCollision =0; 
    this->numOfSearchCollision=0;
} // Constructor                        

int HashLinear::getSizeOfTable(){
    return this->currentSize;
}

    // inserts a key into hash table
bool HashLinear::insertItem(int key){
       int index = hashFunction(key);
       while(table[index] && table[index]!=key && table[index]!=-1){
           index++;
           index%=tableSize;
           this->numOfCollision++;
       }
       if(!table[index]){
           currentSize++;
           table[index]=key;
           return true;
       }
       return false;
}

    // hash function to map values to key
unsigned int HashLinear::hashFunction(int key){
    return key%tableSize;
}

void HashLinear::printTable(){
    for(int i=0; i<tableSize; i++){ //traverse each node in the table
        if(table[i]){
            std::cout<<table[i]<<" ";
        }
    }
}

int HashLinear::getNumOfCollision(){
    return this->numOfCollision;
}
void HashLinear::resetNumCollision(){
    this->numOfCollision=0;
}
void HashLinear::resetNumSearchCollision(){
    this->numOfSearchCollision=0;
}
int HashLinear::getNumOfSearchCollision(){
    return this->numOfSearchCollision;
}
int HashLinear::searchItem(int key){ // return index
    int index = hashFunction(key);
    while(table[index] && table[index] != key){
        index++;
        index %= tableSize;
        this->numOfSearchCollision++;
    }

    if(table[index] == NULL){
        return -1; //not found
    }
    else{
        return index; //found
    }
}

HashLinear::~HashLinear(){
    delete[] table;
};
#include "hashChaining.hpp"
#include <iostream>
//HASHTABLE WITH CHAINING

HashTable::HashTable(int bsize){
    this->tableSize = bsize;
    this->currentSize = 0;
    this->numOfCollision =0; 
    this->numOfSearchCollision=0;
    this->table = new HashNode*[tableSize];
} // Constructor

HashNode* HashTable::createNode(int key, HashNode* next){
    HashNode* newNode = new HashNode;
    newNode->key=key;
    newNode->next=next;
    return newNode;
} 

int HashTable::getSizeOfTable(){
    return this->currentSize;
}

    // inserts a key into hash table
bool HashTable::insertItem(int key){
    int index = hashFunction(key);
    if(!this->table[index]){//inserting first node into a linked list
        this->table[index]=createNode(key,nullptr);
        return true;
    }
    else{
        HashNode* traversal = this->table[index];
        while(traversal->next){//finding endpoint to insert new node
            traversal=traversal->next;
        }
        traversal->next=createNode(key,nullptr);
        numOfCollision++; // num of collisions increase for every node inserted after the first
        return true;
    }
    return false;
}

    // hash function to map values to key
unsigned int HashTable::hashFunction(int key){
    return key%tableSize;
}

void HashTable::printTable(){
    for(int i=0; i<tableSize; i++){ //traverse each node in the table
        HashNode* traversal = this->table[i];
        while(traversal->next){ //traverse linked list
            std::cout << traversal->key << " -> ";
            
        }
        std::cout << "NULL" << std::endl;
    }
}

int HashTable::getNumOfCollision(){
    return this->numOfCollision;
}
void HashTable::resetNumCollision(){
    this->numOfCollision=0;
}
void HashTable::resetNumSearchCollision(){
    this->numOfSearchCollision=0;
}
int HashTable::getNumOfSearchCollision(){
    return this->numOfSearchCollision;
}

HashNode* HashTable::searchItem(int key){
    int index = hashFunction(key); // hash to determine which linked list to traverse
    HashNode* traversal = table[index];
    if(traversal->key==key){ //check if first node in LL is the correct node
        return traversal;
    }
    while(traversal->next){ // search through linked list
        if(traversal->key == key){
            return traversal;
        }
        traversal=traversal->next;
        numOfSearchCollision++; //increase num of collisions per every node searched after the first
    }
    return nullptr; // value was not found
}

HashTable::~HashTable(){
    for(int i=0 ; i<this->tableSize ; i++){
        while(this->table[i]){
            // set root to the next node in linked list
            HashNode* temp = this->table[i];
            this->table[i] = this->table[i]->next;

            //delete temp node
            delete temp;
        }
    }
}
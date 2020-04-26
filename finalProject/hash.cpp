#include "hashChaining.hpp"#include <list>
#include <iostream>
//HASHTABLE WITH CHAINING
HashTable::HashTable(int bsize){
    this->tableSize = bsize;
    this->currentSize = 0;
    this->table = new Node*[tableSize];
} // Constructor                        

Node* HashTable::createNode(int key, Node* next){
    Node* newNode = new Node;
    newNode->key=key;
    newNode->next=nullptr;
    return newNode;
} 

int HashTable::getSizeOfTable(){
    return this->currentSize;
}

    // inserts a key into hash table
bool HashTable::insertItem(int key){
    if(this->currentSize != this->tableSize){
        int index = hashFunction(key);

        // while(this->table[index]){ //linear probing
        //     index += 1;
        // }
        // this->table[index]->key = key;
        // currentSize++;

        // int i;
        // while(table[index]){ //quadratic probing
        //     index += i*i;
        //     i++;
        // }
        // this->table[index]->key = key;
        // currentSize++;
        // LL head = curr
        // 1 -> nullptr == no collision
        // 1 -> 2 -> nullptr == 1 collisionde* current = this->table[index];
        while(current){ //find tail of the linked list (nullptr)
            current = current->next;
            numOfcollision++;
        }
        current = createNode(key,nullptr);
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
        Node* traversal = this->table[i];
        while(traversal->next){ //traverse linked list
            std::cout << traversal->key << " -> ";
            
        }
        std::cout << "NULL" << std::endl;
    }
}



int HashTable::getNumOfCollision(){
    return this->numOfcollision;
}

Node* HashTable::searchItem(int key){
    int index = hashFunction(key); // hash to determine which linked list to traverse
    Node* traversal = table[index];
    while(traversal->next){ // search through linked list
        if(traversal->key == key){
            return traversal;
        }
        traversal=traversal->next;
    }
    return nullptr; // value was not found
}HashTable~HashtTable(){
    for(int i=0; i<this->tableSize; i++){;
        Node* traversal = this->table[i];
        while()
    }
} ; i++{}while())his->abl[]i]outstd::cout<<i]outstd::cout<<
e::~HaHashTable::shtabTe()){}le::shtabTe()){}e()){}
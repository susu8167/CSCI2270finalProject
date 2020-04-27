#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#pragma once
#include <iostream>


struct LLNode{
    int data;
    LLNode* next;
    LLNode(){
        data=NULL;
        next = nullptr;
    }
};

class linkedList{
    public:
        linkedList();
        void insertNode(int data); // ordered insert, 3 cases
        void printList(); 
        LLNode* search(int data);
        ~linkedList();
    private:
        LLNode* head = nullptr;
        //LLNode* tail;
};

#endif
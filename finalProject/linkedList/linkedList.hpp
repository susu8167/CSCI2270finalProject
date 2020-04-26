#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#pragma once
#include <iostream>


struct Node{
    int data;
    Node* next;
    Node(){
        data=NULL;
        next = nullptr;
    }
};

class linkedList{
    public:
        linkedList();
        void insertNode(int data); // ordered insert, 3 cases
        void printList(); 
        Node* search(int data);
        ~linkedList();
    private:
        Node* head = nullptr;
        //Node* tail;
};

#endif
#include "linkedList.hpp"
#include <iostream>

linkedList::linkedList(){
    head = nullptr;
    //potentially could implement a "tail" variable to decrease insert time
    //tail=nullptr;
}
/*
//alternate insert function (using tail)

void LinkedList::insertNode(int data){
    LLNode* newNode = new LLNode;
    newNode->data=data;
    if(!head){
        head = tail = newNode;
    }
    else{ 
    // this allows for O(1) insert time as we do not have to traverse the whole list to insert
    // this is an un-ordered insert (inserting at the end)
        tail->next = newNode;
        tail=newNode;
    }
}

*/
LLNode* getInsertPoint(LLNode* head){ //helper function for insertNode function to find end of list
    LLNode* crawler = head;
    while(crawler->next != nullptr){
        crawler=crawler->next;
    }
    return crawler;
}

void linkedList::insertNode(int data){// un-ordered insert at end of list, O(n) time
    LLNode* newNode = new LLNode;
    newNode->data=data;
    newNode->next=nullptr;
    if(!head){
        head=newNode;
    }
    else{
        LLNode* insertPoint = getInsertPoint(head);
        insertPoint->next = newNode;
    }
} 
/*
while (ptr->next != NULL)
        {
            cout << ptr->name << " -> ";
            ptr = ptr->next;
        }
        cout << ptr->name << " -> ";
        cout << "NULL" << endl;
*/

void linkedList::printList(){
    LLNode* crawler = head;
    while(crawler){
        std::cout<<crawler->data<<" -> ";
        crawler = crawler->next;
    }
    std::cout<<"NULL";
}

LLNode* linkedList::search(int data){
    LLNode* crawler = head;
    while(crawler && crawler->data != data){
        crawler = crawler->next;
    }
    return crawler;
} //return nullptr if data isn't found

linkedList::~linkedList(){
    LLNode* temp;
    while(head){
        temp = head;
        head = head->next;
        delete temp;
    }
}
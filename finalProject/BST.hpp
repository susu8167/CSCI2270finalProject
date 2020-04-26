#ifndef BST_H
#define BST_H

#pragma once

struct Node{
    int data;
    Node* left;
    Node* right;
    Node(){
        left = nullptr;
        right = nullptr;
        data=NULL;
    }
};

class BST{
    public:
        BST();// constructor
        void insert(int data);
        Node* search(int data);
        void printTree(); // using preorder traversal to print the order data is inserted in
        ~BST();
    private:
        Node* root;
};

#endif
#ifndef BST_H
#define BST_H
#include <iostream>
#pragma once

struct BSTNode{
    int data;
    BSTNode* left;
    BSTNode* right;
    BSTNode(){
        left = nullptr;
        right = nullptr;
        data=NULL;
    }
};

class BST{
    public:
        BST();// constructor
        void insert(int data);
        BSTNode* search(int data);
        void printTree(); // using preorder traversal to print the order data is inserted in
        ~BST();
    private:
        BSTNode* root;
};

#endif
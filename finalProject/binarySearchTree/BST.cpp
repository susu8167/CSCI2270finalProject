#include <iostream>
#include "BST.hpp"

BST::BST(){
    root = nullptr;
}

Node* newNode(int data){
    Node* newNode = new Node;
    newNode->data = data;
    newNode->left = newNode->right = nullptr;
    return newNode;
}
Node* insertHelper(Node* current, int data){
    if(!current){
        return newNode(data);
    }
    if(data > current->data){
        current->left = insertHelper(current->left, data);
    }
    else{
        current->right = insertHelper(current->right,data);
    }
    return current;
}

void BST::insert(int data){
    root = insertHelper(root,data);
}

Node* BST::search(int data){
    Node* current = root;
    while(current && current->data != data){
        if(current->data < data){ //go left
            current = current->left;
        }
        else if(current->data > data){ // go right
            current = current->right;
        }
    }
    //std::cout << current->key << std::endl;
    return current;
} //if data isn't in BST, return nullptr

void printTreeHelper(Node* current){
    // can achieve different traversal methods depending on order of function calls below
    if(current){
        printTreeHelper(current->left);
        std::cout<<current->data<<" -> ";
        printTreeHelper(current->right);
        
    }
}

void BST::printTree(){
    std::cout<<"preorder: ";
    printTreeHelper(root);
} // using inorder traversal to print the data in descending order

void deleteHelper(Node* current){
    if(current){
        deleteHelper(current->left);
        deleteHelper(current->right);
        delete current;
    }
}

BST::~BST(){
    deleteHelper(root);
}
#include <iostream>


class Node
{
    public: 
        int data;
        bool isBlack; 
        Node* left;
        Node* right;
        Node* parent;


        Node(int data) 
        {
            this->data = data;
            this->parent = NULL;
            this->left = NULL;
            this->right = NULL;
            this->isBlack = false;
        }
};
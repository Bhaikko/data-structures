#include <iostream>

class Node
{
    public: 
        int data;
        int height;
        Node* left;
        Node* right;


        Node(int data) 
        {
            this->data = data;
            this->left = NULL;
            this->right = NULL;
            this->height = 1;
        }
};
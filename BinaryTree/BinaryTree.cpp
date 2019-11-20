#include "BinaryTree.h"
#include <queue>

BinaryTree::BinaryTree()
{
    this->root = NULL;
}

Node* BinaryTree::treeInput(Node* root) 
{
    int input;
    std::cin >> input;

    if (input == -1) {
        return NULL;
    }

    root = new Node(input);
    root->left = this->treeInput(root->left);
    root->right = this->treeInput(root->right);

    return root;
}

void BinaryTree::input()
{
    this->root = this->treeInput(this->root);
}

void BinaryTree::treePreorderTraversal(Node* root)
{
    if (root == NULL) {
        return;
    }

    std::cout << root->data << " : ";
    std::cout << (root->left ? root->left->data : -1) << " " << (root->right ? root->right->data : -1) << std::endl;

    this->treePreorderTraversal(root->left);
    this->treePreorderTraversal(root->right);
}

void BinaryTree::preOrder()
{
    std::cout << "[+] Preorder Traversal" << std::endl;
    this->treePreorderTraversal(this->root);
}

void BinaryTree::levelWise()
{
    std::cout << "[+] Levelwise Traversal" << std::endl;
    if (this->root == NULL) {
        return;
    }

    std::queue<Node*>* pending = new std::queue<Node*>();
    Node* current = this->root;
    Node* newline = NULL;

    pending->push(current);
    pending->push(newline);

    while (true) {
        current = pending->front();
        
        if (current == newline) {
            std::cout << std::endl;
            pending->push(newline);
            pending->pop();
            if (pending->front() == newline) {
                break;
            }
 
        } else {
            std::cout << current->data << " ";

            if (current->left) {
                pending->push(current->left);
            } 

            if (current->right) {
                pending->push(current->right);
            } 

            pending->pop();
        }
    }
}
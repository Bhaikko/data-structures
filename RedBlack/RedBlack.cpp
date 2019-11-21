#include "RedBlack.h"
#include <algorithm>

RedBlack::RedBlack()
{
    this->root = NULL;
}

void RedBlack::right_rotate(Node* root, Node* current)
{
    Node* currentLeft = current->left;
    
    current->left = currentLeft->right;

    if (current->left != NULL) {
        current->left->parent = current;
    }

    currentLeft->parent = current->parent;
    if (current->parent == NULL) {
        root = currentLeft;
    } else if (current == current->parent->left) {
        current->parent->left = currentLeft;
    } else {
        current->parent->right = currentLeft;
    }

    currentLeft->right = current;
    current->parent = currentLeft;

}

void RedBlack::left_rotate(Node* root, Node* current)
{
    Node *currentRight = current->right; 

	current->right = currentRight->left; 

	if (current->right != NULL) 
		current->right->parent = current; 

	currentRight->parent = current->parent; 

	if (current->parent == NULL) 
		root = currentRight; 

	else if (current == current->parent->left) 
		current->parent->left = currentRight; 

	else
		current->parent->right = currentRight; 

	currentRight->left = current; 
	current->parent = currentRight; 
}

void RedBlack::fix_colors(Node* root, Node* current)
{
    Node* currentParent = NULL;
    Node* currentGrandparent = NULL;

    while ((current != root) && (!current->isBlack) && (!current->parent->isBlack)) {
        currentParent = current->parent;
        currentGrandparent = current->parent->parent;

        // Parent of current is left child of grandparent of current
        if (currentParent == currentGrandparent->left) {
            Node* currentUncle = currentGrandparent->right;

            // If Color of uncle is red, only recolor is required
            if (currentUncle != NULL && !currentUncle->isBlack) {
                currentGrandparent->isBlack = false;
                currentParent->isBlack = true;
                currentUncle->isBlack = true;
                current = currentGrandparent;
            } else {
                // current is right child of its parent
                // Left rotation required
                if (current == currentParent->right) {
                    this->left_rotate(root, currentParent);
                    current = currentParent;
                    currentParent = current->parent;
                }

                // current is left child of its parent
                // Right rotation required
                this->right_rotate(root, currentGrandparent);
                std::swap(currentParent->isBlack, currentGrandparent->isBlack);
                current = currentParent;

            }
        } else { // Parent of current is right child of grandparent of current 
            Node* currentUncle = currentGrandparent->left;

            // If Color of uncle is red, only recolor is required
            if (currentUncle != NULL && !currentUncle->isBlack) {
                currentGrandparent->isBlack = false;
                currentParent->isBlack = true;
                currentUncle->isBlack = true;
                current = currentGrandparent;
            } else {
                // current is right child of its parent
                // Right rotation required
                if (current == currentParent->left) {
                    this->right_rotate(root, currentParent);
                    current = currentParent;
                    currentParent = current->parent;
                }

                // current is right child of its parent
                // Left rotation required
                this->left_rotate(root, currentGrandparent);
                std::swap(currentParent->isBlack, currentGrandparent->isBlack);
                current = currentParent;

            }

        }
    }

    root->isBlack = true;
}

Node* RedBlack::insert_data(Node* root, Node* current)
{
    if (root == NULL) {
        return current;
    }

    if (current->data < root->data) {
        root->left = this->insert_data(root->left, current);
        root->left->parent = root;
    } else if (current->data > root->data) {
        root->right = this->insert_data(root->right, current);
        root->right->parent = root;
    }

    return root;
}

void RedBlack::insert_data(int data)
{
    Node* current = new Node(data);
    this->root = this->insert_data(this->root, current);
    this->fix_colors(this->root, current);
}

void RedBlack::print(Node* root)
{
    if (root == NULL) {
      return;
    }
    
    std::cout << root->data << " ";
    if (root->left != NULL) {
      this->print(root->left);
    }
    if (root->right != NULL) {
      this->print(root->right);
    }
}

void RedBlack::print()
{
    this->print(this->root);
    std::cout << std::endl;
}
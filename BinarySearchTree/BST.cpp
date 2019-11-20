#include "BST.h"

BST::BST()
{    this->root = NULL; }

bool BST::search(Node* root, int data) 
{
    if (root == NULL) {
        return false;
    }

    if (root->data == data) {
        return true;
    }

    if (data < root->data) {
        return this->search(root->left, data);
    } else {
        return this->search(root->right, data);
    }
}

bool BST::search(int data)
{   return this->search(this->root, data);  }

Node* BST::insertData(Node* root, int data)
{
    if (root == NULL) {
        root = new Node(data);
        return root;
    }

    if (data < root->data) {
        root->left = this->insertData(root->left, data);
    } else {
        root->right = this->insertData(root->right, data);
    }

    return root;
}

void BST::insertData(int data)
{    this->root = this->insertData(this->root, data);   }


Node* BST::deleteData(Node* root, int data)
{
    if (root == NULL) {
        return NULL;
    }

    if (root->data == data) {
        if (root->left == NULL && root->right == NULL) {
            delete root;
            return NULL;
        } else if (root->left == NULL && root->right != NULL) {
            Node* temp = root->right;
            delete root;
            return temp;
        } else if (root->left != NULL && root->right == NULL) {
            Node* temp = root->left;
            delete root;
            return temp;
        } else if (root->left != NULL && root->right != NULL) {
            Node* temp = root->right;

            while (temp->left != NULL) {
                temp = temp->left;
            } 
            int data = root->data;
            root->data = temp->data;
            temp->data = data;

            root->right = this->deleteData(root->right, data);
        }
    } else if (data < root->data) {
        root->left = this->deleteData(root->left, data);
    } else {
        root->right = this->deleteData(root->right, data);
    }

    return root;
}

void BST::deleteData(int data)
{   this->root = this->deleteData(this->root, data); }

void BST::print(Node* root)
{
    if (root == NULL) {
      return;
    }
    
    if (root->left != NULL && root->right != NULL) {
      std::cout << root->data << ":L:" << root->left->data << ",R:" << root->right->data << std::endl;
    } else if (root->left == NULL && root->right == NULL) {
      std::cout << root->data << ":" << std::endl;
    } else if (root->left==NULL) {
      std::cout << root->data << ":R:" << root->right->data << std::endl;
    }
    else if (root->right==NULL) {
      std::cout << root->data << ":L:" << root->left->data << "," <<std::endl;
    }
    
      
    if (root->left != NULL) {
      this->print(root->left);
    }
    if (root->right != NULL) {
      this->print(root->right);
    }
        
}

void BST::print() 
{
    std::cout << "###" << std::endl;   
    this->print(this->root);    
    std::cout << "###" << std::endl;   
}
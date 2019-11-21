#include "AVL.h"
#include <algorithm>

// utility function for height
int height(Node* node)
{ return node == NULL ? 0 : node->height; }


AVL::AVL()
{   this->root = NULL; }

int AVL::get_balance_factor(Node* root)
{
    return root == NULL ? 0 : height(root->left) - height(root->right);
}

Node* AVL::right_rotate(Node* y)
{
    Node* x = y->left;
    Node* T2 = x->right;

    // Perform Rotation
    x->right = y;
    y->left = T2;

    // Height Update
    y->height = std::max(height(y->left), height(y->right)) + 1;
    x->height = std::max(height(x->left), height(x->right)) + 1;

    return x;
}

Node* AVL::left_rotate(Node* x)
{
    Node* y = x->right;
    Node* T2 = y->left;

    // Perform Rotation
    y->left = x;
    x->right = T2;


    // Height Update
    x->height = std::max(height(x->left), height(x->right)) + 1;
    y->height = std::max(height(y->left), height(y->right)) + 1;

    return y;
}

Node* AVL::insert_data(Node* root, int data)
{
    if (root == NULL) {
        root = new Node(data);
        return root;
    }

    if (data < root->data) {
        root->left = this->insert_data(root->left, data);
    } else if (data > root->data) {
        root->right = this->insert_data(root->right, data);
    } else {
        // duplicates are not allowed in AVL trees
        return root;
    }

    root->height = 1 + std::max(height(root->left), height(root->right));

    int balanceFactor = this->get_balance_factor(root);

    // LL Rotation case
    if (balanceFactor > 1 && data < root->left->data) {
        return this->right_rotate(root);
    } 

    // RR Rotation Case
    if (balanceFactor < -1 && data > root->right->data) {
        return this->left_rotate(root);
    }

    // LR Rotation Case
    if (balanceFactor > 1 && data > root->left->data) {
        root->left = this->left_rotate(root->left);
        return this->right_rotate(root);
    }   

    // RL Rotation Case
    if (balanceFactor < -1 && data < root->right->data) {
        root->right = this->right_rotate(root->right);
        return this->left_rotate(root);
    }

    return root;

}

void AVL::insert_data(int data)
{
    this->root = this->insert_data(this->root, data);
}


Node* AVL::delete_data(Node* root, int data)
{
    if (root == NULL) {
        return root;
    }

    if (data < root->data) {
        root->left = this->delete_data(root->left, data);
    } else if (data > root->data) {
        root->right = this->delete_data(root->right, data);
    } else {
        if (root->left == NULL && root->right == NULL) {
            delete root;
            root =  NULL;
        } else if (root->left == NULL && root->right != NULL) {
            Node* temp = root->right;
            delete root;
            root = temp;
        } else if (root->left != NULL && root->right == NULL) {
            Node* temp = root->left;
            delete root;
            root = temp;
        } else if (root->left != NULL && root->right != NULL) {
            Node* temp = root->right;

            while (temp->left != NULL) {
                temp = temp->left;
            } 

            int data = root->data;
            root->data = temp->data;
            temp->data = data;

            root->right = this->delete_data(root->right, data);
        }
    }

    if (root == NULL) {
        return root;
    }

    root->height = 1 + std::max(height(root->left), height(root->right));
    int balanceFactor = this->get_balance_factor(root);


    // Left Left Case
    if (balanceFactor > 1 && this->get_balance_factor(root->left) >= 0) {
        return this->right_rotate(root);
    } 

    // Left Right Case
    if (balanceFactor > 1 && this->get_balance_factor(root->left) < 0) {
        root->left = this->left_rotate(root->left);
        return this->right_rotate(root);
    }

    // Right Right Case
    if (balanceFactor < -1 && this->get_balance_factor(root->right) <= 0) {
        return this->left_rotate(root);
    }

    // Right Left Case
    if (balanceFactor < -1 && this->get_balance_factor(root->right) > 0) {
        root->right = this->right_rotate(root->right);
        return this->left_rotate(root);
    }

    return root;

}

void AVL::delete_data(int data)
{
    this->root = this->delete_data(this->root, data);
}

void AVL::print(Node* root)
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

void AVL::print()
{
    this->print(this->root);
    std::cout << std::endl;
}
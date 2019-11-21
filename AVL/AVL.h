#include "Node.h"

class AVL
{
    private:
        Node* root;

    private:
        Node* left_rotate(Node* root);
        Node* right_rotate(Node* root);
        int get_balance_factor(Node* root);
        Node* insert_data(Node* root, int data);
        Node* delete_data(Node* root, int data);
        void print(Node* root);

    public:
        AVL();
        void insert_data(int data);
        void delete_data(int data);
        void print();
};
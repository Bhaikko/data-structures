#include "Node.h"

class RedBlack
{
    private:
        Node* root;
        void left_rotate(Node* root, Node* current);
        void right_rotate(Node* root, Node* current);
        Node* insert_data(Node* root, Node* data);
        Node* delete_data(Node* root, int data);
        void fix_colors(Node* root, Node* current);
        void print(Node* root);

    public:
        RedBlack();
        void insert_data(int data);
        void delete_data(int data);
        void print();

};
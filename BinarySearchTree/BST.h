#include "Node.h"

class BST
{
    private:
        Node* root;

    private:
        bool search(Node* root, int data);
        Node* insertData(Node* root, int data);
        Node* deleteData(Node* root, int data);
        void print(Node* root);

    public:
        BST();
        bool search(int input);
        void insertData(int data);
        void deleteData(int data);
        void print();
};
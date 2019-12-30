#include "Node.h"

class BTree
{
    private:
    Node* root;
    int minDegree;

    public:
    BTree(int minDegree) {
        this->root = NULL;
        this->minDegree = minDegree;
    }

    void insert(int key);
    void traverse() {
        if (this->root != NULL) {
            this->root->traverse();
            std::cout << std::endl;
        }
    }

    Node* search(int key) {
        return (this->root == NULL) ? NULL : this->root->search(key);
    }
};

void BTree::insert(int key)
{
    if (this->root == NULL) {
        this->root = new Node(this->minDegree, true);
        this->root->keys->at(0) = key;
        this->root->numberOfKeys = 1;
    } else {
        if (this->root->numberOfKeys == 2 * this->minDegree - 1) {
            Node* newNode = new Node(this->minDegree, false);
            newNode->childPointers->at(0) = this->root;
            newNode->split_child(0, this->root);

            int i = 0;
            if (newNode->keys->at(0) < key) {
                i++;
            }
            newNode->childPointers->at(i)->insert_non_full(key);
            this->root = newNode;
        } else {
            this->root->insert_non_full(key);
        }
    }
}
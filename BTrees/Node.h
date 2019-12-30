#include <iostream>
#include <vector>

class Node
{
    public:
    std::vector<int>* keys;
    int minDegree;

    std::vector<Node*>* childPointers;
    int numberOfKeys;
    bool isLeaf;

    Node(int minDegree, bool isLeaf);

    void insert_non_full(int key);
    void split_child(int i, Node* current);
    void traverse();
    Node* search(int key);
};

Node::Node(int minDegree, bool isLeaf)
{
    this->minDegree = minDegree;
    this->isLeaf = isLeaf;

    this->keys = new std::vector<int>(2 * minDegree - 1); // Since a node can have minimum Math::ceil(maxDegree / 2)
    this->childPointers = new std::vector<Node*>(2 * minDegree);  // Children has to be equal to maxDegree

    this->numberOfKeys = 0;
}

void Node::insert_non_full(int key)
{
    // Since the node is inserted bottom up, we first insert key at the bottom then spilt the node according to it
    int i = numberOfKeys - 1;

    if (this->isLeaf) {
        // Inserting to be insertedKey at right position in node
        while (i >= 0 && this->keys->at(i) > key) {
            this->keys->at(i + 1) = this->keys->at(i);
            i--;
        }

        this->keys->at(i + 1) = key;
        this->numberOfKeys++;
    } else {
        while (i >= 0 && this->keys->at(i) > key) {
            i--;
        }

        if (this->childPointers->at(i + 1)->numberOfKeys == 2 * this->minDegree - 1) {
            this->split_child(i + 1, this->childPointers->at(i + 1));

            if (this->keys->at(i + 1) < key) {
                i++;
            }
        }

        this->childPointers->at(i + 1)->insert_non_full(key);
    }
}

void Node::split_child(int i, Node* current)
{
    Node* newNode = new Node(current->minDegree, current->isLeaf);
    newNode->numberOfKeys = this->minDegree - 1;

    for (int j = 0; j < this->minDegree - 1; j++) {
        newNode->keys->at(j) = current->keys->at(j + this->minDegree);
    }

    if (!current->isLeaf) {
        for (int j = 0; j < this->minDegree; j++) {
            newNode->childPointers->at(j) = current->childPointers->at(j + this->minDegree);
        }
    }

    current->numberOfKeys = this->minDegree - 1;

    for (int j = this->numberOfKeys; j >= i + 1; j--) {
        this->childPointers->at(j + 1) = this->childPointers->at(j);
    }

    this->childPointers->at(i + 1) = newNode;

    for (int j = this->numberOfKeys - 1; j >= i; j--) {
        this->keys->at(j + 1) = this->keys->at(j);
    }

    this->keys->at(i) = current->keys->at(this->minDegree - 1);

    this->numberOfKeys++;
}

void Node::traverse()
{
    int i;
    for (i = 0; i < this->numberOfKeys; i++) {
        if (!this->isLeaf) {
            this->childPointers->at(i)->traverse();
        }

        std::cout << " " << this->keys->at(i);
    }

    if (!this->isLeaf) {
        this->childPointers->at(i)->traverse();
    }
}

Node* Node::search(int key)
{
    int i = 0;
    while (i < this->numberOfKeys && key > this->keys->at(i)) {
        i++;
    }

    if (this->keys->at(i) == key) {
        return this;
    }

    if (this->isLeaf) {
        return NULL;
    }

    return this->childPointers->at(i)->search(key);
}
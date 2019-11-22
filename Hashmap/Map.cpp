#include "Map.h"

Map::Map()
{
    this->bucketSize = 10;
    this->count = 0;
    this->bucket = new Node*[bucketSize];
    for (int i = 0; i < bucketSize; i++) {
        this->bucket[i] = NULL;
    }
}

int Map::hash(std::string key)
{
    long hashcode = 0;
    long currentFactor = 1;
    for (int i = key.size() - 1; i >= 0; i--) {
        hashcode += key[i]* currentFactor;
        currentFactor *= 257;
    }

    return hashcode % this->bucketSize;
}

void Map::resize_bucket()
{
    Node** newBucket = this->bucket;
    this->bucket = new Node*[2 * this->bucketSize];
    this->bucketSize *= 2;

    for (int i = 0; i < this->bucketSize; i++) {
        this->bucket[i] = NULL;
    }
    this->count = 0;

    for (int i = 0; i < this->bucketSize / 2; i++) {
        Node* head = newBucket[i];
        while (head != NULL) {
            this->insert_data(head->key, head->value);
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
}

void Map::insert_data(std::string key, int value)
{
    int keyHash = this->hash(key);

    Node* head = this->bucket[keyHash];

    if (head == NULL) {
        Node* newNode = new Node(key, value);
        this->bucket[keyHash] = newNode;
        this->count++;
    } else {
        Node* temp = head;
        Node* prev = NULL;
        
        while (temp != NULL)
        {
            // Key already exists, that means we are overwriting data
            if (temp->key == key) {
                temp->value = value;
                return;
            } 
            // new key value pair is added by user
            prev = temp;
            temp = temp->next;
        }

        Node* newNode = new Node(key, value);
        prev->next = newNode;
        this->count++;
    }

    double loadFactor = (1.0 * this->count) / this->bucketSize;
    if (loadFactor >= 0.75) {
        this->resize_bucket();
    }
}

void Map::erase_data(std::string key)
{
    int keyhash = this->hash(key);
    Node* head = this->bucket[keyhash];

    if (head == NULL) {
        return;
    }

    Node* temp = head;
    Node* prev = NULL;

    while (temp != NULL) {
        if (temp->key == key) {
            if (prev == NULL) {
                this->bucket[keyhash] = temp->next;
            } else {
                prev->next = temp->next; 
            }
            this->count--;
            delete temp;
            return;
        }
        prev = temp;
        temp = temp->next;
    }
}

int Map::search(std::string key)
{
    int keyhash = this->hash(key);

    Node* head = this->bucket[keyhash];
    if (head == NULL) {
        return -1;
    }

    Node* temp = head;
    while (temp != NULL) {
        if (temp->key == key) {
            return temp->value;
        }
        temp = temp->next;
    }

    return -1;
}


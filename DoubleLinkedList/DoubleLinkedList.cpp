#include "DoubleLinkedList.h"

DoubleLinkedList::DoubleLinkedList()
{
    this->front = NULL;
    this->back = NULL;
    this->length = 0;
}

void DoubleLinkedList::add_front(int data)
{
    if (this->front == NULL && this->back == NULL) {
        this->front = new Node(data);
        this->back = this->front;
    } else {
        Node* newNode = new Node(data);
        newNode->next = this->front;
        this->front->prev = newNode;
        this->front = newNode;
        this->length++;
    }
}

void DoubleLinkedList::add_end(int data)
{
    if (this->front == NULL && this->back == NULL) {
        this->front = new Node(data);
        this->back = this->front;
    } else {
        Node* newNode = new Node(data);
        this->back->next = newNode;
        newNode->prev = this->back;
        this->back = newNode;
        this->length--;
    }
}

void DoubleLinkedList::forward_traverse()
{
    Node* temp = this->front;

    while(temp != NULL) {
        std::cout << temp->data << " ";
        temp = temp->next;
    }

    std::cout << std::endl;

}

void DoubleLinkedList::backward_traverse()
{
    Node* temp = this->back;

    while(temp != NULL) {
        std::cout << temp->data << " ";
        temp = temp->prev;
    }

    std::cout << std::endl;

}

void DoubleLinkedList::delete_node_from_front(int index)
{
    if (index == 0) {
        Node* temp = this->front;
        this->front = this->front->next;
        delete temp;
        return;
    } else if (index == this->length - 1){
        Node* temp = this->back;
        back = back->prev;
        delete temp;
        return;
    }

    Node* temp = this->front;
    for (int i = 0; i < index; i++) {
        temp = temp->next;
    }

    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    delete temp;

}
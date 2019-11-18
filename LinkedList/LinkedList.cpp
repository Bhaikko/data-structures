#include "./LinkedList.h"

LinkedList::LinkedList()
{
    this->head = NULL;
    this->tail = NULL;
}

void LinkedList::insertNode(int data)
{
    if (this->head == NULL && this->tail == NULL) {
        head = new Node(data);
        tail = head;
    } else {
        tail->next = new Node(data);
        tail = tail->next;
    }
}

Node* LinkedList::deleteNodeRecursive(Node* head, int index)
{
    if (index == 0) {
        return head->next;
    }

    Node* currentHead = this->deleteNodeRecursive(head->next, index - 1);
    head->next = currentHead;

    return head;
}

void LinkedList::deleteNode(int index) 
{
    this->head = this->deleteNodeRecursive(this->head, index);
}

int LinkedList::length()
{
    Node* temp = this->head;
    int count = 0;

    while (temp != NULL) {
        count++;
        temp = temp->next;
    }

    delete temp;
    return count;
}

void LinkedList::printList()
{
    Node* temp = this->head;

    while(temp != NULL)
    {
        std::cout << temp->data << " ";
        temp = temp->next;
    }
    std::cout << std::endl;

    delete temp;
}

Node* LinkedList::reverseRecursive(Node* head)
{
    if (head == NULL || head->next == NULL) {
        return head;
    }
    Node* smallHead = this->reverseRecursive(head->next);
    Node* temp = head->next;
    temp->next = head;
    head->next = NULL;

    return smallHead;
}

LinkedList* LinkedList::reverse()
{
    Node* reversedHead = this->reverseRecursive(this->head);
    Node* temp = reversedHead;
    LinkedList* reversedList = new LinkedList();

    while (temp != NULL) {
        reversedList->insertNode(temp->data);
        temp = temp->next;
    }

    return reversedList;
}
#include "./Node.h"

class LinkedList
{
    private:
        Node* head;
        Node* tail;

    private:
        Node* deleteNodeRecursive(Node* head, int index);
        Node* reverseRecursive(Node* head);

    public:
        LinkedList();
        void insertNode(int data);
        void deleteNode(int index);
        LinkedList* reverse();
        int length();
        void printList();

};
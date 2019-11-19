#include "Node.h"

class DoubleLinkedList
{
    private:
        Node* front;
        Node* back;
        int length;

    public:
        DoubleLinkedList();
        void add_front(int data);
        void add_end(int data);
        void delete_node_from_front(int index);
        void forward_traverse();
        void backward_traverse();
};
#include <iostream>

template <typename T>
class Node
{
    public:
        T data;
        Node<T>* next;

        Node<T>(T data);
};


template <typename T>
Node<T>::Node(T data)
{
    this->data = data;
    this->next = NULL;
}

#include "Node.h"

template <class T>
Node<T>::Node(T data)
{
    this->data = data;
    this->next = NULL;
}

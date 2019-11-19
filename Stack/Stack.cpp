// #include "Stack.h"

// template <class T>
// Stack<T>::Stack()
// {
//     this->size = 0;
//     this->top = NULL;
// }

// template <class T>
// void Stack<T>::push(T data)
// {
//     if (this->size == 0) {
//         this->top = new Node<T>(data);
//     } else {
//         Node<T>* topNode = new Node<T>(data);
//         topNode->next = this->top;
//         this->top = topNode;
//     }
//     this->size++;
// }

// template <class T>
// void Stack<T>::pop()
// {
//     if (this-size == 0) {
//         return;
//     }

//     Node<T>* temp = this->top;
//     this->top = this->top->next;
//     delete temp;
//     this->size--;
// }

// template <class T>
// T Stack<T>::topElement()
// {
//     return this->top->data;
// }
#include "Node.h"

template <typename T>
class Stack
{
    private:
        Node<T>* top;
        int size;

    public:
        Stack<T>();
        void push(T data);
        void pop();

        T topElement() { return top->data; }
        int length() { return size; }

        template<class X>
        friend std::ostream& operator << (std::ostream& os, Stack<X>* stack); 

}; 

template <typename T>
std::ostream& operator << (std::ostream& os, Stack<T>* stack)
{
    Stack<T>* temp = new Stack<T>();
    while (stack->length() != 0) {
        temp->push(stack->topElement());
        os << stack->topElement() << "\n";
        stack->pop();
    }

    while (temp->length() != 0) {
        stack->push(temp->topElement());
        temp->pop();
    }

    return os;
}

template <typename T>
Stack<T>::Stack()
{
    this->size = 0;
    this->top = NULL;
}

template <typename T>
void Stack<T>::push(T data)
{
    if (this->size == 0) {
        this->top = new Node<T>(data);
    } else {
        Node<T>* topNode = new Node<T>(data);
        topNode->next = this->top;
        this->top = topNode;
    }
    this->size++;
}

template <typename T>
void Stack<T>::pop()
{
    if (this-size == 0) {
        return;
    }

    Node<T>* temp = this->top;
    this->top = this->top->next;
    delete temp;
    this->size--;
}


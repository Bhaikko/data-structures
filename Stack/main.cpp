#include "Stack.h"

int main()
{
    Stack<int>* stack = new Stack<int>();

    stack->push(1);
    stack->push(2);
    stack->push(3);
    stack->push(4);
    stack->push(5);

    std::cout << stack;

    stack->pop();
    stack->pop();
    stack->pop();
    std::cout << stack;
}
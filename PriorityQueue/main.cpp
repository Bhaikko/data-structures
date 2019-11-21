#include "PriorityQueue.h"

int main()
{
    PriorityQueue* queue = new PriorityQueue();

    queue->push(5);
    queue->push(4);
    queue->push(3);
    queue->push(2);
    queue->push(1);

    std::cout << queue->pop() << std::endl;
    std::cout << queue->pop() << std::endl;
    std::cout << queue->pop() << std::endl;
    std::cout << queue->pop() << std::endl;
    std::cout << queue->pop() << std::endl;
    std::cout << queue->pop() << std::endl;

    return 0;
}
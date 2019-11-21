#include "PriorityQueue.h"

PriorityQueue::PriorityQueue()
{
    this->heap = new std::vector<int>();
}

void PriorityQueue::heapify(int index)
{

    int leftChild = 2 * index + 1;
    int rightChild = 2 * index + 2;
    
    if (leftChild >= this->heap->size()) {
        return;
    }

    int minIndex = index;

    if (this->heap->at(leftChild) < this->heap->at(minIndex)) {
        minIndex = leftChild;
    }

    if (rightChild < this->heap->size() && this->heap->at(rightChild) < this->heap->at(minIndex)) {
        minIndex = rightChild;
    }

    if (minIndex != index) {
        std::swap(this->heap->at(minIndex), this->heap->at(index));
        this->heapify(minIndex);
    }
}

void PriorityQueue::push(int data)
{
    this->heap->push_back(data);
    int child = this->heap->size() - 1;

    while (child > 0) {
        int parent = (child - 1) / 2;
        if (this->heap->at(child) < this->heap->at(parent)) {
            std::swap(this->heap->at(child), this->heap->at(parent));
            child = parent;
        } else {
            break;
        }
    }
}


int PriorityQueue::pop()
{
    if (this->heap->empty()) {
        return INT_MIN;
    } else {
        int temp = this->heap->at(0);
        std::swap(this->heap->at(0), this->heap->at(this->heap->size() - 1));
        this->heap->pop_back();
        this->heapify(0);

        return temp;
    }


}
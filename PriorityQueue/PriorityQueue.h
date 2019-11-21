#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

// Min PriorityQueue
class PriorityQueue
{
    private:
        std::vector<int>* heap;
        void heapify(int index);

    public:
        PriorityQueue();
        void push(int data);
        int pop();
};
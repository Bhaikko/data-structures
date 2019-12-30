#include <iostream>
#include <algorithm>

struct Object
{
    int profit;
    int weight;
    float profitPerWeight;
};

float fractionalKnapsack(Object objects[], int size, int maxWeight)
{
    for (int i = 0; i < size; i++) {
        objects[i].profitPerWeight = (objects[i].profit * 1.0) / (objects[i].weight * 1.0);
    }

    std::sort(objects, objects + size, [](Object first, Object second) -> bool {
        return first.profitPerWeight > second.profitPerWeight; 
    });

    float profit = 0;
    for (int i = 0; i < size; i++) {
        if (objects[i].weight <= maxWeight) {
            profit += objects[i].profit;
            maxWeight -= objects[i].weight;
        } else {
            profit += objects[i].profitPerWeight * maxWeight;
            break;
        }
    }

    return profit;
}

int main()
{
    int size = 7;
    Object objects[size] = {
        {10, 2},
        {5, 3},
        {15, 5},
        {6, 1},
        {7, 7},
        {18, 4},
        {3, 1}
    };

    std::cout << fractionalKnapsack(objects, size, 15) << std::endl;
}
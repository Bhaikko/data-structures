#include <iostream>
#include <climits>
#include <algorithm>

int rodcutRecursive(int arr[], int size)
{
    if (size == 0) {
        return 0;
    }

    int maxPrice = INT_MIN; 
    for (int i = 1; i <= size; i++) {
        maxPrice = std::max(maxPrice, arr[i] + rodcutRecursive(arr, size - i));
    }

    return maxPrice;
}

int rodcutMemotization(int arr[], int size, int calculated[])
{
    if (calculated[size] >= 0) {
        return calculated[size];
    }

    if (size == 0) {
        return 0;
    }

    int maxPrice = INT_MIN;
    for (int i = 1; i <= size; i++) {
        maxPrice = std::max(maxPrice, arr[i] + rodcutMemotization(arr, size - i, calculated));
    }

    calculated[size] = maxPrice;
    return maxPrice;
}

int rodcutMemotization(int arr[], int size)
{
    int calculated[size];
    for (int i = 0; i <= size; i++) {
        calculated[i] = INT_MIN;
    }

    return rodcutMemotization(arr, size, calculated);
}

int rodcutDynamic(int arr[], int size)
{
    int calculated[size + 1];

    calculated[0] = 0;

    for (int i = 1; i <= size; i++) {
        int maxPrice = INT_MIN;
        for (int j = 1; j <= i; j++) {
            maxPrice = std::max(maxPrice, arr[j] + calculated[i - j]);
        }
        calculated[i] = maxPrice;
    }

    return calculated[size];
}


int main()
{
    int size = 5;
    int arr[size] = {0, 1, 5, 8, 9, 2};


    std::cout << rodcutRecursive(arr, size - 1) << std::endl;
    std::cout << rodcutMemotization(arr, size - 1) << std::endl;
    std::cout << rodcutDynamic(arr, size - 1) << std::endl;

    return 0;
}


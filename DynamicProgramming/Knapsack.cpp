#include <iostream>
#include <algorithm>

int knapsack(int weights[], int values[], int size, int maxWeight)
{
    int profit[size + 1][maxWeight + 1];

    for (int i = 0; i <= maxWeight; i++) {
        profit[0][i] = 0;
    }

    for (int i = 0; i <= size; i++) {
        profit[i][0] = 0;
    }

    for (int i = 1; i <= size; i++) {
        for (int j = 1; j <= maxWeight; j++) {

            if (weights[i - 1] <= j) {
                profit[i][j] = std::max(
                    profit[i - 1][j], 
                    profit[i - 1][j - weights[i - 1]] + values[i - 1]
                );
            } else {
                profit[i][j] = profit[i - 1][j];
            }
        }
    }

    return profit[size][maxWeight];
}


int main()
{
    int size = 4;
    int maxWeight = 8;
    int weights[] = {2, 3, 4, 5};
    int values[] = {1, 2, 5, 6};

    std::cout << knapsack(weights, values, size, maxWeight) << std::endl;

    return 0;
}
#include <iostream>
#include <climits>

int calculateFrequency(int start, int end, int freq[])
{
    int sum = 0;
    for (int i = start; i <= end; i++) {
        sum += freq[i];
    }

    return sum;
}

int optimalBST(int keys[], int freq[], int size)
{
    int costs[size][size];
    // int roots[size + 1][size + 1];

    for (int i = 0; i < size; i++) {
        costs[i][i] = freq[i];
    }

    for (int L = 2; L <= size; L++) {
        for (int i = 0; i <= size - L + 1; i++) {   // since lower diagonal triangle is not filled, upper half is filled only

            int j = i + L - 1;
            costs[i][j] = INT_MAX;
            
            for (int r = i; r <= j; r++) {
                int calculatedCost = ((r > i) ? costs[i][r - 1] : 0) + ((r < j) ? costs[r + 1][j] : 0) + calculateFrequency(i, j, freq);
            
                if (calculatedCost < costs[i][j]) {
                    costs[i][j] = calculatedCost;
                }
            }
        }
    }

    return costs[0][size - 1];
}

int main()
{
    int keys[] = {10, 20, 30, 40};
    int freq[] = {4, 2, 6, 3};

    int size = 4;

    std::cout << optimalBST(keys, freq, size) << std::endl;

    return 0;
}
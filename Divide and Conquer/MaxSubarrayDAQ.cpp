#include <iostream>
#include <algorithm>
#include <climits>

int maxCrossingSum(int arr[], int start, int mid, int end)
{
    int sum = 0;
    int leftSum = INT_MIN;
    for (int i = mid; i >= start; i--) {
        sum += arr[i];
        if (sum > leftSum) {
            leftSum = sum;
        }
    }

    sum = 0;
    int rightSum = INT_MIN;
    for (int i = mid + 1; i <= end; i++) {
        sum += arr[i];
        if (sum > rightSum) {
            rightSum = sum;
        }
    }

    return leftSum + rightSum;
}

int maxSubArray(int arr[], int start, int end)
{
    if (start == end) {
        return arr[start];
    }

    int mid = (start + end) / 2;

    return std::max(
        std::max(
            maxSubArray(arr, start, mid), 
            maxSubArray(arr, mid + 1, end)
        ), 
        maxCrossingSum(arr, start, mid, end)
    );
}

int main()
{
    int size = 6;
    int arr[size] = {-1, 3, 4, -5, 9, -2};

    std::cout << maxSubArray(arr, 0, size - 1) << std::endl;    

    return 0;
}
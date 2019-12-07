#include <iostream>
#include <algorithm>

int randomPartition(int arr[], int start, int end)
{
    int pivotIndex = start + rand() % (end - start + 1);
    int pivot = arr[pivotIndex];
    std::swap(arr[pivotIndex], arr[end]);
    pivotIndex = end;

    int i = start - 1;

    for (int j = start; j < end; j++) {
        if (arr[j] <= pivot) {
            i++;
            std::swap(arr[i], arr[j]);
        }
    }

    std::swap(arr[i + 1], arr[pivotIndex]);
    return i + 1;
}

int randomSelection(int arr[], int start, int end, int k)
{
    if (start == end) {
        return arr[start];
    }

    if (k == 0) {
        return -1;
    }

    if (start < end) {
        int mid = randomPartition(arr, start, end);
        int i = mid - start + 1;

        if (i == k) {
            return arr[mid];
        } else if (k < i) {
            return randomSelection(arr, start, mid - 1, k);
        } else {
            return randomSelection(arr, mid + 1, end, k - i);
        }
    }
}

int main()
{
    int arr[] = {9, 5, 7, 1, 10, 2, 3};
    int size = 7;

    std::cout << randomSelection(arr, 0, size - 1, 2) << std::endl;

    return 0;
}
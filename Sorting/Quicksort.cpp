#include <iostream>
#include <algorithm>


int findPivot(int arr[], int start, int end)
{
    int pivotIndex = start;
    int pivotElement = arr[pivotIndex];

    for (int i = start; i <= end; i++) {
        if (arr[i] < pivotElement) {
            pivotIndex++;
        }
    }

    std::swap(arr[start], arr[pivotIndex]);

    int left = start;
    int right = end;

    while (left <= pivotIndex - 1 && right >= pivotIndex + 1) {
        if (arr[left] >= pivotElement) {
            if (arr[right] < pivotElement) {
                std::swap(arr[left], arr[right]);
                left++;
                right--;
            } else {
                right--;
            } 
        } else {
            left++;
        }
    }

    return pivotIndex;
}

void quickSort(int arr[], int start, int end)
{
    if (start >= end) {
        return;
    }

    int pivotIndex = findPivot(arr, start, end);
    quickSort(arr, start, pivotIndex - 1);
    quickSort(arr, pivotIndex + 1, end);
}

int main()
{
    int arr[] = {12, 11, 13, 5, 6, 7}; 
	int size = sizeof(arr)/sizeof(arr[0]); 

    quickSort(arr, 0, size - 1);

    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }

    std::cout << std::endl;

    return 0;
}
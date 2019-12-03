#include <iostream>
#include <algorithm>

void heapify(int arr[], int size, int index)
{
    int largestIndex = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < size && arr[left] > arr[largestIndex]) {
        largestIndex = left;
    }

    if (right < size && arr[right] > arr[largestIndex]) {
        largestIndex = right;
    }

    if (largestIndex != index) {
        std::swap(arr[index], arr[largestIndex]);
        heapify(arr, size, largestIndex);
    }
}

void heapsort(int arr[], int size)
{
    for (int i = size / 2 - 1; i >= 0; i--) {
        heapify(arr, size, i);
    }

    for (int i = size - 1; i >= 0; i--) {
        std::swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

int main()
{
    int arr[] = {12, 11, 13, 5, 6, 7}; 
	int size = sizeof(arr)/sizeof(arr[0]); 

	heapsort(arr, size); 


    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }

    std::cout << std::endl;

    return 0;
}
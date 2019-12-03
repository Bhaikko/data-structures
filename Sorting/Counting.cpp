#include <iostream>

#define RANGE 255

void countSort(int arr[], int size)
{
    int output[size];

    int count[RANGE + 1];
    
    for (int i = 0; i <= RANGE; i++) {
        count[i] = 0;
    }

    for (int i = 0; i < size; i++) {
        count[arr[i]]++;
    }

    for (int i = 1; i <= RANGE; i++) {
        count[i] += count[i - 1];
    }

    for (int i = 0; i < size; i++) {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }

    for (int i = 0; i < size; i++) {
        arr[i] = output[i];
    }
}

int main()
{
    int arr[] = {12, 11, 13, 5, 6, 7}; 
	int size = sizeof(arr)/sizeof(arr[0]); 

	countSort(arr, size); 


    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }

    std::cout << std::endl;

    return 0;
}
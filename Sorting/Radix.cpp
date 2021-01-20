#include <iostream>

int GetMax(int arr[], int size) 
{
    int max = arr[0];
    for (int i = 0; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }

    return max;
}

void CountSort(int arr[], int size, int exp)
{
    int output[size];
    int count[10] = {0};

    for (int i = 0; i < size; i++) {
        count[(arr[i] / exp) % 10]++;
    }

    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    for (int i = size - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    for (int i = 0; i < size; i++) {
        arr[i] = output[i];
    }
}

void Radixsort(int arr[], int size)
{
    int max = GetMax(arr, size);

    for (int exp = 1; max / exp > 0; exp *= 10) {
        CountSort(arr, size, exp);
    }
}


int main()
{
    int arr[] = { 12, 11, 13, 5, 6, 7 }; 
	int size = sizeof(arr) / sizeof(arr[0]); 

	Radixsort(arr, size); 

    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }

    std::cout << std::endl;

    return 0;
}
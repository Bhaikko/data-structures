#include <iostream>

void mergeSort(int arr1[], int size1, int arr2[], int size2, int ans[])
{
    int arrIndex1 = 0;
    int arrIndex2 = 0;
    int ansIndex = 0;

    while (arrIndex1 < size1 && arrIndex2 < size2) {
        if (arr1[arrIndex1] < arr2[arrIndex2]) {
            ans[ansIndex++] = arr1[arrIndex1++];
        } else {
            ans[ansIndex++] = arr2[arrIndex2++];
        }
    }

    while (arrIndex1 < size1) {
        ans[ansIndex++] = arr1[arrIndex1++]; 
    } 

    while (arrIndex2 < size2) {
        ans[ansIndex++] = arr2[arrIndex2++];
    }
}

void mergeSort(int arr[], int size) 
{
    if (size == 1) {
        return;
    }

    int mid = size / 2;

    int size1 = mid;
    int size2 = size - mid;

    int arr1[size1];
    int arr2[size2];

    for (int i = 0; i < size1; i++) {
        arr1[i] = arr[i];
    }

    int k = 0;
    for (int i = mid; i < size; i++) {
        arr2[k++] = arr[i];
    }

    mergeSort(arr1, size1);
    mergeSort(arr2, size2);

    int output[size];
    
    mergeSort(arr1, size1, arr2, size2, output);

    for (int i = 0; i < size; i++) {
        arr[i] = output[i];
    }

}

int main()
{
    int arr[] = {6, 5, 4, 3, 2, 1};
    int size = 6;

    mergeSort(arr, size);

    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
    return 0;


}
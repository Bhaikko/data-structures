#include <iostream>
#include <algorithm>
#include <time.h>

void BubbleSort(int arr[], int n)  
{  
    int i, j;  
    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                std::swap(arr[j], arr[j+1]);  
            }
        } 
    }
}  
  
void PrintArray(int arr[], int size)  
{  
    std::cout << std::endl;  
    int i;  
    for (i = 0; i < size; i++) {
        std::cout << arr[i] << " ";  
    }
    std::cout << std::endl;  
}  

int* GetNewSizeArray(int n)
{
    int* newArray = new int[n];

}

  
int main()  
{  
    int arr[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};  
    int n = sizeof(arr) / sizeof(arr[0]);  

    time_t startTime = time(NULL);
        BubbleSort(arr, n);  
    std::cout << "Time Taken: " << difftime(time(NULL), startTime) << std::endl;

    PrintArray(arr, n);  
    return 0;  
}  
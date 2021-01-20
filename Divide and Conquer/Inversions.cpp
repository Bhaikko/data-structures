#include <iostream>

int merge(int arr[], int temp[], int start, int mid, int end)
{
    int i = start;
    int j = mid;
    int k = start;
    int count = 0;

    while ((i <= mid - 1) && (j <= end)) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
            count += mid - i;
        }
    }

    while (i <= mid - 1) {
        temp[k++] = arr[i++];
    }

    while (j <= end) {
        temp[k++] = arr[j++];
    }

    for (i = start; i <= end; i++) {
        arr[i] = temp[i];
    }

    return count;
}

int mergeSort(int arr[], int temp[], int start, int end)
{
    int mid, count = 0;
    if (end > start) {
        mid = (start + end) / 2;

        // counting in left half
        count += mergeSort(arr, temp, start, mid);
        
        // counting in right half
        count += mergeSort(arr, temp, mid + 1, end);

        // counting in combination
        count += merge(arr, temp, start, mid + 1, end);
    }

    return count;

}

int mergeSort(int arr[], int size)
{
    int temp[size];
    return mergeSort(arr, temp, 0, size - 1);
}

int main()
{
    int arr[] = { 1, 20, 6, 4, 5 }; 
	int n = sizeof(arr) / sizeof(arr[0]); 
	int ans = mergeSort(arr, n); 
	std::cout << ans << std::endl; 
	return 0; 
}
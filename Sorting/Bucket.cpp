#include <iostream>
#include <vector>
#include <algorithm>

void bucketSort(float arr[], int n)
{
    std::vector<float> bucket[n];

    for (int i = 0; i < n; i++) {
        int bucketIndex = n * arr[i];
        bucket[bucketIndex].push_back(arr[i]);
    }

    for (int i = 0; i < n; i++) {
        std::sort(bucket[i].begin(), bucket[i].end());
    }

    int index = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < bucket[i].size(); j++) {
            arr[index++] = bucket[i][j];
        }
    }
}

int main() 
{ 
	float arr[] = {0.897, 0.565, 0.656, 0.1234, 0.665, 0.3434}; 
	int n = sizeof(arr)/sizeof(arr[0]); 
	bucketSort(arr, n); 

	for (int i=0; i<n; i++) {
	    std::cout << arr[i] << " "; 
    }
    
	return 0; 
} 
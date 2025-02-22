#include <iostream>
using namespace std;

void CountSort(int arr[], int n, int pos) {
    int frequencyArry[10] = {0};


    // Count occurrences
    for (int i = 0; i < n; i++) {
        frequencyArry[(arr[i] / pos) % 10]++;
    }

    // Calculate cumulative frequency
    for (int i = 1; i < 10; i++) {
        frequencyArry[i] += frequencyArry[i - 1];
    }



    int newArray[n];
    for (int i = n - 1; i >= 0; i--) {
        newArray[--frequencyArry[(arr[i] / pos) % 10]] = arr[i];
    }

    // Copy the sorted values back to the original array
    for (int i = 0; i < n; i++) {
        arr[i] = newArray[i];
    }
}

void RadixSort(int arr[], int n) {
    int max = arr[0];

    // Find the maximum value
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }

    
    
    for (int pos = 1; max / pos > 0; pos *= 10) {
        CountSort(arr, n, pos);
    }
}

int main() {

    int arr[] = {789, 123, 456, 0, 999};
    int n = sizeof(arr) / sizeof(arr[0]);

    RadixSort(arr, n);

    

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}

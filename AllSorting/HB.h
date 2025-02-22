#ifndef HB_H
#define HB_H
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// Bubble Sort:
void bubbleSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                std::swap(arr[j], arr[j + 1]);
            }
        }
    }
}

// Merge Sort:
void mergeSort(int num[], int low, int mid, int high)
{
    int a1 = mid - low + 1;
    int b2 = high - mid;
    int a[a1], b[b2];

    for (int i = 0; i < a1; i++)
        a[i] = num[low + i];
    for (int j = 0; j < b2; j++)
        b[j] = num[mid + 1 + j];

    int i = 0, j = 0, k = low;
    while (i < a1 && j < b2)
    {
        if (a[i] <= b[j])
            num[k++] = a[i++];
        else
            num[k++] = b[j++];
    }

    while (i < a1)
        num[k++] = a[i++];

    while (j < b2)
        num[k++] = b[j++];
}

// Selection Sort:
void selectionSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int minIdx = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[minIdx])
                minIdx = j;
        }
        std::swap(arr[i], arr[minIdx]);
    }
}

// Quick Sort:
int partition(int num[], int low, int high)
{
    int index = low - 1;
    int pivot = num[high];
    for (int i = low; i < high; i++)
    {
        if (num[i] <= pivot)
        {
            index++;
            std::swap(num[i], num[index]);
        }
    }
    index++;
    std::swap(num[high], num[index]);
    return index;
}

void QuickSort(int num[], int low, int high)
{
    if (low < high)
    {
        int pivot = partition(num, low, high);
        QuickSort(num, low, pivot - 1);
        QuickSort(num, pivot + 1, high);
    }
}

// Count Sort:
void CountSort(int arr[], int n)
{
    int max = arr[0];
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }

    int frequency[max + 1] = {0};
    for (int i = 0; i < n; i++)
    {
        frequency[arr[i]] += 1;
    }

    for (int i = 1; i <= max; i++)
    {
        frequency[i] = frequency[i] + frequency[i - 1];
    }

    int newArray[n];
    for (int i = n - 1; i >= 0; i--)
    {
        newArray[--frequency[arr[i]]] = arr[i];
    }

    for (int i = 0; i < n; i++)
    {
        arr[i] = newArray[i];
    }
}

// Insertion Sort:
void insertionSort(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int key = arr[i], j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// Radix Sort:
void CountSort(int arr[], int n, int pos)
{
    int frequencyArry[10] = {0};

    for (int i = 0; i < n; i++)
    {
        frequencyArry[(arr[i] / pos) % 10]++;
    }

    for (int i = 1; i < 10; i++)
    {
        frequencyArry[i] += frequencyArry[i - 1];
    }

    int newArray[n];
    for (int i = n - 1; i >= 0; i--)
    {
        newArray[--frequencyArry[(arr[i] / pos) % 10]] = arr[i];
    }

    for (int i = 0; i < n; i++)
    {
        arr[i] = newArray[i];
    }
}

void RadixSort(int arr[], int n)
{
    int max = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }

    for (int pos = 1; max / pos > 0; pos *= 10)
    {
        CountSort(arr, n, pos);
    }
}

// Bucket Sort:
void bucketSort(int arr[], int n)
{
    int max = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }

    int bucketCount = max / 10 + 1;
    vector<int> buckets[bucketCount];

    for (int i = 0; i < n; i++)
    {
        int bucketIndex = arr[i] / 10;
        buckets[bucketIndex].push_back(arr[i]);
    }

    for (int i = 0; i < bucketCount; i++)
    {
        sort(buckets[i].begin(), buckets[i].end());
    }

    int index = 0;
    for (int i = 0; i < bucketCount; i++)
    {
        for (int j = 0; j < buckets[i].size(); j++)
        {
            arr[index++] = buckets[i][j];
        }
    }
}

#endif

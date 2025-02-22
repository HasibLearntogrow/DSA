#include <iostream>
using namespace std;

void merge(int num[], int low, int mid, int high)
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

void mergeSort(int num[], int low, int high)
{
    if (low >= high)
        return;

    int mid = low + (high - low) / 2;
    mergeSort(num, low, mid);
    mergeSort(num, mid + 1, high);
    merge(num, low, mid, high);
}

int main()
{
    int num[] = {0, 1, 1, 0, 1, 2, 1, 2, 0, 0, 0, 1};
    int n = sizeof(num) / sizeof(num[0]);

    mergeSort(num, 0, n - 1);

    cout << "After sorting:" << endl;
    for (int i = 0; i < n; i++)
        cout << num[i] << " ";

    return 0;
}

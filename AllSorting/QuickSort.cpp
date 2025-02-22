#include <iostream>
using namespace std;

int partition(int num[], int low, int high) {
    int index = low - 1;
    int pivot = num[high];
    for (int i = low; i < high; i++) {
        if (num[i] <= pivot) {
            index++;
            swap(num[i], num[index]);
        }
    }
    index++;
    swap(num[high], num[index]);
    return index;
}

void QuickSort(int num[], int low, int high) {
    if (low < high) {
        int pivot = partition(num, low, high);
        QuickSort(num, low, pivot - 1);
        QuickSort(num, pivot + 1, high);
    }
}

int main() {
    int num[] = {10,5,30,3,99};
    int n = sizeof(num) / sizeof(num[0]);

    QuickSort(num, 0, n - 1);

    cout << "After sorting:" << endl;
    for (int i = 0; i < n; i++)
        cout << num[i] << " ";

    return 0;
}

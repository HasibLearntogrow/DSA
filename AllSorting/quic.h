#ifdef quic_H
#define quic_H
#include <iostream>
#include <algorithm>
int partition(int Arr[], int start, int end) {
    int P_index = start - 1;
    int pivot = Arr[end];
    for (int i = start; i < end; i++) {
        if (Arr[i] <= pivot) {
            P_index++;
            std::swap(Arr[i], Arr[P_index]);
        }
    }
    P_index++;
   std:: swap(Arr[end], Arr[P_index]);
    return P_index;
}

void QuickSort(int Arr[], int start, int end) {
    if (start < end) {
        int pivot = partition(Arr, start, end);
        QuickSort(Arr, start, pivot - 1);
        QuickSort(Arr, pivot + 1, end);
    }
}


#endif
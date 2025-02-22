#include<bits/stdc++.h>
using namespace std;
int partition(int Arr[], int start, int end) {
    int P_index = start - 1;
    int pivot = Arr[end];
    for (int i = start; i < end; i++) {
        if (Arr[i] <= pivot) {
            P_index++;
            swap(Arr[i], Arr[P_index]);
        }
    }
    P_index++;
    swap(Arr[end], Arr[P_index]);
    return P_index;
}

void QuickSort(int Arr[], int start, int end) {
    if (start < end) {
        int pivot = partition(Arr, start, end);
        QuickSort(Arr, start, pivot - 1);
        QuickSort(Arr, pivot + 1, end);
    }
}

int main(){

    int num[] = {2,4,1,6,3,8,5,7};
    int n = sizeof(num) / sizeof(num[0]);

    QuickSort(num, 0, n - 1);

    cout << "After sorting:" << endl;
    for (int i = 0; i < n; i++)
        cout << num[i] << " ";

    return 0;





    return 0;
}
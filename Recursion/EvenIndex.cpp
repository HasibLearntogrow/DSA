#include<iostream>
using namespace std;

void printEvenIndicesReverse(int arr[], int n, int idx) {
    if (idx >= n) return; 

    printEvenIndicesReverse(arr, n, idx + 2);  
    cout << arr[idx] << " "; 
}

int main() {
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    printEvenIndicesReverse(arr, n, 0); 
    cout << endl;
    return 0;
}

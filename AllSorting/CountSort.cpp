#include <iostream>
using namespace std;

void CountSort(int arr[], int n)
{
    // Step-1: Find Max value:
    int max = arr[0];
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }

    // Step-2: Create new array with max value size:
    int frequency[max + 1] = {0};
    for (int i = 0; i < n; i++)
    {
        frequency[arr[i]] += 1;
    }

    // Step-3: Update frequency table: updated value = current value + previous value:
    for (int i = 1; i <= max; i++)
    {
        frequency[i] = frequency[i] + frequency[i - 1];
    }

    // Step-4: Sort values:

    // i. Iterate given array from last position
    // ii. Get value and use this as index in updated array
    // iii. Get value from updated array and decrease one
    // iv. Use this value as an index in new array
    // v. Set newArray[value] = Givenarr[i]
    int newArray[n];
    for (int i = n - 1; i >= 0; i--)
    {
        newArray[--frequency[arr[i]]] = arr[i];
    }

    // Step-5: Copy newArray to given array:
    for (int i = 0; i < n; i++)
    {
        arr[i] = newArray[i];
    }
}

int main()
{
    int arr[11] = {1, 3, 2, 3, 4, 1, 6, 4, 3,20,11};
    int n = sizeof(arr) / sizeof(arr[0]);

    CountSort(arr, n);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}

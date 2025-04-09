#include <bits/stdc++.h>
using namespace std;
class heap
{

public:
    int arr[1000];
    int size;
    heap()
    {
        arr[0] = -1;
        size = 0;
    }

    // Insert node:
    void insert(int data)
    {
        size += 1;
        int index = size;
        arr[index] = data;
        while (index > 1)
        {
            int parentindex = index / 2;
            if (arr[parentindex] > arr[index])
            {
                swap(arr[index], arr[parentindex]);
                parentindex = index;
            }
            else
            {
                return;
            }
        }
    }

    // Delete  node:
    void Delete()
    {
        if (size == 0)
        {
            cout << "Heap is Empty!" << endl;
            return;
        }

        swap(arr[1], arr[size]); //--->step :1
        size--;                  //--->step:2

        // Give correct position for heap:
        int i = 1;
        while (i < size)
        {
            int leftindex = 2 * i;
            int rightindex = 2 * i + 1;
            if (leftindex < size && arr[i] > arr[leftindex])
            {
                swap(arr[leftindex], arr[i]);
                leftindex = 1;
            }
            else if (rightindex < size && arr[i] > arr[rightindex])
            {
                swap(arr[rightindex], arr[i]);
                rightindex = 1;
            }
            else
            {
                return;
            }
        }
    }

    void print()
    {
        cout << "position->node(FOllow by Min Heap):" << endl;
        for (int i = 1; i <= size; i++)
        {
            cout << i << "->" << arr[i] << endl;
        }
    }
};
int main()
{
    heap h;
    // int n;
    // cout << "Enter the number of node:";
    // cin >> n;
    // cout << "Enter nodes:";
    // for (int i = 1; i <= n; i++)
    // {
    //     int value;
    //     cin >> value;
    //     h.insert(value);
    // }

    // h.print();
    // cout << "After delete:" << endl;
    // h.Delete();
    h.insert(90);
    h.insert(85);
    h.insert(80);
    h.insert(70);
    h.insert(60);
    h.insert(50);
    h.insert(40);
    h.print();

    return 0;
}
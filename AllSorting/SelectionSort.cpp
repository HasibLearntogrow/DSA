#include <iostream>
using namespace std;

int main()
{
    int num[] = {10, 2, 3, 20, 5, 6};
    int n = sizeof(num) / sizeof(num[0]);

    for (int i = 0; i < n; i++)
    {   int min=INT_MAX;
    int mindex=-1;
        for (int j = i; j < n; j++)
        {
            if (num[j] <min)
            {
                min=num[j];
                mindex=j;
              
                
            }
        }
         swap(num[i],num[mindex]) ;
    }

    for (int i = 0; i < n; i++)
    {
        cout << num[i] << " ";
    }

    return 0;
}

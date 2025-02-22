#include <iostream>
using namespace std;

int main()
{
    int num[] = {10, 2, 3, 20, 5, 6};
    int n = sizeof(num) / sizeof(num[0]);

    for (int i = 0; i < n - 1; i++)
    { 
        bool flag=false;
        for (int j = 0; j < n - i - 1; j++)
        {
            if (num[j] > num[j + 1])
            {
                
               swap(num[j],num[j + 1]) ;
               flag=true;
                
            }
        }
        if (flag=false)
        {
            break;
        }
        
    }

    for (int i = 0; i < n; i++)
    {
        cout << num[i] << " ";
    }

    return 0;
}

#include <iostream>
using namespace std;

int main()
{
    int num[] = {77, 33, 44, 11, 88, 22,66,65};
    int n = sizeof(num) / sizeof(num[0]);

    for (int i = 0; i < n; i++)
    {   
      int j=i+1;
      while (j>=1 && num[j]<num[j-1])
      {
        swap(num[j],num[j-1]);
       j--;
      }
    }
cout<<"After sorting:"<<endl; 
    for (int i = 0; i < n; i++)
    {
        cout << num[i] << " ";
    }

    return 0;
}

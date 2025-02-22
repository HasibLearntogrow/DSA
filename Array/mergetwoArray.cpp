#include <iostream>
using namespace std;
int main()
{
    int num1[6]={1,2,3,4,5,6};
     int num2[6]={7,8,9,10,11,12};
    int n1=sizeof(num1)/sizeof(num1[0]);
    int n2=sizeof(num2)/sizeof(num2[0]);
    int num3[n1+n2];
    int i=0;
    int j=0;
    int k=0;
    while(i<n1)
    {
        num3[k++]=num1[i++];
    }
    while(j<n2)
    {
        num3[k++]=num2[j++];
    }
    for(int m=0;m<n1+n2;m++)
    {
        cout<<num3[m]<<" ";
    }
    
    
   return 0;
}
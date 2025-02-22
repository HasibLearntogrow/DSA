#include <iostream>

using namespace std;

void Binary_search(int num[],int low,int high,int item)

{     int mid;
     mid=(low+high)/2;

     if (low<=high)
     {
         if (num[mid]==item)
    {
         cout<<item<<"-index:"<<mid<<endl; 
        }else if (num[mid]>item)
    {
        Binary_search(num,low,high=mid-1,item);
        }else if (num[mid]<item)
    {
        Binary_search(num,low=mid+1,high,item);
    }
     }
     else if(low>high)
     {
        cout<<"Do not found";
     }
}
int main()
{
    int num[]={1,2,3,4,5};
    int n=sizeof(num)/sizeof(num[0]);
    int low=0;
    int high=n-1;
    int item=5;
    Binary_search(num,low,high,item);

   return 0;
}
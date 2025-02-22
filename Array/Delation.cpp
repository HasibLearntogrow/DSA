#include <iostream>

using namespace std;

int main()
{
    int num[]={1,2,3,4,5};
    int n=sizeof(num)/sizeof(num[0]);
    cout<<"Primary array:"<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<num[i]<<" "<<endl;
    }
    cout<<"Enter any index for delete element:"<<endl;
    int k;
    cin>>k;
   if(k<n)
   {
       for(int j=k;j<n;j++)
  {
      num[j]=num[j+1];
      
  }
  n=n-1;
   }
    cout<<"Final output"<<endl;
     int i = 0;
    while (i < n) {
        cout << num[i] << " ";
        i++;
    }
   return 0;
}
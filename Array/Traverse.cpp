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

   return 0;
}
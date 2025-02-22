#include <iostream>
using namespace std;
void Insert(int num[],int n,int k,int item){
    int j=n;
    while(j>=k){
        num[j+1]=num[j];
        j--;
      
      }
      num[k]=10;
      n++;


}
int main()
{
    int num[6]={1,2,3,4,5};
    int n=5;
    int k=3;
    int j=n;

Insert(num,n,k,10);

     for(int i=0;i<n;i++)
    {
        cout<<num[i]<<" "<<endl;
    }  
   return 0;
}
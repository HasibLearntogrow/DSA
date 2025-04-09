#include<bits/stdc++.h>
using namespace std;
class cbt{

    public:
   int arr[1000];
   int size;
   cbt(){
    arr[0]=-1;
    size=0;
   }


//Insert value in tree:
   void insert(int data){
    size+=1;
    int index=size;
    arr[index]=data;
   }



//Print Complete Binary Tree:
   void print()
   {
    cout<<"position->node:"<<endl;
  for(int i=1;i<=size;i++){
   cout<<i<<"->"<<arr[i]<<endl;
  }
   }
};
int main(){
    cbt c;
    c.insert(50);
    c.insert(3);
    c.insert(2);
    c.insert(15);
    c.insert(16);
    c.insert(17);

  c.print();
    return 0;
}
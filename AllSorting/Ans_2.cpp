#include<bits/stdc++.h>
#include "Sort.h"
using namespace std;
int main(){
 int arr1[]={4,9,5};
 int arr2[]={9,4,9,8,4};
 int size1=sizeof(arr1)/sizeof(arr1[0]);
 int size2=sizeof(arr2)/sizeof(arr2[0]);
bubbleSort(arr1,size1) ;
bubbleSort(arr2,size2);
set<int>s1;
set<int>s2;
for(int i=0;i<size1;i++){
    int m=arr1[i];
    s1.insert(m);
}
for(int c: arr2){

    s2.insert(c);
}
for(int c: s1){
    for(int x: s2){
        if(c==x){
            cout<<c<<" ";
        }
    }
}
    return 0;
}

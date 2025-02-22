#include<bits/stdc++.h>
#include "Sort.h"
using namespace std;
int main(){

int num[]={10,3,2,2,11,24};
int n=sizeof(num)/sizeof(num[0]);
QuickSort(num,0,n-1);
for(int i=0;i<n;i++){
    cout<<num[i]<<" ";
}

}
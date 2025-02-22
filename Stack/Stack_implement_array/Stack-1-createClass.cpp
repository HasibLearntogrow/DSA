#include<iostream>
using namespace std;
class Stack{
int* arr;
int size;
int top;
public:
Stack(int n){
         size=n;;
    arr=new int[size];
    top=-1;
}

};
int main(){
   Stack *st=new Stack(10);

    return 0;
}
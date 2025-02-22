#include <iostream>
using namespace std;
//Operation-1:
class Stack
{
    int *arr;
    int size;
    int top;

public:
    Stack(int n)
    {
        size = n;
        ;
        arr = new int[size];
        top = -1;
    }
    //Operation-2:Empty or Not:
    bool isEmpty(){
        if(top ==-1){
            return true;
        }else{
            return false;
        }
    }
    //Operation-3:Push()
    void StPush(int data){
        if(isEmpty() && top<size){
            top++;
            arr[top]==data;
        }else{
            cout<<"Satck overflow!";
        }
    }
    //Operation-4: pop()
    void StPop(){
        if(top>=0){
            top--;
        }else{
            cout<<"Satck Underflow!";
        }

    }

};
int main()
{
    Stack *st = new Stack(10);
 
    st->StPush(10);
    st->StPop();
    
    st->StPop();
  
    return 0;
}
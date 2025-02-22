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

};
int main()
{
    Stack *st = new Stack(10);
    cout<<st ->isEmpty();

    return 0;
}
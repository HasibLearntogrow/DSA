#include <iostream>
using namespace std;
//1-Create CirQueue:
class CirQueue {
    int* arr;
    int size;
    int front;
    int rear;
    
public:
    CirQueue() {
        size = 1000;
        arr = new int[size];
        front =-1;
        rear = -1;
    }
//Insert value: operation-2:
    void Enqueue(int data){
    if(front==0 && rear==size-1 || rear==(front-1)%(size-1)){
    cout<<"Circular Queue is Full!"<<endl;
    }else if(front==-1){
        front=rear=0;
        arr[front]=data;

    }else if(rear==size-1){
        rear=0;
        arr[rear]=data;
    }else{
        rear++;
        arr[rear]=data;
    }
    }
    //Check Empty or Not: operation-3:
    bool IsEmpty(){

        if(front==-1 && rear==-1){
            return true;
        }else{
            return false;
        }
    }
};

int main() {
    CirQueue cq;
   // cq.Enqueue(10);
    cout<<cq.IsEmpty();
    return 0;
}

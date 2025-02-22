#include <iostream>
using namespace std;
//1-Create Deque:
class Deque {
    int* arr;
    int size;
    int front;
    int rear;
    
public:
    Deque(int n) {
        size =n;
        arr = new int[size];
        front =rear =-1;
        
    }

    //operation-2:Check Empty or Not: 
    bool IsEmpty(){

        if(front==-1 && rear==-1){
            return true;
        }else{
            return false;
        }
    }
    //Operation-3: PushFront()
    void pushFront(int data){
        if (front == 0 && rear == size-1) {
            cout << "Deque is full\n";
            return;
        }
    if(front==-1){
        front=rear=0;
    }else if(front==0 && rear!=size-1){
        front=size-1;
    }else{
        front--;
    }
    arr[front]=data;
    }


  
};

int main() {
    Deque *dq=new Deque(20);
  cout<<dq->IsEmpty()<<endl;
  dq->pushFront(12);
  dq->pushFront(10);
  dq->print();


    return 0;
}

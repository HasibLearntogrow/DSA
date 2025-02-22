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

    //Operation-4: Print Circulae Queue:
      void PrintQueue() {
        if (IsEmpty()) {
            cout << "Circular Queue is Empty!" << endl;
            return;
        }
        
        cout << "Circular Queue elements are: ";
        
        if (rear >= front) {
            for (int i = front; i <= rear; i++) {
                cout << arr[i] << " ";
            }
        } else {
            for (int i = front; i < size; i++) {
                cout << arr[i] << " ";
            }
            for (int i = 0; i <= rear; i++) {
                cout << arr[i] << " ";
            }
        }
        cout << endl;
    }
    //Operation-5:DeQueue:(POP):
    void Dequeue(){
     if(IsEmpty()){
        cout<<"This is Empty !so dont possible to perform Dequeue"<<endl;
     }else if(front==rear){
       front=rear=-1;
     }else if(front==size-1){
        front=0;
        
     }else{
        front++;
     }


    }
    
};

int main() {
    CirQueue cq;
    
    cq.Enqueue(10);
    cq.Enqueue(11);
    cq.Enqueue(23);
    cq.PrintQueue();


    cq.Dequeue();
    cq.PrintQueue();

    cq.Dequeue();
    cq.PrintQueue();

    cq.Dequeue();
    cq.PrintQueue();

    return 0;
}

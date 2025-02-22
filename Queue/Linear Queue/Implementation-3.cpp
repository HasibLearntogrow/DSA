#include <iostream>
using namespace std;
// 1-Create Queue:
class Queue
{
    int *arr;
    int size;
    int front;
    int rear;

public:
    Queue()
    {
        size = 1000;
        arr = new int[size];
        front = 0;
        rear = 0;
    }
  //2-Check Empty or not:
    bool isEmpty()
    {
        // 1----Empty
        if (front == rear)
        {
            return 1;
        }
        else
        {
            // 0----NotEmpty
            return 0;
        }
    }
    //Insert value:
    void Enqueue(int data){
        if(rear<size){
         arr[rear]=data;
         rear++;
        }else{
         cout<<"Queue if full";
        }
       }

};

int main()
{

    Queue q;
    cout << q.isEmpty()<<endl;
    q.Enqueue(10);
    q.Enqueue(11);
    cout << q.isEmpty()<<endl;
  
    return 0;
}

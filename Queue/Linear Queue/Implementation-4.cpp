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
    //3-:Insert value:
  void Enqueue(int data){
   if(rear<size){
    arr[rear]=data;
    rear++;
   }else{
    cout<<"Queue if full";
   }
  }
  // 4-Print:
  
  void print() {
    int temp = front;
    while (temp != rear) {
        cout << arr[temp] << " ";
        temp++;
    }
    cout << endl;
}



};

int main()
{

    Queue q;
    
    q.Enqueue(10);
    q.Enqueue(11);
    q.print();
  
    return 0;
}

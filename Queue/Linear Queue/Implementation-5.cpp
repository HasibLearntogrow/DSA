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
            return true;
        }
        else
        {
            // 0----NotEmpty
            return false;
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
    if(front==rear){

        cout<<"Empty!Queue"<<endl;
    }else{
        int temp = front;
        while (temp != rear) {
            cout << arr[temp] << " ";
            temp++;
        }
        cout << endl;
    }
    
}
//5-Dequeue:
void Dequeue() {
    if (front !=rear) {
        arr[front] = -1;
        front++;
        if (front == rear) {
            front = rear = 0;
        }
        
    } 
}




};

int main()
{

    Queue q;
    
    q.Enqueue(10);
    q.Enqueue(11);
    q.Enqueue(13);
    q.print();

    q.Dequeue();
    q.print();

    q.Dequeue();
    q.print();

    q.Dequeue();
    q.print();

    return 0;
}

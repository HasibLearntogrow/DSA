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
};

int main()
{

    Queue q;
    cout << q.isEmpty();
    return 0;
}

#include <iostream>
using namespace std;
// 1-Create Deque:
class Deque
{
    int *arr;
    int size;
    int front;
    int rear;

public:
    Deque(int n)
    {
        size = n;
        arr = new int[size];
        front = rear = -1;
    }

    // operation-2:Check Empty or Not:
    bool IsEmpty()
    {

        if (front == -1 && rear == -1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    // Operation-3: PushFront()
    void pushFront(int data)
    {
        if (front == 0 && rear == size - 1)
        {
            cout << "Deque is full\n";
            return;
        }
        if (front == -1)
        {
            front = rear = 0;
        }
        else if (front == 0 && rear != size - 1)
        {
            front = size - 1;
        }
        else
        {
            front--;
        }
        arr[front] = data;
    }

    // operation-4:Print value of Deque:
    int print()
    {
        if (IsEmpty())
        {
            cout << "This Deque is empty" << endl;
            return -1;
        }
        cout << "Deque elements are: ";
        if (front <= rear)
        {
            for (int i = front; i <= rear; i++)
            {
                cout << arr[i] << " ";
            }
        }
        else
        {
            for (int i = front; i < size; i++)
            {
                cout << arr[i] << " ";
            }
            for (int i = 0; i <= rear; i++)
            {
                cout << arr[i] << " ";
            }
        }
        cout << endl;
        return 0;
    }
    // Operation-5:PopFront()
    void popFront()
    {
        if (IsEmpty())
        {
            cout << "This is Empty !so dont possible to perform Dequeue" << endl;
        }
        else if (front == rear)
        {
            front = rear = -1;
        }
        else if (front == size - 1)
        {
            front = 0;
        }
        else
        {
            front++;
        }
    }
    // Operation-6: Push_Back()
    void PushBack(int data)
    {
        if ((rear + 1) % size == front)
        {
            cout << "Deque is full\n";
            return;
        }

        if (front == -1)
        {
            front = rear = 0;
        }
        else if (rear == size - 1 && front != 0)
        {
            rear = 0;
        }
        else
        {
            rear++;
        }

        arr[rear] = data;
    }
    // Operation -7: popBack():
    void popBack()
    {
        if (IsEmpty())
        {
            cout << "This is Empty !so dont possible to perform Dequeue" << endl;
        }
        else if (front == rear)
        {
            front = rear = -1;
        }
        else if (rear == 0)
        {
            rear = size - 1;
        }
        else
        {
            rear--;
        }
    }
};

int main()
{
    Deque *dq = new Deque(20);
    cout << dq->IsEmpty() << endl;

    dq->pushFront(12);
    dq->pushFront(10);
    dq->print();

    dq->popFront();
    dq->print();

    dq->PushBack(14);
    dq->PushBack(17);
    dq->PushBack(20);
    dq->print();

    dq->popBack();
    dq->print();
    return 0;
}

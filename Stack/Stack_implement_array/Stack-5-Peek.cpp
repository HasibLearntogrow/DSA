#include <iostream>
using namespace std;
// Operation-1:
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
    // Operation-2:Empty or Not:
    bool isEmpty()
    {
        if (top == -1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    // Operation-3:Push()
    void StPush(int data)
    {
        if (size - top > 1)
        {
            top++;
            arr[top] = data;
        }
        else
        {
            cout << "Satck overflow!";
        }
    }
    // Operation-4: pop()
    void StPop()
    {
        if (top >= 0)
        {
            top--;
        }
        else
        {
            cout << "Satck Underflow!";
        }
    }
    // Operation-5: Print top value:
    int peek()
    {
        if (isEmpty())
        {
            return -1;
        }
        else
        {
            return arr[top];
        }
    }
};
int main()
{
    Stack *st = new Stack(10);

    st->StPush(10);
    st->StPush(12);
    st->StPush(15);
    st->StPush(16);
    cout << st->peek() << endl;
    st->StPop();

    cout << st->peek() << endl;
    st->StPop();

    cout << st->peek() << endl;
    st->StPop();
    return 0;
}
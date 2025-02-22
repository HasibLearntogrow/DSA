#include <iostream>
#include <queue>
using namespace std;

int main()
{
    // 1. Declare Queue:
    queue<int> q;

    // 2. Insert value:
    q.push(1);
    q.push(2);
    q.push(3);

    // 3. Check empty or not:
    //  0---->Not Empty:  1---->Empty
    cout << "Boolean value:" << q.empty() << endl;

    // 4. Check size:
    cout << "Size:" << q.size() << endl;

    // 5. Print Front value:
    cout << "First value:" << q.front() << endl;

    // 6. Print Rear value:
    cout << "Last value:" << q.back() << endl;

    // 7. Iterate value from queue:
    cout << "Original queue:" << endl;
    while (!q.empty())
    {
        cout << q.front() << endl;
        q.pop();
    }

    // Re-insert values to demonstrate deletion:
    q.push(1);
    q.push(2);
    q.push(3);

    // 8. After deleting first value:
    q.pop();
    cout << "After deleting front value:" << endl;
    while (!q.empty())
    {
        cout << q.front() << endl;
        q.pop();
    }

    // 9. Swap two queues:
    queue<int> q2;
    q2.push(4);
    q2.push(5);
    q2.push(6);

    cout << "Queue 1 before swap:" << endl;
    q.push(1);
    q.push(2);
    q.push(3);
    while (!q.empty())
    {
        cout << q.front() << endl;
        q.pop();
    }

    cout << "Queue 2 before swap:" << endl;
    queue<int> temp = q2;
    while (!temp.empty())
    {
        cout << temp.front() << endl;
        temp.pop();
    }

    swap(q2, q);

    cout << "Queue 1 after swap:" << endl;
    while (!q.empty())
    {
        cout << q.front() << endl;
        q.pop();
    }

    cout << "Queue 2 after swap:" << endl;
    while (!q2.empty())
    {
        cout << q2.front() << endl;
        q2.pop();
    }

    return 0;
}

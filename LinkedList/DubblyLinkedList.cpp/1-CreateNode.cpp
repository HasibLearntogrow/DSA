#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *pre;
    Node *Next;
    Node(int d)
    {
        this->data = d;
        this->pre = NULL;
        this->Next = NULL;
    }
};

int main()
{
    Node *node1 = new Node(10);
    cout << node1->data << endl;
    cout << node1->pre << endl;
    cout << node1->Next;
    return 0;
}
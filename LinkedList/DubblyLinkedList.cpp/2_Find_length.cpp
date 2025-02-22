#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *pre;
    Node *next;
    Node(int d)
    {
        this->data = d;
        this->pre = NULL;
        this->next = NULL;
    }
};

int getLength(Node *&head)
{
    int len = 0;
    Node *temp = head;
    while (temp != NULL)
    {
        len++;
        temp = temp->next;
    }
    return len;
}

int main()
{
    Node *node1 = new Node(10);
    Node *head = node1;
    int len = getLength(head);
    cout << "Length:" << len;
    return 0;
}
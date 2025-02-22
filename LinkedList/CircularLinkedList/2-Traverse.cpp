#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    // Pass value in Node:
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};
void print(Node* tail) {
    
    Node* temp = tail;
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != tail);
    
    cout << endl;
}

int main()
{
    Node *node1 = new Node(2);
    Node* tail=node1;
    print(tail);

    return 0;
}
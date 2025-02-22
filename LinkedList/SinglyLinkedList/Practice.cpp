#include<bits/stdc++.h>
#include "linkedList.h"
using namespace std;

int main(){
    Node* node1 = new Node(10);
    Node* head = node1;
    Node* tail = node1;

    InsertAtTail(tail, 12);
    InsertAtTail(tail, 13);
    InsertAtTail(tail, 13);
    InsertAtTail(tail, 13);
    InsertAtTail(tail, 15);
    InsertAtTail(tail, 15);
    InsertAtTail(tail, 16);
    InsertAtTail(tail, 9);

    Print(head);
   deleteNode(1,head);
    Unique(head);
    Print(head);
  Sort(head);
  Print(head);


    return 0;
}
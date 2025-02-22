#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    // Create node: Node:
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};
//Insert in head:

void InsertAtHead(Node* &head,int d){
    Node* temp= new Node(d);
    temp ->next=head;
    head=temp;
   
   }

//This is use use for create LinkedList by adding new Node in the last position:
void InsertAtTail(Node *&tail, int d)
{
    Node *temp = new Node(d);
    tail->next = temp;
    tail = tail->next;
}

//Add new Add in specific position:
void InsertAtPosition(Node* &tail,Node *&head, int position, int d)
{
   // Add first position:
    if(position==1){
        InsertAtHead(head,d);
        return;
    }
    

    Node *temp = head;
    int i = 1;
    while (i < position - 1)
    {
        temp = temp->next;
        i++;
    }
 //Add last position:
    if(temp ->next==NULL){
      InsertAtTail(tail,d);
      return ;
    }

    //Add Middel of LinkedList:
    Node *newNode = new Node(d);
    newNode->next = temp->next;
    temp->next = newNode;
}
void Print(Node *&head)
{
    Node *tem = head;
    while (tem != NULL)
    {
        cout << tem->data << " ";
        tem = tem->next;
    }
    cout << endl;
}

int main()
{
    Node *node1 = new Node(10);
    Node *head = node1;
    Node *tail = node1;
    InsertAtTail(tail, 12);
    InsertAtTail(tail, 13);
    InsertAtTail(tail, 15);
    InsertAtTail(tail, 16);
    Print(head);
    cout << "New add node at 2nd position:11:" << endl;
  //For Midle
    InsertAtPosition(tail,head, 2, 11);
    Print(head);
    //For add first:
    InsertAtPosition(tail,head, 1, 9);
    Print(head);
    //For Last:
    InsertAtPosition(tail,head, 8, 17);
    Print(head);
    return 0;
}
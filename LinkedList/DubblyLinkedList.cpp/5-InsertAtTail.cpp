#include<bits/stdc++.h>
using namespace std;
class Node{
public:
int data;
Node* pre;
Node* next;
Node(int d){
    this ->data=d;
    this ->pre=NULL;
    this ->next=NULL;
}
};
void InsertAtTail(Node* &tail,int d){
 Node* temp=new Node(d);
 
 tail->next= temp;
 temp ->pre=tail;
  tail=temp;
}
void print(Node *&head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data<<" ";
        temp = temp->next;
       
    }
    cout<<endl;
}



int main(){
Node* node1=new Node(10);
Node* tail=node1;
Node* head=node1;
print(head);
InsertAtTail(tail,9);
print(head);
InsertAtTail(tail,11);
print(head);
    return 0;
}
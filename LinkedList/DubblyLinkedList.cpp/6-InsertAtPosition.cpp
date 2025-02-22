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
//Insert at head:
void InsertAtHead(Node* &head,int d){
    Node* temp=new Node(d);
    
    temp->next= head;
    head ->pre=temp;
    head=temp;
   }
//Insert At tail:
void InsertAtTail(Node* &tail,int d){
 Node* temp=new Node(d);
 
 tail->next= temp;
 temp ->pre=tail;
  tail=temp;
}
void InsertAtPosition(Node *&head,Node* &tail, int position, int d)
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

    //Add Middel:
    Node *newNode = new Node(d);
    newNode ->next=temp ->next;
    temp ->next ->pre=newNode;
    temp ->next=newNode;
    newNode ->pre=temp;

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

InsertAtHead(head,8);
print(head);
InsertAtPosition(head,tail,3,30);
print(head);
    return 0;
}
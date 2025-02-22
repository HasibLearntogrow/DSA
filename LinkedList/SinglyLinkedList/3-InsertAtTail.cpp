#include<bits/stdc++.h>
using namespace std;
class Node{
  public:
  int data;
  Node*next;
  //Pass value in Node:
 Node(int data){
    this -> data=data;
    this -> next=NULL;
 }
};

void InsertAtTail(Node* &tail,int d){
 Node* temp= new Node(d);
 tail ->next=temp;
   tail=tail->next;

}

void Print(Node* &head){
   Node* tem=head;
   while (tem!=NULL)
   {
    cout<<tem->data<<" ";
    tem=tem->next;
   }
   cout<<endl;

}

int main(){
Node* node1=new Node(10);
Node* head=node1;
 Print(head);
Node* tail=node1;
InsertAtTail(tail,12);
Print(head);
InsertAtTail(tail,113);
Print(head);
    return 0;
}
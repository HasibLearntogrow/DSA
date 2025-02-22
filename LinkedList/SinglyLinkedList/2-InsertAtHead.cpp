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

void InsertAtHead(Node* &head,int d){
 Node* temp= new Node(d);
 temp ->next=head;
 head=temp;

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
InsertAtHead(head,12);
Print(head);
    return 0;
}
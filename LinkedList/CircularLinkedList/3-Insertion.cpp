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
void InsertAtTail(Node* &tail,int element,int d){
    //Let...element are include in LinkedList

    //If linkedList is empty:
if(tail==NULL){
Node *temp=new Node(d);
  tail=temp;
  temp ->next=temp;
}else{
Node* current=tail;
while(current ->data !=element){
   current=current ->next;

}
Node* temp= new Node(d);
temp ->next=current ->next;
current ->next=temp;

}
}
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
   Node* tail=NULL;
   
   InsertAtTail(tail,2,3);
   print(tail);

   InsertAtTail(tail,3,4);
   print(tail);

   InsertAtTail(tail,4,5);
   print(tail);

   InsertAtTail(tail,3,2);
   print(tail);
    return 0;
}
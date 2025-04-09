#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node *left;
    Node *right;
    Node(int d){
        this ->data=d;
        this ->left=right=nullptr;
    }
};
Node *CreteTree(Node *root){

int value;
cout<<"value:"<<endl;
cin>>value;
root=new Node(value);


if (value==-1)
{
    return NULL;
}


cout<<"Enter left side value of ->"<<value<<endl;
root ->left=CreteTree(root->left);

cout<<"Enter right side value of ->"<<value<<endl;
root ->right=CreteTree(root->right);

    return root;
}


int main(){
 Node *root=nullptr;
 root=CreteTree(root);
    return 0;
}
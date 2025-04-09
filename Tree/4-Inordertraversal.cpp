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

//InOrder traverse:
void Inorder(Node * root){
if (root==NULL)
{
    return ;
}
Inorder(root->left);
cout<<root->data<<" ";
Inorder(root->right);
}



int main(){
 Node *root=nullptr;
 root=CreteTree(root);
 cout<<"Inorder traverse:"<<endl;
 Inorder(root);
    return 0;
}
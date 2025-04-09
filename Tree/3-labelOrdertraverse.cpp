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

//Create tree:

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




void LabelOrder(Node *root) {
    if (root == NULL) return;

    queue<Node *> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty()) {
        Node *temp = q.front();
        q.pop();

        if (temp == NULL) {
            cout << endl;
            if (!q.empty()) {
                q.push(NULL);
            }
        } else {
            cout << temp->data << " ";
            
            if (temp->left) {
                q.push(temp->left);
            }
            
            if (temp->right) {
                q.push(temp->right);
            }
        }
    }
}


int main(){
 Node *root=nullptr;
 root=CreteTree(root);
 LabelOrder(root);
    return 0;
}





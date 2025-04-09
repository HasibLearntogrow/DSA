#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int d)
    {
        this->data = d;
        this->left = right = nullptr;
    }
};

Node *AddChild(Node *&node, int value)
{
    if (node == nullptr)
    {
        return new Node(value);
    }
    if (node->data > value)
    {
        node->left = AddChild(node->left, value);
    }
    else
    {
        node->right = AddChild(node->right, value);
    }
    return node;
}

// label order traversal:
void LabelOrder(Node *root)
{
    if (root == NULL)
        return;

    queue<Node *> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();

        if (temp == NULL)
        {
            cout << endl;
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            cout << temp->data << " ";

            if (temp->left)
            {
                q.push(temp->left);
            }

            if (temp->right)
            {
                q.push(temp->right);
            }
        }
    }
}
// Delete in BST:
Node *Delete(Node *root, int target)
{
    if (root == nullptr)
    {
        cout << "BST is already NULL" << endl;
        return nullptr;
    }
    if (root->data > target)
    {
        root->left = Delete(root->left, target);
    }
    else if (root->data < target)
    {
        root->right = Delete(root->right, target);
    }
    else
    {
        // leaf node:
        if (root->left == nullptr && root->right == nullptr)
        {
            delete root;
            return nullptr;
        }
        else if (root->right == nullptr) // One child-> left child
        {
            Node *temp = root->left;
            delete root;
            return temp;
        }
        else if (root->left == nullptr) // one child->right child
        {
            Node *temp = root->right;
            delete root;
            return temp;
        }
        else
        {
            // both child:
            Node *parent = root;
            Node *child = root->left;
            while (child->right)
            {
                parent = child;
                child = child->right;
            }
            if (parent != root)
            {
                parent->right = child->left;
                child->left = root->left;
            }
            child->right = root->right;
            delete root;
            return child;
        }
    }
    return root;
}

int main()
{
    Node *root = nullptr;
    cout << "Enter the value of child(-1 for stop insert):" << endl;
    int value;
    while (cin >> value && value != -1)
    {
        root = AddChild(root, value);
    }

    cout << "BST tree:" << endl;
    LabelOrder(root);

    int target;
    cout << "Enter any value to delete in BST:";
    cin >> target;
    root = Delete(root, target);
    cout << "After delete-" << target << endl;
    LabelOrder(root);

    return 0;
}
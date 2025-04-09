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

// Search in BST:
bool search(Node *root, int target)
{

    if (root == nullptr)
    {
        return false;
    }

    if (root->data == target)
    {
        return true;
    }

    if (root->data > target)
    {
        return search(root->left, target);
    }
    else
    {
        return search(root->right, target);
    }
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
    cout << "Enter any value to search in BST:";
    cin >> target;
    bool res = search(root, target);
    cout << "1 for Exist and 0 for not exist in BST:" << res;
    return 0;
}
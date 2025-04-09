#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    int height;
    Node(int value)
    {
        data = value;
        left = right = nullptr;
        height = 1;
    }
};

int getHeight(Node *root)
{
    if (root == nullptr)
    {
        return 0;
    }
    return root->height;
}

int getbalance(Node *root)
{
    if (root == nullptr)
    {
        return 0;
    }
    return getHeight(root->left) - getHeight(root->right);
}

Node *leftrotation(Node *x)
{
    Node *y = x->right;
    Node *T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = 1 + max(getHeight(x->left), getHeight(x->right));
    y->height = 1 + max(getHeight(y->left), getHeight(y->right));

    return y;
}

Node *rightrotation(Node *x)
{
    Node *y = x->left;
    Node *T2 = y->right;

    y->right = x;
    x->left = T2;

    x->height = 1 + max(getHeight(x->left), getHeight(x->right));
    y->height = 1 + max(getHeight(y->left), getHeight(y->right));

    return y;
}

Node *insert(Node *root, int value)
{
    if (root == nullptr)
    {
        return new Node(value);
    }

    if (value < root->data)
    {
        root->left = insert(root->left, value);
    }
    else if (value > root->data)
    {
        root->right = insert(root->right, value);
    }
    else
    {
        return root;
    }

    root->height = 1 + max(getHeight(root->left), getHeight(root->right));
    int balance = getbalance(root);

    if (balance > 1 && value < root->left->data)
    {
        return rightrotation(root);
    }

    if (balance < -1 && value > root->right->data)
    {
        return leftrotation(root);
    }

    if (balance > 1 && value > root->left->data)
    {
        root->left = leftrotation(root->left);
        return rightrotation(root);
    }

    if (balance < -1 && value < root->right->data)
    {
        root->right = rightrotation(root->right);
        return leftrotation(root);
    }

    return root;
}

Node *deletenode(Node *root, int key)
{
    if (root == nullptr)
    {
        return nullptr;
    }
    if (root->data > key)
    {
        root->left = deletenode(root->left, key);
    }
    else if (root->data < key)
    {
        root->right = deletenode(root->right, key);
    }
    else
    {
        // Node to be deleted found
        if (root->left == nullptr && root->right == nullptr) // Leaf node
        {
            delete root;
            return nullptr;
        }
        else if (root->right == nullptr) // Only left child
        {
            Node *temp = root->left;
            delete root;
            return temp;
        }
        else if (root->left == nullptr) // Only right child
        {
            Node *temp = root->right;
            delete root;
            return temp;
        }
        else
        {
            // Node with two children:
            Node *min = root->right;
            while (min->left)
            {
                min = min->left;
            }
            root->data = min->data;
            root->right = deletenode(root->right, min->data);
        }
    }

    // Update height
    root->height = 1 + max(getHeight(root->left), getHeight(root->right));

    // Get balance factor
    int balance = getbalance(root);

    if (balance > 1) // Left
    {
        if (getbalance(root->left) >= 0) // LL Case
        {
            return rightrotation(root);
        }
        else // LR Case
        {
            root->left = leftrotation(root->left);
            return rightrotation(root);
        }
    }
    else if (balance < -1) // Right
    {
        if (getbalance(root->right) <= 0) // RR Case
        {
            return leftrotation(root);
        }
        else // RL Case
        {
            root->right = rightrotation(root->right);
            return leftrotation(root);
        }
    }
    return root;
}

void LabelOrder(Node *root)
{
    if (root == nullptr)
        return;

    queue<Node *> q;
    q.push(root);
    q.push(nullptr);

    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();

        if (temp == nullptr)
        {
            cout << endl;
            if (!q.empty())
            {
                q.push(nullptr);
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

int main()
{
    Node *root = nullptr;
    root = insert(root, 60);
    root = insert(root, 40);
    root = insert(root, 80);
    root = insert(root, 30);
    root = insert(root, 20);
    LabelOrder(root);
    root = deletenode(root, 60);
    LabelOrder(root);
    return 0;
}

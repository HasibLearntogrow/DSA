#include <bits/stdc++.h>
using namespace std;
//Create class:
class Node {
public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }

    ~Node() {
        this->next = nullptr;  // Prevent recursive deletion
    }
};

// Insert at head:
void InsertAtHead(Node*& head, int d) {
    Node* temp = new Node(d);
    temp->next = head;
    head = temp;
}

// Insert at tail:
void InsertAtTail(Node*& tail, int d) {
    Node* temp = new Node(d);
    tail->next = temp;
    tail = temp;
}

// Insert at a specific position:
void InsertAtPosition(Node*& tail, Node*& head, int position, int d) {
    if (position == 1) {
        InsertAtHead(head, d);
        return;
    }

    Node* temp = head;
    int i = 1;
    while (i < position - 1 && temp != nullptr) {
        temp = temp->next;
        i++;
    }

    if (temp == nullptr) {
        cout << "Position out of range!" << endl;
        return;
    }

    if (temp->next == nullptr) {
        InsertAtTail(tail, d);
        return;
    }

    Node* newNode = new Node(d);
    newNode->next = temp->next;
    temp->next = newNode;
}

// Delete a node at a given position:
void deleteNode(int position, Node*& head) {
    if (head == nullptr) {
        cout << "List is empty!" << endl;
        return;
    }

    if (position == 1) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }

    Node* current = head;
    Node* previous = nullptr;
    int i = 1;

    while (i < position && current != nullptr) {
        previous = current;
        current = current->next;
        i++;
    }

    if (current == nullptr) {
        cout << "Position out of range!" << endl;
        return;
    }

    previous->next = current->next;
    delete current;
}

// Remove duplicates from sorted linked list:
void Unique(Node*& head) {
    if (head == nullptr) {
        return;
    }

    Node* current = head;

    while (current != nullptr && current->next != nullptr) {
        if (current->data == current->next->data) {
            Node* temp = current->next;
            current->next = current->next->next;
            delete temp;
        } else {
            current = current->next;
        }
    }
}
//Remove Unsorted linkedlist:
void UnUnique(Node*& head) {
    if (head == nullptr) return;

    Node* current = head;

    while (current != nullptr) {
        Node* prev = current;
        Node* temp = current->next;

        while (temp != nullptr) {
            if (temp->data == current->data) {  
                prev->next = temp->next;
                delete temp;
                temp = prev->next;
            } else {
                prev = temp;
                temp = temp->next;
            }
        }
        current = current->next;
    }
}

// Print linked list:
void Print(Node*& head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
//Sort:
void Sort(Node *&head) {
    if (head == nullptr) {
        return;
    }

    bool swapped;
    Node* ptr1;
    Node* lptr = nullptr; // Last sorted element

    do {
        swapped = false;
        ptr1 = head;

        while (ptr1->next != lptr) {
            if (ptr1->data > ptr1->next->data) {
                swap(ptr1->data, ptr1->next->data);
                swapped = true;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    } while (swapped);
}

//Delete node by value:
void Delete(int item, Node*& head) {
    if (head == nullptr) return;

    if (head->data == item) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }

    Node* Current = head;
    Node* Previous = nullptr;

    while (Current != nullptr && Current->data != item) {
        Previous = Current;
        Current = Current->next;
    }

    if (Current == nullptr) return;

    Previous->next = Current->next;
    delete Current;
}

int size(Node* &head){
    if(head==nullptr){
        return -1;
    }
    int count=0;
    Node *curr=head;
    while (curr !=nullptr)
    {
        count++;
        curr=curr ->next;
    }
    return count;
}
void Middle(int pos, Node*& head) {
    if (head == nullptr) return;

    int end = pos / 2;
    int star = 1;
    Node* current = head;

    while (star < end && current != nullptr) {  
        current = current->next;
        star++;
    }

    if (current == nullptr) return;

    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

// Main function
int main() {
    Node* node1 = new Node(10);
    Node* head = node1;
    Node* tail = node1;

    InsertAtTail(tail, 12);
    InsertAtTail(tail, 13);
    InsertAtTail(tail, 13);
    InsertAtTail(tail, 13);
    InsertAtTail(tail, 15);
    InsertAtTail(tail, 15);
    InsertAtTail(tail, 16);
    InsertAtTail(tail, 9);
    Print(head);
    int m=size(head);
cout<<"size:"<<m<<endl;
Middle(m,head);
    return 0;
}

#ifndef linkedList_H
#define linkedList_H
#include <iostream>
#include <algorithm>

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
        std::cout << "Position out of range!" << std::endl;
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
        std::cout << "List is empty!" << std::endl;
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
        std::cout << "Position out of range!" << std::endl;
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

// Remove duplicates from unsorted linked list:
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
        std::cout << temp->data << " ";
        temp = temp->next;
    }
    std::cout << std::endl;
}

// Sort linked list:
void Sort(Node*& head) {
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
                std::swap(ptr1->data, ptr1->next->data);
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
//Find Size:
int size(Node*head){
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


#endif

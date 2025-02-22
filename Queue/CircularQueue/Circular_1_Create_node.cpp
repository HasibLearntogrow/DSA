#include <iostream>
using namespace std;
//1-Create Queue:
class Queue {
    int* arr;
    int size;
    int front;
    int rear;
    
public:
    Queue() {
        size = 1000;
        arr = new int[size];
        front = 0;
        rear = 0;
    }
};

int main() {
    return 0;
}

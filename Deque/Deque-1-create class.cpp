#include <iostream>
using namespace std;
//1-Create Deque:
class Deque {
    int* arr;
    int size;
    int front;
    int rear;
    
public:
    Deque(int n) {
        size =n;
        arr = new int[size];
        front =rear =-1;
        
    }
};

int main() {
    return 0;
}

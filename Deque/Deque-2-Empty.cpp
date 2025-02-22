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

    //operation-2:Check Empty or Not: 
    bool IsEmpty(){

        if(front==-1 && rear==-1){
            return true;
        }else{
            return false;
        }
    }
};

int main() {
    Deque *dq=new Deque(20);
  cout<<dq->IsEmpty();

    return 0;
}

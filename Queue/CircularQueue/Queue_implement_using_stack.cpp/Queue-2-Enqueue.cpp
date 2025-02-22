#include<bits/stdc++.h>
using namespace std;
//Create Class:
class Queue{
stack<int>s1,s2;
public:
void Enqueue(int data){
    s1.push(data);

}
//helping method copy s1 to s2----here s2 work as a queque:
void Assist(){
 if (s2.empty()) {
        while (!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }
    }
}

};
int main(){
Queue q;
q.Enqueue(10);
    return 0;
}
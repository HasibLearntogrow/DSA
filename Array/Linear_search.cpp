#include <iostream>

using namespace std;

int main()
{
    int num[]={1,2,3,4,5};
    cout<<"Enter any value:";
    int item;
    cin>>item;
    int n=sizeof(num)/sizeof(num[0]);
    
   bool found = false;

    for (int i = 0; i < n; i++) {
        if (num[i] == item) {
            cout << item << "-Index:" << i << endl;
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Do not found" << endl;
    
}
   return 0;
}
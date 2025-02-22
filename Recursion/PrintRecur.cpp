#include <iostream>
using namespace std;
int Recur(int n)
{
    if (n == 0)
    {
        return 0;
    }
    else
    {
        cout << "I love Recursion" << endl;
        return Recur(n - 1);
    }
}
using namespace std;

int main()
{
    int n;
    cin >> n;
    Recur(n);
    return 0;
}
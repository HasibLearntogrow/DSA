#include <bits/stdc++.h>
using namespace std;
int Weired(int n)
{
    if (n == 1)
    {
        return -1; // This is base case;
    }
    else if (n % 2 == 0)
    { // For even
        cout << n / 2 << " ";
        return Weired(n / 2);
    }
    else
    {
        cout << n * 3 + 1 << " "; /// for odd
        return Weired(n * 3 + 1);
    }
}
int main()
{
    cout << "Enter any number:";
    int n;
    cin >> n;
    cout << "Result :" << n << " ";
    Weired(n);

    return 0;
}
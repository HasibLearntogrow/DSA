#include <bits/stdc++.h>
int jos(int n)
{
    if (n == 1)
    { // This is base Case: if number of people is 1...he is all time safe
        return 1;
    }
    if (n % 2 == 0)
    {
        return (2 * jos(n / 2) - 1); // For even people
    }
    else
    {
        return (2 * jos(n / 2) + 1); // For Odd people
    }
}
using namespace std;
int main()
{
    int n;
    cout << "Enter number of people:";
    cin >> n;
    int living = jos(n);
    cout << "Position of living people:" << " " << living << endl;
    return 0;
}

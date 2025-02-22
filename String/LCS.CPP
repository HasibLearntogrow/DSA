#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string LCS(string x, string y)
{
    int m = x.size();
    int n = y.size();
    int dp[m+1][n+1]; //Creade data table
    
    for (int i = 0; i <= m; i++) {
        dp[i][0] = 0;
    }

    for (int j = 0; j <= n; j++) {
        dp[0][j] = 0;
    }

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (x[i-1] == y[j-1]) {
                dp[i][j] = dp[i-1][j-1] + 1;//Add diagonal element
            } else {
                dp[i][j] = max(dp[i][j-1], dp[i-1][j]); //Add maximum value
            }
        }
    }

    string res = "";
    int i = m;// Assigen Last position
    int j = n; 
    
    while (i > 0 && j > 0) {
        if (x[i-1] == y[j-1]) {
            res = x[i-1] + res; // Add last character
            i--;
            j--;
        } else if (dp[i-1][j] >= dp[i][j-1]) {
            i--; //Up shift
        } else {
            j--; //Left Shift
        }
    }

    return res;
}

int main()
{
    cout<<"Enter Two string:";
    string text1, text2;
    cin >> text1 >> text2;
    
    string answer = LCS(text1, text2);
    cout << "LCS is: " << answer;
    return 0;
}

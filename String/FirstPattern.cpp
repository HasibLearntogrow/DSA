#include <iostream>
#include <string>
using namespace std;
int patternMatching(string P,string T) {
    int R = P.length();
    int S = T.length();
    int MAX = S - R + 1;

    for (int K = 0; K < MAX; ++K) {
        int L;
        for (L = 0; L < R; ++L) {
            if (P[L] != T[K + L]) {
                break;
            }
        }
        if (L == R) {
            return K; 
        }
    }

    return -1; 
}

int main() {
    string T = "ABABDABACDABABCABAB";
    string P = "ABABCABAB";

    int index = patternMatching(P, T);

    if (index != -1) {
        cout << "Pattern found at index: " << index << std::endl;
    } else {
        cout << "Pattern not found." << std::endl;
    }

    return 0;
}
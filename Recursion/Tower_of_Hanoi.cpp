#include <iostream>
using namespace std;

int moveCounter = 0;

void Hanoi(int n, int A, int B, int C) {
    if (n == 1) {
        cout << "Disk Shift: " << A << " TO " << C << endl;
        moveCounter++;
        return;
    }
    
    Hanoi(n - 1, A, C, B);
    cout << "Disk Shift: " << A << " TO " << C << endl;
    moveCounter++;
    Hanoi(n - 1, B, A, C);
}

int main() {
    int n;
    cout << "Enter the number of disks: ";
    cin >> n;
    
    Hanoi(n, 1, 2, 3);
    cout << "Total Shifts: " << moveCounter << endl;
    
    return 0;
}

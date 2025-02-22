#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

struct Point {
    int x, y;
};

// Compare function to sort points
bool comparePoints(Point p1, Point p2) {
    if (p1.x == p2.x) return p1.y < p2.y;
    return p1.x < p2.x;
}

// Cross product to determine the turn direction
int cross(Point O, Point A, Point B) {
    return (A.x - O.x) * (B.y - O.y) - (A.y - O.y) * (B.x - O.x);
}


vector<Point> grahamScan(vector<Point> points) {
    
    sort(points.begin(), points.end(), comparePoints);

    stack<Point> hull;

    for (Point p : points) {
        
        while (hull.size() >= 2) {
            Point top = hull.top();
            hull.pop();
            if (cross(hull.top(), top, p) <= 0) {
                hull.push(top);  
                break;
            }
        }
        hull.push(p);  
    }

    vector<Point> result;
    while (!hull.empty()) {
        result.push_back(hull.top());
        hull.pop();
    }

    reverse(result.begin(), result.end());  // Reverse the result to get the correct order
    return result;
}

// Function to print the convex hull
void printHull(vector<Point> hull) {
    cout << "Convex Hull: ";
    for (Point p : hull) {
        cout << "(" << p.x << ", " << p.y << ") ";
    }
    cout << endl;
}

int main() {

    vector<Point> points = {{0, 0}, {2, 2},{1, 1},{2, 0}, {1,-1}};

    
    vector<Point> hull = grahamScan(points);

    
    printHull(hull);

    return 0;
}

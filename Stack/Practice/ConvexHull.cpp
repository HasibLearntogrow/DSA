#include <bits/stdc++.h>
using namespace std;

// Structure to represent a point
struct Point {
    int x, y;
};

// Function to find the orientation of an ordered triplet (p, q, r)
// Returns:
// 0 -> collinear
// 1 -> clockwise
// 2 -> counterclockwise
int orientation(Point p, Point q, Point r) {
    int val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);
    if (val == 0) return 0; // collinear
    return (val > 0) ? 1 : 2; // clockwise or counterclockwise
}

// Comparison function to sort points based on polar angle
Point p0; // Reference point
bool compare(Point p1, Point p2) {
    int o = orientation(p0, p1, p2);
    if (o == 0) // If collinear, sort by distance from p0
        return (p1.x - p0.x) * (p1.x - p0.x) + (p1.y - p0.y) * (p1.y - p0.y) <
               (p2.x - p0.x) * (p2.x - p0.x) + (p2.y - p0.y) * (p2.y - p0.y);
    return (o == 2);
}

// Graham scan algorithm
void convexHull(vector<Point>& points) {
    int n = points.size();
    if (n < 3) {
        cout << "Convex hull not possible\n";
        return;
    }

    // Find the bottom-most point (or left-most in case of tie)
    int minY = 0;
    for (int i = 1; i < n; i++)
        if (points[i].y < points[minY].y || (points[i].y == points[minY].y && points[i].x < points[minY].x))
            minY = i;

    // Place the bottom-most point at first position
    swap(points[0], points[minY]);
    p0 = points[0];

    // Sort points based on polar angle with respect to p0
    sort(points.begin() + 1, points.end(), compare);

    // Create an empty stack and push first three points
    stack<Point> hull;
    hull.push(points[0]);
    hull.push(points[1]);
    hull.push(points[2]);

    // Process remaining points
    for (int i = 3; i < n; i++) {
        while (hull.size() > 1) {
            Point top = hull.top();
            hull.pop();
            Point secondTop = hull.top();

            if (orientation(secondTop, top, points[i]) == 2) {
                hull.push(top);
                break;
            }
        }
        hull.push(points[i]);
    }

    // Print the convex hull
    cout << "Convex Hull:\n";
    while (!hull.empty()) {
        Point p = hull.top();
        cout << "(" << p.x << ", " << p.y << ")\n";
        hull.pop();
    }
}

// Driver code
int main() {
    vector<Point> points = {
        {0, 0}, {1, 1}, {2, 2}, {3, 3},
        {4, 4}, {5, 5}, {6, 1}, {7, 2}
    };

    convexHull(points);
    return 0;
}

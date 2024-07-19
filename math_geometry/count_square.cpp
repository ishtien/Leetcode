#include <iostream>
#include <vector>
#include <unordered_map>
#include <cmath> // For abs

using namespace std;

class CountSquares {
public:
    vector<vector<int>> points;
    unordered_map<long, int> ptsCount;

    CountSquares() {}

    long getKey(int x, int y) {
        return (static_cast<long>(x) << 32) | static_cast<long>(y);
    }

    void add(vector<int> point) {
        ptsCount[getKey(point[0], point[1])]++;
        points.push_back(point);
    }

    int count(vector<int> point) {
        int px = point[0];
        int py = point[1];
        int res = 0;
        for (auto &pts : points) {
            if (abs(px - pts[0]) != abs(py - pts[1]) || px == pts[0] || py == pts[1]) continue;
            res += ptsCount[getKey(pts[0], py)] * ptsCount[getKey(px, pts[1])];
        }
        return res;    
    }
};

int main() {
    // Create an instance of CountSquares
    CountSquares cs;

    // Add points
    cs.add({1, 1});
    cs.add({1, 3});
    cs.add({3, 1});
    cs.add({3, 3});
    
    // Count the number of squares that can be formed with the point (1, 1)
    cout << "Count of squares with (1, 1): " << cs.count({1, 1}) << endl;

    // Add more points
    cs.add({2, 2});
    cs.add({2, 4});
    cs.add({4, 2});
    cs.add({4, 4});

    // Count the number of squares that can be formed with the point (2, 2)
    cout << "Count of squares with (2, 2): " << cs.count({2, 2}) << endl;

    // Add some more points
    cs.add({5, 5});
    cs.add({6, 6});
    cs.add({5, 6});
    cs.add({6, 5});

    // Count the number of squares that can be formed with the point (5, 5)
    cout << "Count of squares with (5, 5): " << cs.count({5, 5}) << endl;

    // Count the number of squares that can be formed with the point (6, 6)
    cout << "Count of squares with (6, 6): " << cs.count({6, 6}) << endl;

    return 0;
}

#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;

// Define the compare struct for the priority_queue
struct compare {
    bool operator()(const pair<vector<int>, int> &a, const pair<vector<int>, int> &b) {
        return a.second > b.second;
    }
};

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> res;
        priority_queue<pair<vector<int>, int>, vector<pair<vector<int>, int>>, compare> pq;
        
        // Push each point with its squared distance into the priority queue
        for(int i = 0; i < points.size(); i++) {
            int dist = pow(points[i][0], 2) + pow(points[i][1], 2); // Calculate squared distance
            pq.push({points[i], dist});
        }
        
        // Extract k closest points from the priority queue
        while(!pq.empty() && k > 0) {
            auto top = pq.top();
            pq.pop();
            res.push_back(top.first); // Store the point (first element of pair) into result
            k--;
        }
        
        return res;
    }
};

int main() {
    // Test the kClosest function
    Solution sol;

    // Example points
    vector<vector<int>> points = {{1, 3}, {-2, 2}, {5, 8}, {0, 1}};
    int k = 2;

    // Call kClosest function
    vector<vector<int>> closestPoints = sol.kClosest(points, k);

    // Output the results
    cout << "The " << k << " closest points are:" << endl;
    for (const auto& point : closestPoints) {
        cout << "(" << point[0] << ", " << point[1] << ")" << endl;
    }

    return 0;
}

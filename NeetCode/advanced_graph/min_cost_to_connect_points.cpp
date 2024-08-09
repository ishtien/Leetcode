#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <cmath>
using namespace std;

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        unordered_map<int, vector<pair<int, int>>> graph; // A node, {dist, B node}
        for (int i = 0; i < points.size(); i++) {
            for (int j = i + 1; j < points.size(); j++) {
                int dist = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
                graph[i].push_back({dist, j});
                graph[j].push_back({dist, i});
            }
        }
        
        int res = 0;
        unordered_set<int> visited;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minH;
        minH.push({0, 0});
        
        while (visited.size() < points.size()) {
            auto top = minH.top();
            int value = top.first;
            int cur = top.second;
            minH.pop();
            
            if (visited.count(cur)) continue;
            res += value;
            visited.insert(cur);
            
            for (auto &n : graph[cur]) {
                if (visited.count(n.second) == 0) {
                    minH.push(n);
                }
            }
        }
        
        return res;
    }
};

int main() {
    Solution sol;
    
    // Example 1
    vector<vector<int>> points1 = {{0, 0}, {2, 2}, {3, 10}, {5, 2}, {7, 0}};
    cout << "Minimum Cost to Connect Points (Example 1): " << sol.minCostConnectPoints(points1) << endl;
    
    // Example 2
    vector<vector<int>> points2 = {{0, 0}, {1, 1}, {1, 0}, {-1, 1}};
    cout << "Minimum Cost to Connect Points (Example 2): " << sol.minCostConnectPoints(points2) << endl;
    
    return 0;
}

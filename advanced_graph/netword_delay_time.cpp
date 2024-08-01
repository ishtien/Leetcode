#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
using namespace std;

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map<int, vector<pair<int, int>>> graph; // node, {time, neighbor}
        
        // Build the graph from the edge list
        for (auto &time : times) { // {source, target, time}
            int src = time[0];
            int target = time[1];
            int value = time[2];
            graph[src].push_back({value, target});
        }
        
        // Min-heap priority queue for Dijkstra's algorithm
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minH;
        minH.push({0, k}); // Start from node k with 0 delay
        
        int res = 0;
        unordered_set<int> visit;
        
        while (!minH.empty()) {
            auto top = minH.top();
            int to = top.second;
            int value = top.first;
            minH.pop();
            
            if (visit.count(to)) continue;
            visit.insert(to);
            
            for (auto &n : graph[to]) {
                int node = n.second;
                int weight = n.first;
                if (!visit.count(node)) {
                    minH.push({value + weight, node});
                }
            }
            
            res = value;
        }
        
        return (visit.size() == n) ? res : -1; // Check if all nodes are visited
    }
};

int main() {
    Solution sol;
    
    // Example 1
    vector<vector<int>> times1 = {
        {2, 1, 1},
        {2, 3, 1},
        {3, 4, 1}
    };
    int n1 = 4; // Number of nodes
    int k1 = 2; // Starting node
    cout << "Network Delay Time (Example 1): " << sol.networkDelayTime(times1, n1, k1) << endl;
    
    // Example 2
    vector<vector<int>> times2 = {
        {1, 2, 1},
        {2, 3, 2},
        {1, 3, 4}
    };
    int n2 = 3; // Number of nodes
    int k2 = 1; // Starting node
    cout << "Network Delay Time (Example 2): " << sol.networkDelayTime(times2, n2, k2) << endl;
    
    return 0;
}

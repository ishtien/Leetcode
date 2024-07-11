#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int sz = edges.size(); // n nodes = n edges
        vector<int>parent(sz + 1);
        vector<int>rank(sz + 1, 1);
        vector<vector<int>> res;
        for(int i = 1; i < sz + 1; i ++) {
            parent[i] = i;
        }
        for(auto &pair : edges) {
            unionNodes(pair[0], pair[1], parent, rank, res);
        }
        return res[res.size()-1];
    }
    int find(int node, vector<int>& parent) {
        int p;
        if(parent[node] != node) {
            p = find(parent[node], parent);
        } else {
            p= node;
        }
        return p;
    }
    bool unionNodes(int a, int b, vector<int>& parent, vector<int> & rank, vector<vector<int>>& res) {
        int parentA = find(a, parent);
        int parentB = find(b, parent);
        if(parentA == parentB) {
            res.push_back({a, b});
            return false;
        } else {
            if(rank[parentA] >= rank[parentB]) {
                parent[parentB] = parentA;
                rank[parentA] += rank[parentB];
            } else {
                parent[parentA] = parentB;
                rank[parentB] += rank[parentA];
            }
        }
        return true;
    }
};


int main() {
    Solution sol;

    // Example usage
    //vector<vector<int>> edges = {{1, 2}, {2, 3}, {3, 4}, {1, 4}, {1, 5}};
    vector<vector<int>> edges = {{3,4}, {1, 2}, {2, 4}, {3, 5}, {2, 5}};
    //edges=[[1,2],[2,3],[2,4],[4,5],[1,5]]
    //[[1,4],[3,4],[1,3],[1,2],[4,5]]
    //[3,4],[1,2],[2,4],[3,5],[2,5]

    vector<int> redundantEdge = sol.findRedundantConnection(edges);

    if (redundantEdge.empty()) {
        cout << "No redundant edge found." << endl;
    } else {
        cout << "Redundant edge found: " << redundantEdge[0] << " -> " << redundantEdge[1] << endl;
    }

    return 0;
}

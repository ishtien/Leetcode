#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class SolutionModify {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<int> parent(n);
        vector<int> rank(n);
        int res = n;
        for(int i = 0; i < n; i++) {
            parent[i] = i;
            rank[i] = 1;
        }
        for(auto &pair : edges) {
            int u = unionNode(pair[0], pair[1], parent, rank);
            res -= u;
        }
        return res;
       
    }
    int find(int node, vector<int> & parent) {
        int p;
        if(parent[node] != node) p = find(parent[node], parent);
        else p = node;
        return p;
    }
    int unionNode(int a, int b, vector<int>& parent, vector<int>& rank) {
        if(a==b) return 0;
        int parent_a = find(a, parent);
        int parent_b = find(b, parent);
        if(parent_a == parent_b) return 0; 
        else{
            if(rank[parent_a] >= rank[parent_b]) {
                parent[parent_b] = parent_a;
                rank[parent_a] += rank[parent_b];
            } else {
                parent[parent_a] = parent_b;
                rank[parent_b] += rank[parent_a];
            }
        }
        return 1;
    }
};

class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n);
        for(auto &node : edges) {
            graph[node[0]].push_back(node[1]);
            graph[node[1]].push_back(node[0]);
        }
        unordered_set<int> visited;
        int count = 0;
        for(int i = 0; i < n; i++) {
            if(!visited.count(i)) {
                count++;
                dfs(i, graph, visited);
            }
        }
        return count;
    }
    void dfs(int node, vector<vector<int>>& graph, unordered_set<int>& visited) {
        if(visited.count(node)) return;
        visited.insert(node);
        for(auto & n: graph[node]) {
            dfs(n, graph, visited);
        } 
        return;
    }
};


int main() {
    Solution sol;
    SolutionModify sol2;

    // Example usage
    int n = 5;
    vector<vector<int>> edges = {{0, 1}, {1, 2}, {3, 4}};
    
    int numComponents = sol.countComponents(n, edges);
    int numComponents2 = sol2.countComponents(n, edges);

    cout << "Number of connected components (DFS): " << numComponents << endl;
    cout << "Number of connected components (Union): " << numComponents2 << endl;

    return 0;
}

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;
class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n);
        for(auto & node: edges) {
            graph[node[0]].push_back(node[1]);
            graph[node[1]].push_back(node[0]);
        }
        unordered_set<int> visited;

        return dfs(0, -1, graph, visited) && ((visited.size()==n)?true:false);
    }
    bool dfs(int cur, int prev, vector<vector<int>> &graph, unordered_set<int> &visited){
        if(visited.count(cur)) return false;
        
        visited.insert(cur);
        for(auto & node: graph[cur]) {
            if(node == prev) continue;
            if(!dfs(node, cur, graph, visited)) return false;
        }
        return true;

    }
};

int main() {
    Solution sol;
    
    int n = 5;
    vector<vector<int>> edges = {{0, 1}, {0, 2}, {0, 3}, {1, 4}};
    
    bool isTree = sol.validTree(n, edges);
    
    if (isTree) {
        cout << "The graph with " << n << " nodes and given edges forms a valid tree." << endl;
    } else {
        cout << "The graph with " << n << " nodes and given edges does not form a valid tree." << endl;
    }
    
    return 0;
}
